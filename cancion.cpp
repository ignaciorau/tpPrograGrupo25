#include <iostream>
#include <cstring>
#include "cancion.h"
#include "interprete.h"
using namespace std;

int Cancion::getIDCancion(){return idCancion;}

const char* Cancion::getTitulo(){return titulo;}
int Cancion::getIDInterprete(){return IDInterprete;}
int Cancion::getGenero(){return genero;}
int Cancion::getReproducciones(){return reproducciones;}
int Cancion::getLikes(){return likes;}
bool Cancion::getEstado() {return estado;}
const char* Cancion::getNombreInterprete() {return nombreInterprete;}

void Cancion::setTitulo(const char* _titulo){strcpy(titulo, _titulo);}
void Cancion::setIDInterprete(int _IDInterprete){IDInterprete=_IDInterprete;}
void Cancion::setGenero(int _genero){genero=_genero;}
void Cancion::setEstado(int _estado){estado=_estado;}
void Cancion::setNombreInterprete(const char* _nombreInterprete) {strcpy(nombreInterprete, _nombreInterprete);}

void cargarCancion();
void mostrarCancion();


