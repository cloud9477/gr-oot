#!/bin/bash

echo "analog pluto installation start for ubuntu 22.04"
echo "install dependency"
sudo apt-get -y install libxml2 libxml2-dev bison flex cmake git libaio-dev libboost-all-dev
sudo apt-get -y install doxygen
sudo apt-get -y install libusb-1.0-0-dev
sudo apt-get -y install libavahi-common-dev libavahi-client-dev

echo "install analog device driver"
cd
[ ! -d "./sdr/" ] && echo "sdr directory does not exist, build sdr folder."
cd ./sdr/

echo "install lib iio"
git clone https://github.com/analogdevicesinc/libiio.git
cd libiio
mkdir build
cd build
cmake ../
make
sudo make install
cd ../../

echo "install lib ad9361-iio"
git clone https://github.com/analogdevicesinc/libad9361-iio.git
cd libad9361-iio
mkdir build
cd build
cmake ../
make
sudo make install
cd ../../

sudo apt-get -y install bison flex cmake git libgmp-dev swig

echo "getting pluto info"
iio_info -s


