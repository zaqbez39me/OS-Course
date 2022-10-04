cd ~/week05/ || exit
gcc -pthread ex4.c -o ex4

printf "For m = 1:\n" > ex4.txt
/bin/time -p -a -o ex4.txt ./ex4 10000000 1
printf "For m = 2:\n" >> ex4.txt
/bin/time -p -a -o ex4.txt ./ex4 10000000 2
printf "For m = 4:\n" >> ex4.txt
/bin/time -p -a -o ex4.txt ./ex4 10000000 4
printf "For m = 10:\n" >> ex4.txt
/bin/time -p -a -o ex4.txt ./ex4 10000000 10
printf "For m = 100:\n" >> ex4.txt
/bin/time -p -a -o ex4.txt ./ex4 10000000 100