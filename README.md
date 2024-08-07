
[操作系统：设计与实现 | 2024 春季学期 | JYY | 南京大学](https://jyywiki.cn/OS/2024/)

[实验须知](https://jyywiki.cn/OS/2024/labs/Labs.md)

[抽象计算机](https://jyywiki.cn/AbstractMachine/)

[奔走相告，VWware 真的可以免费用了 | 程序员鱼皮 | 微信公众号](https://mp.weixin.qq.com/s?__biz=MzI1NDczNTAwMA==&mid=2247561445&idx=1&sn=67f96f423f12cdb5a0160c1d63fa7b19&chksm=e9c31712deb49e04138f830af3852383f76d66bd10bb0453d17751067450fb01970a1de9f52e&mpshare=1&scene=1&srcid=0807wRviW5RI63pStET8DZuN&sharer_shareinfo=c20fee200f623d79436c4d1b9b5728a3&sharer_shareinfo_first=c20fee200f623d79436c4d1b9b5728a3#rd)

# L0

[L0 | 为计算机硬件编程](https://jyywiki.cn/OS/2024/labs/L0.md)

ENV

FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update
RUN apt-get install -y build-essential gcc-multilib qemu-system strace gdb sudo python3 libsdl2-dev libreadline-dev
RUN apt-get upgrade -y

git clone https://git.nju.edu.cn/jyy/os-workbench.git

git pull origin L0

cd kernel

注释掉Makefile里的image：git

make run

## process image

cd script && python3 processImage.py

