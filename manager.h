#pragma once
#include "repositorio.h"
#include "usuario.h"
class Manager{
private:
    // puntero al repositorio
    Repositorio* _repo = nullptr ; // para ver si esta incializado;
public:
    // constructor
    Manager(Repositorio* repo = nullptr);
    //son booleanas pq devuelven true o false si la operacion se llevo a cabo con exito
    bool intentarRegistro(int idUsuario, const char* nombre, const char* apellido, const char* dni, const char* mail, const char* telefono);
    bool intentarLogin(int idUsuario, const char* mail, Usuario &usuarioLogueado);
    bool cargarDatosDesdeArchivos();
    bool guardarUsuarioEnArchivo(const Usuario& nuevoUsuario);
    int buscarInterprete();
};
