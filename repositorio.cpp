#include "repositorio.h"

// USUARIOS
const std::vector<Usuario>& Repositorio::getUsuarios() const {
    return _usuarios;
}

void Repositorio::agregarUsuario(const Usuario& nuevoUsuario) {
    _usuarios.push_back(nuevoUsuario);
}

// INTERPRETES
const std::vector<Interprete>& Repositorio::getInterpretes() const {
    return _interpretes;
}

void Repositorio::agregarInterprete(const Interprete& nuevoInterprete) {
    _interpretes.push_back(nuevoInterprete);
}

// PLAYLISTS
const std::vector<Playlist>& Repositorio::getPlaylists() const {
    return _playlists;
}

std::vector<Playlist>& Repositorio::getPlaylists() {
    return _playlists;
}

void Repositorio::agregarPlaylist(const Playlist& nuevaPlaylist) {
    _playlists.push_back(nuevaPlaylist);
}

// INTERACCIONES
void Repositorio::agregarInteraccion(const Interaccion& nuevaInteraccion) {
    _interacciones.push_back(nuevaInteraccion);
}
