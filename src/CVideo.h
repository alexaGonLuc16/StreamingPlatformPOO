#pragma once
#include "CInterfaz.h"
#include <iostream>
using namespace std;

class CVideo : public CInterfaz {
public:
  string nombre;
  int calif;
  int id;
  int duracion; // duracion en minutos
  CVideo();
  ~CVideo();
  CVideo(string nombre, int calif, int id, int duracion);
  void setCalif(int calif);
  virtual void rep() { cout << "Reproduciendo"; }
  virtual void pausar() { cout << "Pausado"; }

  // sobrecarga de operadores
  CVideo(const string &_nombre, int _duracion)
      : nombre(_nombre), duracion(_duracion) {}

  CVideo operator+(const CVideo &other) { // recibe un objeto como parametro
    int duracion_total = duracion + other.duracion;
    cout << "La unión de los videos fue exitosa: " << endl;
    cout << "El nuevo video tiene una duracion de " << duracion_total << endl;
    return CVideo(nombre + " + " + other.nombre, duracion_total);
  }
};