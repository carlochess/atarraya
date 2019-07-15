#include "loop.h"

int parse(int sock){

  char buf[4096], *method, *path;
  int pret, minor_version, errno;
  struct phr_header headers[100];
  size_t buflen = 0, prevbuflen = 0, method_len, path_len, num_headers;
  ssize_t rret;

  while (1) {
    /* read the request */
    while ((rret = read(sock, buf + buflen, sizeof(buf) - buflen)) == -1 && errno == EINTR)
        ;
    if (rret <= 0)
        return -1; // IOError;
    prevbuflen = buflen;
    buflen += rret;
    /* parse the request */
    num_headers = sizeof(headers) / sizeof(headers[0]);
    pret = phr_parse_request(buf, buflen, &method, &method_len, &path, &path_len,
                             &minor_version, headers, &num_headers, prevbuflen);
    if (pret > 0)
        break; /* successfully parsed the request */
    else if (pret == -1)
        return 1;// ParseError;
    /* request is incomplete, continue the loop */
    assert(pret == -2);
    if (buflen == sizeof(buf))
        return 2; // RequestIsTooLongError;
  }

  printf("request is %d bytes long\n", pret);
  printf("method is %.*s\n", (int)method_len, method);
  printf("path is %.*s\n", (int)path_len, path);
  printf("HTTP version is 1.%d\n", minor_version);
  printf("headers:\n");
  for (int i = 0; i != num_headers; ++i) {
    printf("%.*s: %.*s\n", (int)headers[i].name_len, headers[i].name,
           (int)headers[i].value_len, headers[i].value);
  }
}
