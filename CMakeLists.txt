# SubterraneanRose Project Root

cmake_minimum_required(VERSION 3.12)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/;${CMAKE_MODULE_PATH}")
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
    message(STATUS "Use vcpkg toolchain from $ENV{VCPKG_ROOT}")
endif()

project(
    "Subterranean Rose"
    VERSION 0.1.0
    DESCRIPTION "The Subterranean Rose Project"
    HOMEPAGE_URL "https://github.com/HenryAWE/SubterraneanRose"

    LANGUAGES C CXX
)

enable_testing()
add_subdirectory(./tools)
add_subdirectory(./source)
add_subdirectory(./locale)
