cd ~/week04/
gcc ex3.c -o ex3
./ex3 3 &
pstree $$
sleep 5
pstree $$
sleep 5
pstree $$
./ex3 5 &
pstree $$
sleep 5
pstree $$
sleep 5
pstree $$
sleep 5
pstree $$
sleep 5
pstree $$
