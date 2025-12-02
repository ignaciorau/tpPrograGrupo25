#pragma once
#include "repositorio.h"
#include "usuario.h"
#include <limits>

class Manager{
private:
    // puntero al repositorio
    Repositorio* _repo = nullptr ; // para ver si esta incializado;
    int idGenerado=100;
    int generarIdInteraccion();
public:
    // constructor
    Manager(Repositorio* repo = nullptr);
    //son booleanas pq devuelven true o false si la operacion se llevo a cabo con exito
    //usuario
    bool intentarRegistro(int idUsuario, const char* nombre, const char* apellido, const char* dni, const char* mail, const char* telefono);
    bool intentarLogin(int idUsuario, const char* mail, Usuario &usuarioLogueado);
    bool cargarDatosDesdeArchivos();
    bool guardarUsuarioEnArchivo(const Usuario& nuevoUsuario);
    int mostrarTodasLasCanciones();

    //interaccion
    bool guardarInteraccionEnDisco(const Interaccion &nuevaInteraccion);
    bool registrarInteraccion(int _idUsuario, int _idCancion, int _tipo, int _idPlaylist);

    //canciones
    bool agregarCancion();
    bool eliminarCancion();
    void verTodasLasCanciones();
    bool buscarCancion(Cancion &cancionBuscada);
    bool buscarCancionPorId(int id, Cancion& cancionEncontrada);
    bool buscarCancionPorNombre(const char* nombre, Cancion& cancionEncontrada);
    vector<Cancion>  buscarCancionPorGenero(int genero);
    Cancion seleccionarCancion(const vector<Cancion> &lista);
    Cancion pedirDatosCancion();
    bool verificarDatosCancion(int idCancion, const char* titulo);

    //interprete
    bool buscarInterprete(Interprete &interpreteEncontrado);
    bool buscarInterpretePorNombre(const char* nombre, Interprete& interpreteEncontrado);
    Interprete seleccionarInterprete(const vector<Interprete> &lista);

        // playlists
    std::vector<Playlist> obtenerPlaylistsDeUsuario(int idUsuario);
    bool crearPlaylist(Usuario &usuarioLogueado);
        //canciones
    bool agregarCancionAPlaylist(Usuario &usuarioLogueado, const Cancion &cancion);

};


