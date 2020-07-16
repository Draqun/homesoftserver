FROM zachdeibert/autotools
WORKDIR /app


ENTRYPOINT echo $(pwd) && ls -al . && /bin/bash compile.sh