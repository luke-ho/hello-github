#!/bin/bash

git clone https://github.com/luke-ho/hello-github.git
curl -o go1.6.2.linux-amd64.tar.gz https://storage.googleapis.com/golang/go1.6.2.linux-amd64.tar.gz
tar -xf go1.6.2.linux-amd64.tar.gz
export GOROOT=/opt/hello-github-app/go
export PATH=$PATH:/usr/sbin:$GOROOT/bin
cd hello-github
make
cd test
python test.py
