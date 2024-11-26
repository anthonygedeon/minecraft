cmake_minimum_required(VERSION 3.20)

project(minecraft VERSION 0.0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

file(GLOB SOURCES "src/*.cpp")

# Fetch SDL2
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL
    GIT_TAG release-2.24.0
    GIT_PROGRESS TRUE
)

# Fetch IMGUI
FetchContent_Declare(
    IMGUI
    GIT_REPOSITORY https://github.com/ocornut/imgui
    GIT_TAG v1.91.5  # Use a specific release tag
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(SDL2)
FetchContent_MakeAvailable(IMGUI)

# Add IMGUI as a library
add_library(imgui STATIC
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_demo.cpp
	${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
	${imgui_SOURCE_DIR}/misc/cpp/imgui_stdlib.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_sdl2.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_sdlrenderer2.cpp
)

# Set include directories for IMGUI
target_include_directories(imgui PUBLIC
    ${imgui_SOURCE_DIR}
    ${imgui_SOURCE_DIR}/backends
    ${SDL2_SOURCE_DIR}/include
)

# Link SDL2 to the IMGUI library
target_link_libraries(imgui PUBLIC SDL2::SDL2 SDL2::SDL2main)

include_directories(include)
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories for the main project
target_include_directories(${PROJECT_NAME} PUBLIC
    ${imgui_SOURCE_DIR}
    ${imgui_SOURCE_DIR}/backends
    ${SDL2_SOURCE_DIR}/include
)

# Link SDL2, OpenGL, and IMGUI to the main executable
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC
    SDL2::SDL2 SDL2::SDL2main
    imgui
    ${OPENGL_gl_LIBRARY}
)

message(STATUS "IMGUI_INCLUDE_DIR: ${imgui_SOURCE_DIR}")
