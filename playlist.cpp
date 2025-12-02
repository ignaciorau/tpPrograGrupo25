#include "playlist.h"

// GETTERS
int Playlist::getID() const {
    return id;
}

std::string Playlist::getNombre() const {
    return nombre;
}

int Playlist::getIDUsuario() const {
    return idUsuario;
}

bool Playlist::getEstado() const {
    return estado;
}

int Playlist::getCantidadCanciones() const {
    return cantidadCanciones;
}

// SETTERS
void Playlist::setID(int _id) {
    id = _id;
}

void Playlist::setNombre(std::string _nombre) {
    nombre = _nombre;
}

void Playlist::setIDUsuario(int _idUsuario) {
    idUsuario = _idUsuario;
}

void Playlist::setEstado(bool _estado) {
    estado = _estado;
}

void Playlist::setCantidadCanciones(int _cantidadCanciones) {
    cantidadCanciones = _cantidadCanciones;
}

// CANCIONES
void Playlist::agregarCancion(const Cancion& c) {
    canciones.push_back(c);
    cantidadCanciones = (int)canciones.size();
}

const std::vector<Cancion>& Playlist::getCanciones() const {
    return canciones;
}
