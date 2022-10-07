#!/bin/bash
awk 'FNR < 93' cmp.cpp > f1 ; awk 'FNR > 92' "main.cpp" > f2 ; cat f1 > cmp.cpp ; cat f2 >> cmp.cpp
