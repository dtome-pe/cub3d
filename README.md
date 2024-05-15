# Cub3d

A raytracing implementation in C.

## Description

This program parses a 2D map and renders a 3D world using raytracing algorithms, takes basic key handling for movement and rotation and handles basic texture management with the basic grapihc engine Minilibx. 

## Installation

Call the Makefile in the root of the repository

```bash
make
```

## Usage

```bash
./webserv

# it calls the default server at ./conf/default.conf

./webserv [configuration file]

# another configuration file specified
```
Then just access the server via curl or browser at the port specified in the "Listen" directive, and you will be served, considering that the "Root" directive points to the server root.

For example, if:

```
server {
     listen 8888;
     root .;
}

```

Doing a:
```
curl 127.0.0.1:8888
```
Will make a GET request to the root of the server, and will receive an index page or an error if no index page was found.

## Resources

This guide was really fun and easy to follow through. I highly recommend it as a first read:

[Beej's Guide To Network Programming](https://beej.us/guide/bgnet/html/split/)

Reading the HTTP RFC documents was essential for tackling the HTTP requirements of the project:

[RFC 9112 - Hypertext Transfer Protocol](https://datatracker.ietf.org/doc/html/rfc9112)

[RFC 9110 - HTTP Semantics](https://datatracker.ietf.org/doc/html/rfc9110)
