FROM emscripten/emsdk

ENV CMAKE_SYSTEM_NAME=emscripten
ENV EMSCRIPTEN_ROOT_PATH=/emsdk/upstream/emscripten/

RUN apt-get update
RUN apt-get install -y ninja-build


COPY . /app
WORKDIR /app

CMD bash build/build-emscripten.sh
