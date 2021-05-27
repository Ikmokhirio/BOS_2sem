#!/bin/bash

gcc -Wall ./2_4.c -o ./2_4
./2_4 $1 &
ps faxu
