# Versión miníma de CMake
cmake_minimum_required(VERSION 3.10)
# Nombre del proyecto y su idioma
project(Sonidos C)
# Agregar archivo fuente
add_executable(Sonidos src/Sonidos.c)

# Buscar y enlazar ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Enlazar con ncurses
target_link_libraries(Sonidos ${CURSES_LIBRARIES})
