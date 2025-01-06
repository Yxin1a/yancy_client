cmake_minimum_required(VERSION 1.0)#版本
project(src_server)#项目名称

set(CMAKE_VERBOSE_MAKEFILE ON)#显示详细的make命令-O0 -ggdb
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++17 -Wall -Wno-deprecated -Wno-unused-function -Wno-builtin-macro-redefined")

include_directories(.)
include_directories(    #增加搜索头文件的路径
    /usr/local/include
    ../release/${CMAKE_SYSTEM_PROCESSOR}/include
)
link_directories(    #增加搜索库文件的路径
    /usr/local/lib
    ../release/${CMAKE_SYSTEM_PROCESSOR}/lib
)

#要编译的源码路径
set(LIB_SRC 
    IPC/ipc_server.cpp
    IPC/ipc_protocol.cpp
    )

add_library(src_server SHARED ${LIB_SRC})   #加入shared库
#add_library(yancy_static STATIC ${LIB_SRC})  #建立静态库
#SET_TARGET_PROPERTIES(yancy_static PROPERTIES OUTPUT_NAME "yancy")   #改静态库的库名

set(LIBS #要依赖的库
    src_server    #自定义共享库
    libcjson.a  #cjson库
    libhv_static.a  #hv库
    pthread 
)
    
message("***",${LIBS})   #在日志中记录指定的消息文本

#test
add_executable(test ../tests/test.cpp) #生成test测试文件(可执行文件)
add_dependencies(test src_server) #测试文件依赖 add_dependencies
target_link_libraries(test ${LIBS}) #用于指定链接给定目标和/或其依赖项时要使用的库或标志

add_executable(test_ipc_server ../tests/test_ipc_server.cpp) #生成test测试文件(可执行文件)
add_dependencies(test_ipc_server src_server) #测试文件依赖 add_dependencies
target_link_libraries(test_ipc_server ${LIBS}) #用于指定链接给定目标和/或其依赖项时要使用的库或标志

#main
add_executable(server main.cpp) #生成test测试文件(可执行文件)
add_dependencies(server src_server) #测试文件依赖 add_dependencies
target_link_libraries(server ${LIBS}) #用于指定链接给定目标和/或其依赖项时要使用的库或标志

message(STATUS "Current architecture: ${CMAKE_SYSTEM_PROCESSOR}") #打印当前系统架构

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../release/${CMAKE_SYSTEM_PROCESSOR}/bin)#输出测试文件  的路径yancy-master/bin
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)#输出库的文件路径yancy-master/lib  PROJECT_SOURCE_DIR预定义变量

