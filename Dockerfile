FROM zachdeibert/autotools

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y mingw-w64
RUN apt-get install -y libpthread-stubs0-dev
RUN apt-get install -y cmake

WORKDIR /app
CMD /bin/bash compile.sh
