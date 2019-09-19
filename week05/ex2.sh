#!/bin/sh
#Problem is that scripts in background and foreground
# prints same number 
if [ ! -f test.txt ]
then
    touch test.txt
    max=10
    for i in `seq 1 $max`
    do
      echo "$i" >> test.txt
    done
fi
tmp=`tail -1 test.txt`
tmp=$((tmp+1))
echo "$tmp" >> test.txt
