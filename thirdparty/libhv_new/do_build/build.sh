#!/bin/bash

PLATFORM=$1
PREFIX_DIR=$2
# cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$PREFIX_DIR
cmake .. -DCMAKE_INSTALL_PREFIX=$PREFIX_DIR

make -j8 && make install
echo "编译成功"
