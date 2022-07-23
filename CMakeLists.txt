cmake_minimum_required(VERSION 3.16)

project(BVP_LIB VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(LIBRARY_NAME Library)
set(EXECUTABLE_NAME Executable)

include(FetchContent)

FetchContent_Declare(

    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 9.0.0 

)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(

    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.10.0 

)
FetchContent_MakeAvailable(spdlog)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)


add_subdirectory(src)
add_subdirectory(main)
#add_subdirectory(tests)


