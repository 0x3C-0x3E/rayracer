cmake_minimum_required(VERSION 3.16)
project(project C)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Include all .c and .h files recursively from /src
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.c")
file(GLOB_RECURSE HEADER_FILES "${CMAKE_SOURCE_DIR}/src/*.h")

# Create the executable from source and header files
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

# Find and link raylib
find_package(raylib REQUIRED)
target_link_libraries(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} m)

# Include raylib headers
target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_INCLUDE_DIRS})

# Enable -g and -Wall
target_compile_options(${PROJECT_NAME} PRIVATE -g -Wall -lm)

# Copy /res to the build directory
file(COPY "${CMAKE_SOURCE_DIR}/res" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
