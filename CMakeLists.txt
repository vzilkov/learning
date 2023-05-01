cmake_minimum_required(VERSION 3.21.0)
#set(CMAKE_CXX_STANDARD 17)
project(yocto_parser)

# set(LIB_CURL_URL "https://github.com/curl/curl.git")
set(LIBCURL_DIR_SRC "${CMAKE_CURRENT_LIST_DIR}/libcurl_new/include")
# set(LIBCURL_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/libcurl/install)

include(FetchContent)
FetchContent_Declare(libcurl_var
  GIT_REPOSITORY "https://github.com/curl/curl.git"
  GIT_TAG "curl-8_0_0"
  SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/libcurl_new"
)
FetchContent_MakeAvailable(libcurl_var)

add_executable(yocto_parser_main main.cpp)
include_directories(${LIBCURL_DIR_SRC})
#target_link_libraries(yocto_parser_main PUBLIC "${CMAKE_CURRENT_LIST_DIR}/libcurl_new/lib/")