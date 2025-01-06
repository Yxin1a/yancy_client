#!/bin/bash

# 预创建文件夹
BUILD_DIR="./build"

if [ ! -d $BUILD_DIR ]; then
    mkdir $BUILD_DIR    
fi

# 编译
cd $BUILD_DIR
qmake ..
make -j4