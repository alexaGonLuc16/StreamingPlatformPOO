#include "CPelicula.h"

CPelicula::CPelicula() : CElemento() {}

CPelicula::CPelicula(string nombre, string genero, int calif, string tipo)
    : CElemento(nombre, genero, calif, tipo) {}