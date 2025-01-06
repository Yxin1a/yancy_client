#!/bin/bash

PREFIX_DIR=$1
# cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$PREFIX_DIR
cmake .. -DCMAKE_INSTALL_PREFIX=$PREFIX_DIR

make -j8 && make install
