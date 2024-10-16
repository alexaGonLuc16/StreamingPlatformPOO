#pragma once
#include "CElemento.h"
#include "CVideo.h"

class CPelicula : public CElemento {
public:
  CPelicula();
  ~CPelicula() {}
  // CVideo archivo;
  CPelicula(string nombre, string genero, int calif, string tipo);
};