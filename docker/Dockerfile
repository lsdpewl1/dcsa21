FROM ubuntu:22.04

RUN apt update
RUN apt install nginx -y

ENTRYPOINT ["nginx", "-g", "daemon off;"]
