cmake_minimum_required(VERSION 3.10)

project(ezgui)

if(WIN32)
set(raylib_DIR "../Libraries/raylib")
endif()

find_package(raylib REQUIRED)
add_executable(ezgui main.cpp)
target_link_libraries(ezgui raylib)

install(TARGETS ezgui RUNTIME DESTINATION bin)
