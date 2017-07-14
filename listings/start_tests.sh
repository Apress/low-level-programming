#!/bin/bash
TESTDIR=tests

rm -rf "$TESTDIR"
mkdir tests
for testprog in `cat tests_asm` 
do
    mkdir "$TESTDIR/$testprog"
    cp "$testprog" "$TESTDIR/$testprog/$testprog"
    nasm "$testprog" -felf64 -o "$TESTDIR/$testprog/$testprog.o" && ld "$TESTDIR/$testprog/$testprog.o" -o "$TESTDIR/$testprog/$testprog"
    chmod u+x "$TESTDIR/$testprog/$testprog"
    "./$TESTDIR/$testprog/$testprog"
    echo "> $testprog Terminated with code" $?
done
