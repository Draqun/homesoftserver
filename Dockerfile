FROM zachdeibert/autotools
WORKDIR /app

RUN apt-get update
RUN apt-get install -y mingw-w64

CMD echo $(pwd) && ls -al . && /bin/bash compile.sh
