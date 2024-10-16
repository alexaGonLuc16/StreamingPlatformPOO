#include "CInterfaz.h"
#include "CPelicula.h"
#include "CSerie.h"
#include <iostream>
#include <vector>

int menuSeries() {
  int entrada = 0;
  cout << endl << "Presiona 1 si quieres reproducir una serie" << endl;
  cout << "Presiona 2 si quieres filtrar los capitulos de una serie por "
          "calificacion\n";
  cin >> entrada;
  return entrada;
}

int menu() {
  int entrada = 0;
  cout << endl << "Presiona 1 si quieres ver peliculas" << endl;
  cout << "Presiona 2 si quieres ver series\n";
  cout << "Presiona 3 si quieres filtrar series y películas por calificacion\n";
  cout << "Presiona 4 si quieres calificar un capitulo o pelicula\n";
  cout << "Presiona 5 si quieres salir de la plataforma\n";
  cout << "Presiona 6 si quieres unir un video\n";
  cin >> entrada;
  return entrada;
}

void elegirRango() {
  cout << "Elige un rango" << endl << endl;
  cout << "1. De 0 a 20 " << endl;
  cout << "2. De 21 a 40 " << endl;
  cout << "3. De 41 a 60 " << endl;
  cout << "4. De 61 a 80 " << endl;
  cout << "5. De 81 a 100 " << endl;
}

void listarTodo(vector<CElemento *> &todos, int entrada) {
  for (int i = 0; i < todos.size(); i++) {
    if (entrada == 1) {
      if (todos[i]->tipo == "P") {
        cout << i + 1 << ". " << todos[i]->nombre << endl;
      }
    } else { // cuando la entrada == 2

      if (todos[i]->tipo == "S") {
        cout << i + 1 << ". " << todos[i]->nombre << endl;
      }
    }
  }
}
void listarPorCalf(vector<CElemento *> &todos, int entrada) {
  for (int i = 0; i < todos.size(); i++) {
    switch (entrada) {
    case 1:
      if (todos[i]->calif >= 0 && todos[i]->calif <= 20) {
        cout << todos[i]->nombre << endl;
      }
      break;
    case 2:
      if (todos[i]->calif >= 21 && todos[i]->calif <= 40) {
        cout << todos[i]->nombre << endl;
      }
      break;
    case 3:
      if (todos[i]->calif >= 41 && todos[i]->calif <= 60) {
        cout << todos[i]->nombre << endl;
      }
      break;
    case 4:
      if (todos[i]->calif >= 61 && todos[i]->calif <= 80) {
        cout << todos[i]->nombre << endl;
      }
      break;
    case 5:
      if (todos[i]->calif >= 81 && todos[i]->calif <= 100) {
        cout << todos[i]->nombre << endl;
      }
      break;
    default:
      cout << "Opcion invalida";
      break;
    }
  }
}

int main() {
  int seleccion = 0;
  int rango = 0;
  int calf;
  int seleccionCap = 0;
  vector<CElemento *> todos;

  todos.push_back(new CPelicula("La Cenicienta", "Fantasía", 10, "P"));
  todos.push_back(new CPelicula("La Sirenita", "Fantasía", 1, "P"));
  todos.push_back(new CPelicula("Spiderman 3", "Accion", 90, "P"));
  todos.push_back(new CPelicula("Pinocho", "Fantasía", 96, "P"));
  todos.push_back(new CSerie("My Little Pony", "Fantasía", 78, "S"));
  todos.push_back(new CSerie("Esa Sonrisa Tuya", "Romance", 93, "S"));
  todos.push_back(new CSerie("Stranger Things", "Accion", 90, "S"));

  // inicio de la plataforma
  cout << "Bienvenido a ALEFIA" << endl;
  todos[4]->archivos[0].nombre = "Amistad";
  todos[4]->archivos[0].calif = 98;
  todos[4]->archivos[1].nombre = "Lealtad";
  todos[4]->archivos[1].calif = 87;
  todos[4]->archivos[2].nombre = "Solidaridad";
  todos[4]->archivos[2].calif = 75;
  todos[4]->archivos[3].nombre = "Amor";
  todos[4]->archivos[3].calif = 89;

  todos[5]->archivos[0].nombre = "Cap 1";
  todos[5]->archivos[0].calif = 80;
  todos[5]->archivos[1].nombre = "Cap 2";
  todos[5]->archivos[1].calif = 90;
  todos[5]->archivos[2].nombre = "Cap 4";
  todos[5]->archivos[2].calif = 77;
  todos[5]->archivos[3].nombre = "Cap 5";
  todos[5]->archivos[3].calif = 52;

  todos[6]->archivos[0].nombre = "Cap 1";
  todos[6]->archivos[0].calif = 98;
  todos[6]->archivos[1].nombre = "Cap 2";
  todos[6]->archivos[1].calif = 87;
  todos[6]->archivos[2].nombre = "Cap 3";
  todos[6]->archivos[2].calif = 75;
  todos[6]->archivos[3].nombre = "Cap 4";
  todos[6]->archivos[3].calif = 89;
  while (true) {
    seleccion = menu();
    if (seleccion == 1) {
      listarTodo(todos, seleccion);
      cout << "Cual quieres reproducir: " << endl;
      cin >> seleccion;
      todos[seleccion - 1]->rep();
    } else if (seleccion == 2) {
      listarTodo(todos, seleccion);
      seleccion = menuSeries();
      if (seleccion == 1) {
        cout << "Selecciona la serie que quieres reproducir" << endl;
        cin >> seleccion;
        todos[seleccion - 1]->rep();
      } else {
        cout << "Selecciona la serie a filtrar" << endl;
        cin >> seleccion;
        elegirRango();
        cin >> rango;
        todos[seleccion - 1]->filtrarCapCalif(rango);
      }

    } else if (seleccion == 3) {
      elegirRango();
      cin >> seleccion;
      listarPorCalf(todos, seleccion);

    } else if (seleccion == 4) {
      cout << "Selecciona la serie o pelicula a calificar" << endl;
      for (int i = 0; i < todos.size(); i++) {
        cout << i + 1 << ". " << todos[i]->nombre << endl;
      }
      cin >> seleccion;
      if (todos[seleccion - 1]->tipo == "P") {
        cout << "Escribe la calificacion: ";
        cin >> calf;
        todos[seleccion - 1]->archivos[0].setCalif(calf);
        cout << "La pelicula'" << todos[seleccion - 1]->nombre
             << " se calificó con: ";
        cout << todos[seleccion - 1]->archivos[0].calif << endl;

      } else {
        cout << "Selecciona el capitulo que quieres calificar: " << endl;
        todos[seleccion - 1]->listar();
        cin >> seleccionCap;
        cout << "Escribe la calificacion: ";
        cin >> calf;
        todos[seleccion - 1]->archivos[seleccionCap - 1].setCalif(calf);
        cout << "El capitulo '"
             << todos[seleccion - 1]->archivos[seleccionCap - 1].nombre << "' "
             << " Se calificó con:  "
             << todos[seleccion - 1]->archivos[seleccionCap - 1].calif << endl;
      }
    } else if (seleccion == 5) {
      cout << "Saliste de la plataforma...";
      break;
    } else {
      string nombre1 = "";
      string nombre2 = "";
      int duracion1 = 0;
      int duracion2 = 0;
      cout << "Ingresa el nombre del video 1: ";
      cin >> nombre1;
      cout << "Ingresa el nombre del video 2: ";
      cin >> nombre2;
      cout << "Ingresa la duracion del video 1: ";
      cin >> duracion1;
      cout << "Ingresa la duracion del video 2: ";
      cin >> duracion2;

      CVideo video1(nombre1, 100, 1, duracion1);
      CVideo video2(nombre2, 90, 2, duracion2);
      // Sumar los videos
      CVideo nueva_pelicula = video1 + video2;

      cout << "El video " << nombre1 << "dura : ";
      cout << video1.duracion << endl; // Salida: Video 1 (110 minutos)
      cout << "El video " << nombre1 << "dura : ";
      cout << video2.duracion << endl; // Salida: Video 2 (80 minutos)

      cout << "La nueva pelicula dura : ";
      cout << nueva_pelicula.duracion
           << endl; // Salida: Video 1 + Video 2 (190 minutos)
    }
  }
}
