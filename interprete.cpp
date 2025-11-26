#include <iostream>
#include <cstring>
#include "interprete.h"
#include <cstring>
using namespace std;

const int Interprete::getIDInterprete() const {return idInterprete;}
const char* Interprete::getNombre() const {return nombre;}
int Interprete::getSuscriptores(){return suscriptores;}
bool Interprete::getNotificaciones(){return notificaciones;}
bool Interprete::getEstado(){return estado;}

void Interprete::setNombre(const char* _nombre){strcpy(nombre, _nombre);}
void Interprete::setNacionalidad(const char* _nacionalidad){strcpy(nacionalidad, _nacionalidad);}
void Interprete::setSuscriptores(int _suscriptores){suscriptores=_suscriptores;}
void Interprete::setEstado(bool _estado){estado=_estado;}
void Interprete::setNotificaciones(bool _notificaciones){notificaciones=_notificaciones;}

void cargarInterprete();
void mostrarInterprete();




