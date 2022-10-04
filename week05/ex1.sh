cd ~/week05/ || exit

gcc publisher.c -o publisher
gcc subscriber.c -o subscriber

gnome-terminal -- ./publisher $1

for (( i = 0; i < $1; ++i))
do
gnome-terminal -- "./subscriber"
done