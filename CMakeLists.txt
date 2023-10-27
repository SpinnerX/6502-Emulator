cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME 6502-Emulator)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)

# set(CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD 20)

# This is how we are able to simply just include 
# Ref Link: https://stackoverflow.com/questions/8304190/cmake-with-include-and-source-paths-basic-setup

# Ref Link that has the solution: https://stackoverflow.com/questions/73991892/what-is-the-best-way-to-add-assimp-to-a-cmake-project

# This is so we can simply know where the other directories are located in the project
# Such as if we needed to find common we can do ${INCLUDE_DIR}/common instead of manually typing 3DRenderRotator/common
set(PROJECT_INCLUDE_DIR 6502_emulator)


find_package(formatCpp REQUIRED)


# Apply to single targets
# if (CMAKE_COMPILER_IS_GNUCC)
#     target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wno-deprecated-non-prototype)
# endif()

# if(MSVC)
#     target_compile_options(${PROJECT_NAME} /W4)
# endif()

# This is applying to all targets
# These are package maintainers that will let you know what is happening
# Ref Link for these compiler flags: https://stackoverflow.com/questions/14231292/cmake-and-compiler-warnings
# if(CMAKE_COMPILER_IS_GNUCC)
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -wnoi-deprecated-non-prototype")
# endif()


# if(MSVC)
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-deprecated-non-prototype")
# endif()


include_directories(
    ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/include
    # Uncomment these if you want to directly includes the directories themselves
    # Example: instead of doing: #include "common/Utils.h" you would just be doing "Utils.h"
    # ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/include/common
    # ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/include/core
)

# aux_source_directory(${PROJECT_SOURCE_DIR}/ProjectCmake/src all_src)

# Better way instead of GLOBBING 
set(
    all_src
    # ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/src/peripherals/RomMemory.cpp
    # ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/src/peripherals/RamMemory.cpp
    # ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/src/common/Instruction.cpp
    # ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/src/common/CPUState.cpp
    # ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/src/common/Memory.cpp
    # ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/src/core/6502-Emulator.cpp
    # ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/src/common/CPUConfigs.cpp
    # ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/src/core/CPU.cpp
    ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/src/main.cpp
)

set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

add_subdirectory(tests)

add_executable(
    ${PROJECT_NAME}
    ${all_src}
)


##
## NOTE: To run the unit tests, type the command: "ctest"
## This is what will run our unit tests in thhe test directory
enable_testing()


# Define custom target for running tests during build
add_custom_target(TARGET tests COMMAND tests -C $<CONFIGURATION> --verbose)

add_test(
    NAME tests
    COMMAND tests -C $<CONFIGURATION>
)

# Cmake modules here
# include(${PROJECT_SOURCE_DIR}/cmake/glfw.cmake)
target_link_libraries(
    ${PROJECT_NAME}
    formatCpp
)