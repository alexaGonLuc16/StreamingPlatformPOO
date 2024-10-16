#include "CElemento.h"

CElemento::CElemento() {
  genero = "";
  calif = 0;
  tipo = "";
  nombre = "";
}

CElemento::CElemento(string nombre, string genero, int calif, string tipo) {
  this->genero = genero;
  this->calif = calif;
  this->tipo = tipo;
  this->nombre = nombre;
}

void CElemento::rep() {
  cout << "Estas viendo la película " << nombre << "..." << endl;
  cout << "La pelicula ha terminado";
}

void CElemento::filtrarCapCalif(int rango) {
  cout << "Filtrando caps de" << nombre << endl;
}