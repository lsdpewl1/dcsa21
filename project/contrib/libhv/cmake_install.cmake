# Install script for directory: /home/vboxuser1/DCSA/contrib/libhv

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
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

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/vboxuser1/DCSA/project/lib/libhv_static.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/hv" TYPE FILE FILES
    "/home/vboxuser1/DCSA/contrib/libhv/hv.h"
    "/home/vboxuser1/DCSA/contrib/libhv/hconfig.h"
    "/home/vboxuser1/DCSA/contrib/libhv/hexport.h"
    "/home/vboxuser1/DCSA/contrib/libhv/base/hplatform.h"
    "/home/vboxuser1/DCSA/contrib/libhv/base/hdef.h"
    "/home/vboxuser1/DCSA/contrib/libhv/base/hatomic.h"
    "/home/vboxuser1/DCSA/contrib/libhv/base/herr.h"
    "/home/vboxuser1/DCSA/contrib/libhv/base/htime.h"
    "/home/vboxuser1/DCSA/contrib/libhv/base/hmath.h"
    "/home/vboxuser1/DCSA/contrib/libhv/base/hbase.h"
    "/home/vboxuser1/DCSA/contrib/libhv/base/hversion.h"
    "/home/vboxuser1/DCSA/contrib/libhv/base/hsysinfo.h"
    "/home/vboxuser1/DCSA/contrib/libhv/base/hproc.h"
    "/home/vboxuser1/DCSA/contrib/libhv/base/hthread.h"
    "/home/vboxuser1/DCSA/contrib/libhv/base/hmutex.h"
    "/home/vboxuser1/DCSA/contrib/libhv/base/hsocket.h"
    "/home/vboxuser1/DCSA/contrib/libhv/base/hlog.h"
    "/home/vboxuser1/DCSA/contrib/libhv/base/hbuf.h"
    "/home/vboxuser1/DCSA/contrib/libhv/base/hmain.h"
    "/home/vboxuser1/DCSA/contrib/libhv/base/hendian.h"
    "/home/vboxuser1/DCSA/contrib/libhv/ssl/hssl.h"
    "/home/vboxuser1/DCSA/contrib/libhv/event/hloop.h"
    "/home/vboxuser1/DCSA/contrib/libhv/event/nlog.h"
    "/home/vboxuser1/DCSA/contrib/libhv/util/base64.h"
    "/home/vboxuser1/DCSA/contrib/libhv/util/md5.h"
    "/home/vboxuser1/DCSA/contrib/libhv/util/sha1.h"
    "/home/vboxuser1/DCSA/contrib/libhv/cpputil/hmap.h"
    "/home/vboxuser1/DCSA/contrib/libhv/cpputil/hstring.h"
    "/home/vboxuser1/DCSA/contrib/libhv/cpputil/hfile.h"
    "/home/vboxuser1/DCSA/contrib/libhv/cpputil/hpath.h"
    "/home/vboxuser1/DCSA/contrib/libhv/cpputil/hdir.h"
    "/home/vboxuser1/DCSA/contrib/libhv/cpputil/hurl.h"
    "/home/vboxuser1/DCSA/contrib/libhv/cpputil/hscope.h"
    "/home/vboxuser1/DCSA/contrib/libhv/cpputil/hthreadpool.h"
    "/home/vboxuser1/DCSA/contrib/libhv/cpputil/hasync.h"
    "/home/vboxuser1/DCSA/contrib/libhv/cpputil/hobjectpool.h"
    "/home/vboxuser1/DCSA/contrib/libhv/cpputil/ifconfig.h"
    "/home/vboxuser1/DCSA/contrib/libhv/cpputil/iniparser.h"
    "/home/vboxuser1/DCSA/contrib/libhv/cpputil/json.hpp"
    "/home/vboxuser1/DCSA/contrib/libhv/cpputil/singleton.h"
    "/home/vboxuser1/DCSA/contrib/libhv/cpputil/ThreadLocalStorage.h"
    "/home/vboxuser1/DCSA/contrib/libhv/evpp/Buffer.h"
    "/home/vboxuser1/DCSA/contrib/libhv/evpp/Channel.h"
    "/home/vboxuser1/DCSA/contrib/libhv/evpp/Event.h"
    "/home/vboxuser1/DCSA/contrib/libhv/evpp/EventLoop.h"
    "/home/vboxuser1/DCSA/contrib/libhv/evpp/EventLoopThread.h"
    "/home/vboxuser1/DCSA/contrib/libhv/evpp/EventLoopThreadPool.h"
    "/home/vboxuser1/DCSA/contrib/libhv/evpp/Status.h"
    "/home/vboxuser1/DCSA/contrib/libhv/evpp/TcpClient.h"
    "/home/vboxuser1/DCSA/contrib/libhv/evpp/TcpServer.h"
    "/home/vboxuser1/DCSA/contrib/libhv/evpp/UdpClient.h"
    "/home/vboxuser1/DCSA/contrib/libhv/evpp/UdpServer.h"
    "/home/vboxuser1/DCSA/contrib/libhv/http/httpdef.h"
    "/home/vboxuser1/DCSA/contrib/libhv/http/wsdef.h"
    "/home/vboxuser1/DCSA/contrib/libhv/http/http_content.h"
    "/home/vboxuser1/DCSA/contrib/libhv/http/HttpMessage.h"
    "/home/vboxuser1/DCSA/contrib/libhv/http/HttpParser.h"
    "/home/vboxuser1/DCSA/contrib/libhv/http/WebSocketParser.h"
    "/home/vboxuser1/DCSA/contrib/libhv/http/WebSocketChannel.h"
    "/home/vboxuser1/DCSA/contrib/libhv/http/server/HttpServer.h"
    "/home/vboxuser1/DCSA/contrib/libhv/http/server/HttpService.h"
    "/home/vboxuser1/DCSA/contrib/libhv/http/server/HttpContext.h"
    "/home/vboxuser1/DCSA/contrib/libhv/http/server/HttpResponseWriter.h"
    "/home/vboxuser1/DCSA/contrib/libhv/http/server/WebSocketServer.h"
    "/home/vboxuser1/DCSA/contrib/libhv/http/client/HttpClient.h"
    "/home/vboxuser1/DCSA/contrib/libhv/http/client/requests.h"
    "/home/vboxuser1/DCSA/contrib/libhv/http/client/axios.h"
    "/home/vboxuser1/DCSA/contrib/libhv/http/client/AsyncHttpClient.h"
    "/home/vboxuser1/DCSA/contrib/libhv/http/client/WebSocketClient.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv/libhvConfig.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv/libhvConfig.cmake"
         "/home/vboxuser1/DCSA/project/contrib/libhv/CMakeFiles/Export/lib/cmake/libhv/libhvConfig.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv/libhvConfig-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv/libhvConfig.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv" TYPE FILE FILES "/home/vboxuser1/DCSA/project/contrib/libhv/CMakeFiles/Export/lib/cmake/libhv/libhvConfig.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/libhv" TYPE FILE FILES "/home/vboxuser1/DCSA/project/contrib/libhv/CMakeFiles/Export/lib/cmake/libhv/libhvConfig-noconfig.cmake")
  endif()
endif()

