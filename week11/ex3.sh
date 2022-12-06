# shellcheck disable=SC2012
touch _ex3.txt
printf "Kirill" > _ex3.txt
chmod -R -x _ex3.txt
ls -l _ex3.txt | cut -d " " -f1 > ex3.txt
chmod u+rwx,o+rwx _ex3.txt
ls -l _ex3.txt | cut -d " " -f1 >> ex3.txt
chmod g=u _ex3.txt
ls -l _ex3.txt | cut -d " " -f1 >> ex3.txt
printf "660 means that owner and group can read and write. Other cannot do anything.
775 means that owner and group have all permissions. Other can read and execute.
777 means that all users have all permissions." >> ex3.txt