# Arraraya

A simple reverse proxy web server builded to test and understand
the concepts or technologies like:

 - Blue Green deploment
 - Canary deployment
 - Live Config Reloading
 - Autotools
 - C
 - Posix Prefork servers
 - Draining connections
 - (Client) service discovery
 - Packagin
 - and HTTP

## Deps

I didn't want to write the HTTP parser so for now `picohttpparser` is a dependency

## Building

```
$ autoreconf -iv
$ mkdir build && cd $_
$ ../configure
$ make
$ make install
```

## Running

```
$ atarraya
```
