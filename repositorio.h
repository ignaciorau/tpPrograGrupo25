#pragma once
#include <vector>
#include "usuario.h"
#include "interprete.h"
#include "cancion.h"
#include "interaccion.h"
#include "playlist.h"

class Repositorio{

private:
std::vector<Usuario> _usuarios;
std::vector<Interprete> _interpretes;
std::vector<Cancion> _canciones;
std::vector<Interaccion> _interacciones;
std::vector<Playlist> _playlists;
public:
    //el primer const es pq devuelve un constante, el segundo es para que la funcion getUsuario no modifique ningun atributo
    const std::vector<Usuario>& getUsuarios() const;
    void agregarUsuario(const Usuario& nuevoUsuario);
    const std::vector<Interprete>& getInterpretes() const;
    void agregarInterprete(const Interprete& nuevoInterprete);
};