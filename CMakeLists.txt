cmake_minimum_required(VERSION 3.21.0)
set(CMAKE_CXX_STANDARD 11)
project("yocto_parser")

set(LIBCURL_DIR_SRC "${CMAKE_SOURCE_DIR}/libcurl")
set(CURL_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/build/_deps/curl-src/include") # build\_deps\curl-src\include\curl

include(FetchContent)
FetchContent_Declare(lib_boost
  GIT_REPOSITORY "https://github.com/boostorg/boost.git"
  GIT_TAG "boost-1.82.0"
)

# FetchContent_Declare(lib_beast
#   GIT_REPOSITORY "https://github.com/boostorg/beast.git"
#   GIT_TAG "develop"
#   #SOURCE_DIR ${LIBCURL_DIR_SRC}
# )
FetchContent_MakeAvailable(lib_boost)

#set(HEADERS "${CURL_INCLUDE_DIR}/curl/curl.h")
set(SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")


add_executable(yocto_parser ${HEADERS} ${SOURCES})
target_include_directories(yocto_parser PRIVATE Boost::headers)
if(MINGW)
  target_link_libraries(yocto_parser ws2_32)
endif()
target_link_libraries(yocto_parser Boost::asio Boost::beast)

set(SOURCES_BOOST_EXAMPLE "${CMAKE_CURRENT_SOURCE_DIR}/src/new_main.cpp")
add_executable(boost_aexample_parser ${HEADERS} ${SOURCES_BOOST_EXAMPLE})
target_include_directories(boost_aexample_parser PRIVATE Boost::headers)
if(MINGW)
  target_link_libraries(boost_aexample_parser ws2_32)
endif()
target_link_libraries(boost_aexample_parser Boost::asio Boost::beast)
