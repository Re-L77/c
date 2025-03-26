# Versión miníma de CMake
cmake_minimum_required(VERSION 3.10)
# Nombre del proyecto y su idioma
project(Factorial_R-I C)
# Agregar archivo fuente
add_executable(Factorial_R-I src/Factorial_R-I.c)
# Buscar y enlazar ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(Factorial_R-I ${CURSES_LIBRARIES})
