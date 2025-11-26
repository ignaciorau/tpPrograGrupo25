#include "interaccion.h"
#include <iostream>
#include <string>

using namespace std;

//constructor
Interaccion::Interaccion(int _idInteraccion, int _idUsuario, int _idCancion, int _tipo, int _idPlaylist){
    idInteraccion=_idInteraccion;
    idUsuario=_idUsuario;
    idCancion=_idCancion;
    tipo=_tipo;
    idPlaylist=_idPlaylist;
}

// Getters
long Interaccion::getID() {return idInteraccion;}
int Interaccion::getIDUsuario() {return idUsuario;}
int Interaccion::getIDCancion() {return idCancion;}
int Interaccion::getTipo() {return tipo;}
int Interaccion::getIDPlaylist() {return idPlaylist;}
bool Interaccion::getEstado() {return estado;}

// setters
void Interaccion::setID(int _id) {idInteraccion = _id;}
void Interaccion::setIDUsuario(int _idUsuario) {idUsuario = _idUsuario;}
void Interaccion::setIDCancion(int _idCancion) {idCancion = _idCancion;}
void Interaccion::setTipo(int _tipo) {tipo = _tipo;}
void Interaccion::setIDPlaylist(int _idPlaylist) {idPlaylist = _idPlaylist;}
void Interaccion::setEstado(bool _estado) {estado = _estado;}

// metodos
void Interaccion::cargar() {
    cout << "Nueva interaccion" << endl;
    cout << "ID: ";
    cin >> idInteraccion;
    cout << "ID usuario: ";
    cin >> idUsuario;
    cout << "ID cancion: ";
    cin >> idCancion;
    cout << "Tipo (1-Reproducir, 2-Like, 3-Skip, 4-Agregar, 5-Desagregar)";
    cin >> tipo;

    // elegir de q playlist agregar o borrar
    if (tipo == 4 || tipo == 5) {
        cout << "ID Playlist: ";
        cin >> idPlaylist;
    }   else {
        idPlaylist = 0;
    }

    estado = true;
    cout << "Interacion cargada." << endl;
}

void Interaccion::mostrar() {
    cout << "---------------------------------------------------" << endl;
    cout << "ID Interaccion: " << idInteraccion << endl;
    cout << "Usuario: " << idUsuario << endl;
    cout << "Cancion: " << idCancion << endl;

    cout << "Tipo: " << endl;
    switch(tipo) {
        case 1:
        cout << "Reproduciendo... " << endl;
        break;
        case 2:
        cout << "Me gusta" << endl;
        break;
        case 3:
        cout << "Cancion skipeada" << endl;
        break;
        case 4:
        cout << "Agregada a playlist: " << idPlaylist << endl;
        break;
        case 5:
        cout << "Eliminado de Playlist: " << idPlaylist << endl;
        defautl:
        cout << "Interaccion desconocida." << endl;
        cout << "Tipo (" << tipo << ")" << endl;
        break;
    }
    /* viendo q hacer con el estado
    cout << "Estado: "
    */

    // aca irian los metodos de escribir disco y leerlos, no se si los vamos a usar o como
    // los dejo para despues
}
