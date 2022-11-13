# shellcheck disable=SC2012
cd ~/week11/ || mkdir ~/week11/ && cd ~/week11/
touch ~/week01/file.txt
printf "Kirill" > ~/week01/file.txt
rm -f _ex2.txt
link ~/week01/file.txt _ex2.txt > ex2.txt
find ~/ -inum $(ls -i "_ex2.txt" | cut -d " " -f1) >> ex2.txt
find . -inum $(ls -i "$HOME/week01/file.txt" | cut -d " " -f1) -exec rm {} \; >> ex2.txt