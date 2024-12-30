# CMake generated Testfile for 
# Source directory: /home/tq/桌面/net_wipe_network/net_wipe/thirdparty/cJSON
# Build directory: /home/tq/桌面/net_wipe_network/net_wipe/thirdparty/cJSON/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cJSON_test "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/cJSON/build/cJSON_test")
set_tests_properties(cJSON_test PROPERTIES  _BACKTRACE_TRIPLES "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/cJSON/CMakeLists.txt;252;add_test;/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/cJSON/CMakeLists.txt;0;")
subdirs("tests")
subdirs("fuzzing")
