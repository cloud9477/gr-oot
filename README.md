# gr-oot
GNU Radio Test and Out-of-Tree Example

Introduction
=================
This repository is for the Wireless Communication Lab of UConn ECE department.

Version
=================
This version supports both Ubuntu 20.04 and Ubuntu 22.04 with GR 3.10.
For GR 3.9, please check maint-3.9 branch.

Installation
=================
- First clone the repository.
```
$ cd
$ cd sdr/
$ git clone https://github.com/cloud9477/gr-oot.git
$ cd gr-oot/
```
- The main track is for GNU Radio 3.10, if you are using 3.9, please switch the branch like following.
```
$ git checkout maint-3.9
```

- Next, build a folder to keep the building files, build and install the code.
```
$ mkdir build
$ cd build/
$ cmake ../
$ make
$ sudo make install
$ sudo ldconfig
```

The Lab Manual
=================
- The lab manual guides you to install and use the GNU Radio for first time. It also introduces how to create your own GNU Radio Out-Of-Tree block. Please use it together with this repository.
