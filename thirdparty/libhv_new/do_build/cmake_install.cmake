# Install script for directory: /home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/tq/桌面/net_wipe_network/net_wipe/release/x86_64/kylinV10")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/do_build/lib/libhv_static.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/do_build/libhv.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/hv" TYPE FILE FILES
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/hv.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/hconfig.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/hexport.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/base/hplatform.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/base/hdef.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/base/hatomic.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/base/herr.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/base/htime.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/base/hmath.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/base/hbase.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/base/hversion.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/base/hsysinfo.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/base/hproc.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/base/hthread.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/base/hmutex.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/base/hsocket.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/base/hlog.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/base/hbuf.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/base/hmain.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/base/hendian.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/ssl/hssl.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/event/hloop.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/event/nlog.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/util/base64.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/util/md5.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/util/sha1.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/cpputil/hmap.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/cpputil/hstring.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/cpputil/hfile.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/cpputil/hpath.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/cpputil/hdir.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/cpputil/hurl.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/cpputil/hscope.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/cpputil/hthreadpool.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/cpputil/hasync.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/cpputil/hobjectpool.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/cpputil/ifconfig.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/cpputil/iniparser.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/cpputil/json.hpp"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/cpputil/singleton.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/cpputil/ThreadLocalStorage.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/evpp/Buffer.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/evpp/Channel.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/evpp/Event.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/evpp/EventLoop.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/evpp/EventLoopThread.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/evpp/EventLoopThreadPool.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/evpp/TimerThread.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/evpp/Status.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/evpp/TcpClient.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/evpp/TcpServer.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/evpp/UdpClient.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/evpp/UdpServer.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/http/httpdef.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/http/wsdef.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/http/http_content.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/http/HttpMessage.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/http/HttpParser.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/http/WebSocketParser.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/http/WebSocketChannel.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/http/server/HttpServer.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/http/server/HttpService.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/http/server/HttpContext.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/http/server/HttpResponseWriter.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/http/server/WebSocketServer.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/http/client/HttpClient.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/http/client/requests.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/http/client/axios.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/http/client/AsyncHttpClient.h"
    "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/http/client/WebSocketClient.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv/libhvConfig.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv/libhvConfig.cmake"
         "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/do_build/CMakeFiles/Export/51ac961e5020fc2ba22ceaef8285f800/libhvConfig.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv/libhvConfig-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv/libhvConfig.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv" TYPE FILE FILES "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/do_build/CMakeFiles/Export/51ac961e5020fc2ba22ceaef8285f800/libhvConfig.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv" TYPE FILE FILES "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/do_build/CMakeFiles/Export/51ac961e5020fc2ba22ceaef8285f800/libhvConfig-noconfig.cmake")
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/do_build/examples/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
  file(WRITE "/home/tq/桌面/net_wipe_network/net_wipe/thirdparty/libhv_new/do_build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
