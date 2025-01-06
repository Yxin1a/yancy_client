#!/bin/bash

ORIGIN_DIR=$PWD
CONFIG_SHELL="build.sh"
PLATFORM=$(uname -m)
PREFIX_DIR=$PWD/../release/$PLATFORM

# 1. 创建临时构建目录
mkdir -p $PWD/cJSON/do_build
mkdir -p $PWD/libhv_new/do_build

# 4. 编译函数：编译使用 cmake 的开源项目
function compile_opensource_cmake(){
	opensource_name=$1
	echo "Starting compiling $opensource_name"
if [ -d $ORIGIN_DIR/$opensource_name/do_build ]; then
	cd $ORIGIN_DIR/$opensource_name/do_build && rm -fr *
	cp ../$CONFIG_SHELL .
	./$CONFIG_SHELL $PREFIX_DIR
else
	echo -e "No $opensource_name"
fi
	echo "Compile the $opensource_name end"
}

# 2. 编译 cJSON 库
compile_opensource_cmake "cJSON"

# 3. 编译 libhv_new 库
compile_opensource_cmake "libhv_new"



