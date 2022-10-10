#!/bin/bash
awk 'FNR < 94' Helpers/cmp.cpp > Helpers/f1 ; awk 'FNR > 93' "main.cpp" > Helpers/f2 ; cat Helpers/f1 > Helpers/cmp.cpp ; cat Helpers/f2 >> Helpers/cmp.cpp
