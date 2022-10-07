#!/bin/bash
if [ $# -ne 1 ]
then
	echo "How to use: ./randScript.sh <number>"
	exit
fi
truncate -s 0 rand.txt
for (( c=0; c < $1; ++c ))
do
	echo $(( $RANDOM % 5000)) >> rand.txt
done
