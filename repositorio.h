#pragma once
#include <vector>
#include "usuario.h"
#include "interprete.h"
#include "cancion.h"
#include "interaccion.h"
#include "playlist.h"

class Repositorio {

private:
    std::vector<Usuario> _usuarios;
    std::vector<Interprete> _interpretes;
    std::vector<Cancion> _canciones;
    std::vector<Interaccion> _interacciones;
    std::vector<Playlist> _playlists;

public:
    // USUARIOS
    const std::vector<Usuario>& getUsuarios() const;
    void agregarUsuario(const Usuario& nuevoUsuario);

    // INTERPRETES
    const std::vector<Interprete>& getInterpretes() const;
    void agregarInterprete(const Interprete& nuevoInterprete);

    // PLAYLISTS
    const std::vector<Playlist>& getPlaylists() const;
    std::vector<Playlist>& getPlaylists();   // versión no-const para modificar
    void agregarPlaylist(const Playlist& nuevaPlaylist);

    // INTERACCIONES
    void agregarInteraccion(const Interaccion& nuevaInteraccion);
};
