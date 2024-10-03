FROM ubuntu:22.04
WORKDIR /usr/src/server
COPY project .
EXPOSE 7777
CMD [ "./http-server" ]
