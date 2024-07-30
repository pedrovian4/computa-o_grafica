#!/usr/bin/

git clone https://github.com/glfw/glfw
cd glfw
cmake -G "Unix Makefiles"
sudo apt-get build-dep glfw3
sudo make install
