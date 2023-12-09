project(game_jam)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(GRAPHICS GRAPHICS_API_OPENGL_43)
set(OpenGL_GL_PREFERENCE GLVND)


file(GLOB_RECURSE SOURCES src/*.cpp)


add_executable(game_jam ${SOURCES})

list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/include" "/usr/local/include")

target_include_directories(game_jam PUBLIC ${EXTRA_INCLUDES})
target_include_directories(game_jam PUBLIC include)
target_link_libraries(game_jam PUBLIC raylib)

add_custom_command(TARGET game_jam POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:game_jam> ${CMAKE_SOURCE_DIR}
)
