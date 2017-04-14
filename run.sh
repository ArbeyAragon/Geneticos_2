#!/bin/sh
clear
echo "Compilando ****************************************"
g++ main.cpp Individuo/Indiv.cpp -o  main

echo "Ejecutando ****************************************"
./main

echo "Compilando Para visualizar****************************************"
g++ main.cpp Individuo/Indiv.cpp -o  main

echo "Fin ****************************************"