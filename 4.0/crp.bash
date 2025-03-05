#!bin/bash
PARAM=$1
#$(pwd)
PWD_DIR=`pwd`
pedir_directorio(){
  if [ -z "$PARAM" ]; then
    echo -e "\e[31m[ERROR] \e[0m - Proporciona un nombre al directorio."
    read -p "Por favor, ingresa el nombre del directorio: " PARAM
    if [ -z "$PARAM" ]; then
      pedir_directorio
    fi
  else
    DIRECTORIO=$1
  fi
}
pedir_directorio
echo -e "\e[2J\e[H"
echo "$PWD_DIR"
if [ -d "$PARAM" ]; then
    echo -e "El directorio \e[34m'$PARAM'\e[0m ya existe.     \e[1;31m\xE2\x9C\x98\e[0m"
else
    echo -e "El directorio \e[34m'$PARAM'\e[0m no existe. Creándolo..."
    mkdir "$PARAM"
    echo -e "\e[34m[CREATED]\e[0m - '$PWD_DIR/$PARAM'       \e[1;32m\xE2\x9C\x94\e[0m"
fi
