#!/bin/bash
g++ -Wall *.cpp -o 1
./1 config.dat init.dat
if [ $? != 0 ]; then
    echo "exited with exit code $?";
fi
