FROM ubuntu:14.04

RUN apt-get -yqq update
RUN apt-get -yqq install build-essential
RUN apt-get -yqq install curl
RUN apt-get -yqq install default-jdk
RUN apt-get -yqq install make
RUN apt-get -yqq install git
RUN apt-get -yqq install ruby
RUN apt-get -yqq install tcl

ADD hello-github-app /opt/hello-github-app
WORKDIR /opt/hello-github-app

CMD [ "bash" , "run.sh" ]
