#!/bin/sh
if [ -e "calculator" ]
then
  ./calculator
else
  gcc -lm implementation.c -o calculator; ./calculator
fi