cd ~/week05/ || exit
gcc ex3.c -o ex3

printf "For m = 1:\n" > ex3.txt
/bin/time -p -a -o ex3.txt ./ex3 10000000 1
printf "For m = 2:\n" >> ex3.txt
/bin/time -p -a -o ex3.txt ./ex3 10000000 2
printf "For m = 4:\n" >> ex3.txt
/bin/time -p -a -o ex3.txt ./ex3 10000000 4
printf "For m = 10:\n" >> ex3.txt
/bin/time -p -a -o ex3.txt ./ex3 10000000 10
printf "For m = 100:\n" >> ex3.txt
/bin/time -p -a -o ex3.txt ./ex3 10000000 100