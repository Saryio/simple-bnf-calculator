#!/bin/sh
if [ -e "calculator" ]
then
  ./calculator
else
  gcc implementation.c -o calculator -lm; ./calculator
fi