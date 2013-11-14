#!/usr/bin/python

import os
import re
import commands

successRE = re.compile("Hello, GitHub!")

testsPassed = 0

# Add more tests here
tests = [
		 "bin/hello_c",
		 "bin/hello_cpp",
		 "java -cp bin hello",
		 "python hello.py",
		 "ruby hello.rb",
		 "perl hello.pl",
		 "sh hello.sh",
		 "expect hello.tcl"
		]

def run_test(test):
	global testsPassed
	output = commands.getoutput(test)
	output.rstrip()
	if len(output) > 0 and successRE.match(output) != None:
		testsPassed += 1
	else:
		print "\"{0}\" failed({1}).  Number of tests executed: {2}".format(test, output, testsPassed)
		exit(1)

if __name__ == '__main__':
	# Change directory to previous directory where scripts are located
	os.chdir ("..")

	# Run the tests
	for test in tests:
		run_test(test)

	# Print out the result
	print "{0} total tests ran ".format(testsPassed)
	print "All tests passed!"
