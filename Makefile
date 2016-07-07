all: java cpp c

CPP_BIN=/usr/bin/g++
C_BIN=/usr/bin/gcc
JAVA_BIN=/usr/bin/javac

java:
	${JAVA_BIN} -d bin hello.java

cpp:
	${CPP_BIN} -O2 -o bin/hello_cpp hello.cpp
	cd "complex/stack/cpp" && make

c:
	${C_BIN} -O2 -o bin/hello_c hello.c

clean:
	rm bin/*
	rm complex/stack/cpp/bin/*

