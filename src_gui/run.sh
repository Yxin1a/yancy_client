#!/bin/bash

CLEANDESK_PATH=$(dirname "$(realpath "$0")")
ARCH=$(uname -p)

cd "$CLEANDESK_PATH"/../release/"$ARCH"/bin || exit 1

./src_gui