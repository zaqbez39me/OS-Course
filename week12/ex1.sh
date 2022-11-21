cd ~/week12/ || exit
rm -f lofs.img
dd if=/dev/zero of=lofs.img bs=1024 count=51200
/sbin/mkfs lofs.img
mkdir -p lofsdisk
P=$(sudo losetup -f)
sudo mount -o loop="$P" lofs.img lofsdisk
