# Versión miníma de CMake
cmake_minimum_required(VERSION 3.10)
# Nombre del proyecto y su idioma
project(CalifAlumno C)
# Agregar archivo fuente
add_executable(CalifAlumno src/CalifAlumno.c)

set(CMAKE_C_STANDARD 99)
target_link_libraries(CalifAlumno m)
