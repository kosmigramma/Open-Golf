FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive
ENV CMAKE_SYSTEM_NAME=Emscripten

RUN apt-get update
RUN apt-get install -y cmake build-essential

WORKDIR /app
CMD cmake . && make
