#include <iostream>
#include <cstring>
#include "cancion.h"
#include "interprete.h"
using namespace std;

//Constructor
Cancion::Cancion() {
    idCancion = 0;
    titulo[0] = '\0';
    IDInterprete = 0;
    genero = 0;
    reproducciones = 0;
    likes = 0;
    estado = false;
    nombreInterprete[0] = '\0';
}
int Cancion::getIDCancion(){return idCancion;}

Cancion::Cancion(int id, const char* t, int idInt, int gen) {
    idCancion = id;
    strcpy(titulo, t);
    IDInterprete = idInt;
    genero = gen;
    reproducciones = 0;
    likes = 0;
    estado = true;
    nombreInterprete[0] = '\0';
}
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
void Cancion::mostrarCancion() {
    cout << "ID: " << idCancion << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "ID Interprete: " << IDInterprete << endl;
    cout << "Genero: " << genero << endl;
    cout << "Reproducciones: " << reproducciones << endl;
    cout << "Likes: " << likes << endl;
    cout << "Estado: " << (estado ? "Activo" : "Inactivo") << endl;
    cout << "Interprete: " << nombreInterprete << endl;
}


