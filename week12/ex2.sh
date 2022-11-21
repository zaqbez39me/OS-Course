cd ~/week12/ || exit
sh ~/week12/ex1.sh
sudo sh -c 'echo "Kirill" > lofsdisk/file1'
sudo sh -c 'echo "Korolev" > lofsdisk/file2'
sudo mkdir -p lofsdisk/bin
sudo mkdir -p lofsdisk/lib64
sudo mkdir -p lofsdisk/lib/x86_64-linux-gnu
sudo gcc ex2.c -o lofsdisk/ex2.out
cd lofsdisk || exit
sudo cp -v /bin/bash bin/
sudo cp -v /bin/cat bin/
sudo cp -v /bin/echo bin/
sudo cp -v /bin/ls bin/
sudo cp -v /bin/touch bin/
sudo cp -v /lib/x86_64-linux-gnu/libtinfo.so.6 lib
sudo cp -v /lib/x86_64-linux-gnu/libc.so.6 lib
sudo cp -v /lib64/ld-linux-x86-64.so.2 lib64
sudo cp -v /lib/x86_64-linux-gnu/libselinux.so.1 lib
sudo cp -v /lib/x86_64-linux-gnu/libpcre2-8.so.0 lib
cd ../
sudo chroot lofsdisk /ex2.out > ex2.txt
printf "\n" >> ex2.txt
lofsdisk/ex2.out >> ex2.txt