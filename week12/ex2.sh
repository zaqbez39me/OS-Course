# shellcheck disable=SC2016
cd ~/week12/ || exit
sh ~/week12/ex1.sh
sudo sh -c 'echo "Kirill" > lofsdisk/file1'
sudo sh -c 'echo "Korolev" > lofsdisk/file2'
sudo mkdir -p lofsdisk/bin
sudo mkdir -p lofsdisk/lib64
sudo mkdir -p lofsdisk/lib/x86_64-linux-gnu
sudo gcc ex2.c -o lofsdisk/ex2.out
cd lofsdisk || exit
commands=("/bin/bash" "/bin/cat" "/bin/echo" "/bin/ls" "/bin/touch")
for command in ${commands[*]}
do
  sudo cp -v "$command" $(printf ".%s" $(dirname "$command"))
  sudo ldd "$command" | grep "=> \/" | xargs -P 3 sudo sh -c 'cp -v $2 $(printf ".%s" $(dirname "$2"))'
  sudo ldd "$command" | grep "^.\/" | xargs -P 1 sudo sh -c 'cp -v $0 $(printf ".%s" $(dirname "$0"))'
done
cd ../
sudo chroot lofsdisk /ex2.out > ex2.txt
printf "\n" >> ex2.txt
lofsdisk/ex2.out >> ex2.txt