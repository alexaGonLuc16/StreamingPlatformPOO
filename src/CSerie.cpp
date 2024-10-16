#include "CSerie.h"

CSerie::CSerie() {
  nombre = "";
  genero = "";
  calif = 0;
  tipo = ' ';
}

CSerie::~CSerie() {}

CSerie::CSerie(string nombre, string genero, int calif, string tipo)
    : CElemento(nombre, genero, calif, tipo) {}

void CSerie::rep() {
  int tamano = sizeof(archivos) / sizeof(archivos[0]);
  for (int i = 0; i < tamano; i++) {
    cout << "Reproduciendo " << archivos[i].nombre << endl;
  }
}

void CSerie::listar() {
  int tamano = sizeof(archivos) / sizeof(archivos[0]);
  for (int i = 0; i < tamano; i++) {
    cout << i + 1 << "." << archivos[i].nombre << endl;
  }
}
void CSerie::filtrarCapCalif(int rango) {
  int tamano = sizeof(archivos) / sizeof(archivos[0]);
  for (int i = 0; i < tamano; i++) {
    switch (rango) {
    case 1:
      if (archivos[i].calif >= 0 && archivos[i].calif <= 20) {
        cout << archivos[i].nombre << endl;
      }
      break;
    case 2:
      if (archivos[i].calif >= 21 && archivos[i].calif <= 40) {
        cout << archivos[i].nombre << endl;
      }
      break;
    case 3:
      if (archivos[i].calif >= 41 && archivos[i].calif <= 60) {
        cout << archivos[i].nombre << endl;
      }
      break;
    case 4:
      if (archivos[i].calif >= 61 && archivos[i].calif <= 80) {
        cout << archivos[i].nombre << endl;
      }
      break;
    case 5:
      if (archivos[i].calif >= 81 && archivos[i].calif <= 100) {
        cout << archivos[i].nombre << endl;
      }
      break;
    default:
      cout << "Opcion invalida";
      break;
    }
  }
}
