#!bin/bash

# Nombre de proyecto
PARAM=$1
# Descripción del proyecto
PARAM2=$2
# Versión
PARAM3=$3
#$(pwd) - Ruta de trabajo actual
PWD_DIR=`pwd`

pedir_directorio(){
  if [ -z "$PARAM" ]; then
    echo -e "\e[31m[ERROR] \e[0m - Proporciona un nombre al directorio."
    read -p "Por favor, ingresa el nombre del directorio: " PARAM
    if [ -z "$PARAM" ]; then
      pedir_directorio
    fi
  fi
}

pedir_descrip(){
  if [ -z "$PARAM2" ]; then
    echo -e "\e[31m[ERROR] \e[0m - Proporciona una descripción."
    read -p "Por favor, ingresa una descripción: " PARAM2
    if [ -z "$PARAM2" ]; then
       pedir_descrip
    fi
  fi
}

pedir_v(){
  if [ -z "$PARAM3" ]; then
    echo -e "\e[31m[ERROR] \e[0m - Ingrese la versión del proyecto."
    read -p "Por favor, ingresa la versión del proyecto: " PARAM3
    if [ -z "$PARAM3" ]; then
       pedir_v
    fi
  fi
}

# Funciones que en caso de no recibir argumentos posicionales
# pedirlos y repetir hasta que se valide.
pedir_directorio
pedir_descrip
pedir_v

# Limpiar pantalla
echo -e "\e[2J\e[H"

# En caso que el proyecto exista, terminar ejecución. Si no crear archivos y
# carpetas del proyecto
if [ -d "$PARAM" ]; then
    echo -e "El directorio \e[34m'$PARAM'\e[0m ya existe.     \e[1;31m\xE2\x9C\x98\e[0m"
else
    echo -e "Construyendo proyecto \e[34m'$PARAM'\e[0m ...\n"
    mkdir "$PARAM"
    echo -e "\e[34m[CREATED]\e[0m - '$PWD_DIR/$PARAM'   \e[1;32m\xE2\x9C\x94\e[0m"
    mkdir "./$PARAM/src/"
    echo -e "\e[34m[CREATED]\e[0m - '$PWD_DIR/$PARAM/src/'   \e[1;32m\xE2\x9C\x94\e[0m"
    mkdir "./$PARAM/build/"
    echo -e "\e[34m[CREATED]\e[0m - '$PWD_DIR/$PARAM/build/'   \e[1;32m\xE2\x9C\x94\e[0m"
    echo "# Versión miníma de CMake
cmake_minimum_required(VERSION 3.10)
# Nombre del proyecto y su idioma
project($PARAM C)
# Agregar archivo fuente
add_executable($PARAM src/$PARAM.c)
"   > "./$PARAM/CMakeLists.txt"

    echo -e "\e[34m[CREATED]\e[0m - '$PWD_DIR/$PARAM/CMakeLists.txt'    \e[1;32m\xE2\x9C\x94\e[0m"
    echo "
#include <stdio.h>
#include <stdlib.h>
/*
 * $PARAM2
 * Autor : Ordaz Magos Juan Pablo
 * Fecha de creación: 2025-03-06
 * Versión: $PARAM3
 */

int main(int argc, char *argv[]) {
  printf(\"HELLO!!!\n\");
  return EXIT_SUCCESS;
}"  > ./$PARAM/src/$PARAM.c
    echo -e "\e[34m[CREATED]\e[0m - '$PWD_DIR/$PARAM/src/$PARAM.c'    \e[1;32m\xE2\x9C\x94\e[0m\n"
    tree $PWD_DIR/$PARAM/
    cd $PWD_DIR/$PARAM/build/
    cmake ..
    echo " "
    make
    echo " "
    ./$PARAM
fi
