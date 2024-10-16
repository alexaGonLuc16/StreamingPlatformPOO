#pragma once
#include "CVideo.h"
#include <iostream>
using namespace std;

class CElemento {
public:
  CVideo archivos[4];

  CElemento();
  ~CElemento() {}
  CElemento(string nombre, string genero, int calif, string tipo);

  virtual void rep();
  virtual void filtrarCapCalif(int rango);
  virtual void listar(){};
  string nombre;
  string genero;
  int calif;
  string tipo; // indica "s" si es una serie y "p" si es una pelicula
};