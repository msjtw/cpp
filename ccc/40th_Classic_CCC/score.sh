#!/bin/bash

test_n=5

g++ "level$1.cpp" -o "../../zz_exe/level$1"

if [[ ! -d "inputs/level$1" ]]; then
    mkdir "inputs/level$1"
    for (( c=1; c<=$test_n; c++ )); do 
       find ~/Downloads -name "level$1_$c.in" -exec  mv {} inputs/level$1/level$1_$c.in \; 
    done
fi

rm -r "outputs/level$1" 2> /dev/null
mkdir "outputs/level$1"

for (( i=1; i<=$test_n; i++ )); do
    ../../zz_exe/level$1 < "inputs/level$1/level$1_$i.in" > "outputs/level$1/level$1_$i.out"
done
