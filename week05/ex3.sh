cd ... || ~/week05/
gcc ex3.c -o ex3

printf "For m = 1:" > ex3.txt
(time ./ex3 10000000 1) 2>> ex3.txt
printf "For m = 2:" >> ex3.txt
(time ./ex3 10000000 2) 2>> ex3.txt
printf "For m = 4:" >> ex3.txt
(time ./ex3 10000000 4) 2>> ex3.txt
printf "For m = 10:" >> ex3.txt
(time ./ex3 10000000 10) 2>> ex3.txt
printf "For m = 100:" >> ex3.txt
(time ./ex3 10000000 100) 2>> ex3.txt

./ex2