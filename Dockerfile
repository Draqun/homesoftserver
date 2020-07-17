FROM zachdeibert/autotools

RUN apt-get update
RUN apt-get install -y mingw-w64
RUN apt-get install -y libpthread-stubs0-dev
RUN apt-get install -y libmicrohttpd-dev

WORKDIR /app
CMD /bin/bash compile.sh
