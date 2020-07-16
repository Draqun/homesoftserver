FROM zachdeibert/autotools
WORKDIR /app

RUN apt-get update
RUN apt-get install -y mingw-w64
RUN apt-get install -y libpthread-stubs0-dev

CMD /bin/bash compile.sh
