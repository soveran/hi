#!/bin/sh

assert_equal () {
	cmp $1 $2 || printf "F: \"%s\" != \"%s\"\n" $1 $2
}

< ./test/sample.in ./hi ba > ./test/sample.out

assert_equal ./test/sample.out ./test/sample.ref
