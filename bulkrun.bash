#!/bin/bash
echo "n,time_class[ms],time_adap[ms],classic_d,adaptive_d"

for i in {1..20}
do
    filename="TheIdiot${i}.txt"
    output=$(./main inputs/TheIdiot.txt "inputs/$filename")
    echo "$i,$output"
done
