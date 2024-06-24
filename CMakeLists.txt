cmake_minimum_required(VERSION 3.5)

project(hhServerTCP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(TCPLib)

add_executable(hhServerTCP main.cpp
    customserver.h customserver.cpp)
target_link_libraries(hhServerTCP PRIVATE TCP)

include(GNUInstallDirs)
install(TARGETS hhServerTCP
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_include_directories(
    hhServerTCP PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/TCPLib
)
