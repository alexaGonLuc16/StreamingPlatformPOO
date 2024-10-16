#pragma once
#include "CElemento.h"
#include "CVideo.h"
class CSerie : public CElemento {
public:
  CSerie();
  ~CSerie();
  CSerie(string nombre, string genero, int calif, string tipo);
  void rep();
  void listar();
  void filtrarCapCalif(int rango);
};
