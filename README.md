# OSFromScratch

command:
dd if=/dev/zero of=disk.img count=204800 bs=512
fdisk disk.img(n....default option...w)
sudo losetup -o 1048576 /dev/loop1 disk.img
sudo mkfs.ext3 /dev/loop1
mount /dev/loop1 /mnt
sudo grub-install --boot-directory=/mnt --modules="part_msdos" disk.img
make
sudo cp kernel /mnt/
sync
qemu-system-x86_64 -hda disk.img -s
