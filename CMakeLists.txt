cmake_minimum_required(VERSION 3.20)

project(minecraft VERSION 0.0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Winline -Wall -Wextra -std=c99 -O2")

include(FetchContent)

file(GLOB_RECURSE SOURCES "src/*.c")

# Fetch SDL2
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL
    GIT_TAG release-2.24.0
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(SDL2)

include_directories(src)
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories for the main project
target_include_directories(${PROJECT_NAME} PUBLIC
    ${SDL2_SOURCE_DIR}/include
)

# Link SDL2 and OpenGL 
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC
    SDL2::SDL2 SDL2::SDL2main
    ${OPENGL_gl_LIBRARY}
	m
)


