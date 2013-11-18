hello-github
============

![alt tag](https://raw.github.com/luke-ho/hello-github/master/img/hello_github.png)

Compiling
============

###Compiling C, C++, and Java examples

    make

###Compiling just the C example

    make c

###Compiling just the C++ example

    make cpp

###Compiling just the Java example

    make java

If your compiler is located in a different directory, update the CPP_BIN, C_BIN, or JAVA_BIN in the Makefile respectively.

Running 
============

###Compiled languages (C, C++, Java)

Go to the bin directory and run the respective commands to run the application.

    ./hello_c
    ./hello_cpp
    java hello

###Interpreted languages

Run the respective interpreter with the language.

    python hello.py
    ruby hello.rb

![mindblown](https://raw.github.com/luke-ho/hello-github/master/img/mind_blown.gif) 

(Special thanks to [imgur] (http://i.imgur.com/sg017lt.gif))

Testing
============

Go to the test directory and run:

    python test.py

If all goes well, it will run all of the binaries and scripts and tell you which tests passed or failed. 
    

License
============

This project is under the MIT license. See [LICENSE] (https://raw.github.com/luke-ho/hello-github/master/LICENSE) for more details.
