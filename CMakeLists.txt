cmake_minimum_required(VERSION 2.8.12)
project(ke-pkcs11 C)
set(VERSION "0.1")
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)

include_directories(inc)

set(LSRCS src/pkcs11_main.c)
add_library(kepkcs11 STATIC ${LSRCS})

set(ASRCS app/testapp.c)
add_executable(testapp ${ASRCS})
target_link_libraries(testapp kepkcs11)
