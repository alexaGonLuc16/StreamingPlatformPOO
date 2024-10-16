#include "CVideo.h"

CVideo::CVideo() {}

CVideo::~CVideo() {}

CVideo::CVideo(string nombre, int calif, int id, int duracion) {
  this->nombre = nombre;
  this->calif = calif;
  this->id = id;
  this->duracion = duracion;
}
void CVideo::setCalif(int calif) { this->calif = calif; }