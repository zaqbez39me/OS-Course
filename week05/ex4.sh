cd ... || ~/week05/
gcc ex4.c -o ex4

printf "For m = 1:" > ex4.txt
(time ./ex4 10000000 1) 2>> ex4.txt
printf "For m = 2:" >> ex4.txt
(time ./ex4 10000000 2) 2>> ex4.txt
printf "For m = 4:" >> ex4.txt
(time ./ex4 10000000 4) 2>> ex4.txt
printf "For m = 10:" >> ex4.txt
(time ./ex4 10000000 10) 2>> ex4.txt
printf "For m = 100:" >> ex4.txt
(time ./ex4 10000000 100) 2>> ex4.txt

./ex2