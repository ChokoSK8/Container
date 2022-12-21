#!/bin/bash
FILE="Executables/$1"
if [ -f "$FILE" ]
then
DIFF=$(diff <(date -r Executables/$1) <(date -r $2/$1))
if [ -z "$DIFF" ]
then
exit
fi
fi
echo -e "\t\e[1;37mCOPING $1 IN CURRENT DIRECTORY\e[0m"
cp $2/$1 Executables
