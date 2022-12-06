# shellcheck disable=SC2012
cd ~/week11/ || exit
touch _ex1.txt
printf "Kirill" > _ex1.txt
ln -f _ex1.txt _ex1_1.txt
ln -f _ex1.txt _ex1_2.txt
printf "%d\n" $(ls -i _ex1.txt | cut -d " " -f1) > ex1.txt
{ printf "%d\n" $(ls -i _ex1_1.txt | cut -d " " -f1); printf "%d\n" $(ls -i _ex1_2.txt | cut -d " " -f1); } >> ex1.txt
