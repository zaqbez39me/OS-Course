mkdir ~/week01/root/
date
sleep 3
touch ~/week01/root/root.txt
date
sleep 3
mkdir ~/week01/home/
date
sleep 3
touch ~/week01/home/home.txt
ls -t -r / > ~/week01/root/root.txt
ls -t -r ~ > ~/week01/home/home.txt
cat ~/week01/root/root.txt
cat ~/week01/home/home.txt
ls ~/week01/root/
ls ~/week01/home/
