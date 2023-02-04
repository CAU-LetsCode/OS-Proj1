# OS-Proj1
## CSC 4100 Project 1

### Introduction
You will build a stage 1 boot loader and a stage 2 operating system (OS). This initial boot loader has already been written; You simply need to download it, compile it, and install it. It will boot from a (virtual) floppy and put the computer into protected mode. It then will load the seconds stage OS. The second stage OS will clear the screen, draw a border around the screen, and then call a function written by the professor that tests his memory allocator code (also written by the professor). Next, it will again clear the screen, and fill the entire screen with stars (the '*' characters). 

![1](https://github.com/CAU-LetsCode/OS-Proj1/Figure2.png)

## Build Setup

```bash
# install dependencies
$ make

# make install
$ make install

# make run
$ make run

# to clean up 
$ make clean
```