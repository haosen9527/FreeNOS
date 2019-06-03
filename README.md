Free Niek's Operating System.
Authors:

    Niek Linnenbank
    Dan Rulos (AmayaOS)
    Coen Bijlsma (libparse, srv/time)
    Ed Schouten (libteken)
    Alexander Schrijver (OpenBSD patches)

# INSTALL
+ env
``` shell
$ sudo apt-get install build-essential scons python-subversion subversion qemu
```
+ compile
``` shell
$ scons iso
```
# RUN
- install qemu
``` shell
$ sudo apt-get install qemu
```
- create img
``` shell
$ qemu-img create FreeNOS.img 5G
```
* FreeNOS.img size 5G
- Run
``` shell
$ qemu-system-x86_64 -m 512 -smp 4 -hda FreeNOS.img -cdrom FreeNOS.iso -boot dc
```
* -m分配虚拟内存，单位为MB
* -smp分配虚拟硬盘空间
* -hda指定虚拟机文件路径和文件名
* -cdrom指定ios镜像文件路径和文件名
* -boot指定从磁盘启动
