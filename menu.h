#pragma once
#include "manager.h"

class Menu{
private:
    Manager& m;
    void mostrarOpcionesUsuario();
    void mostrarOpcionesAdmin();
    int pedirOpcion();
    void ejecutarOpcion();
    void pedirDatosRegistro();
    bool pedirDatosLogin(Usuario& usuarioLogueado);
public:
    bool manejarMenuInicio(Usuario &usuarioLogueado);
    void manejarMenu(); //maneja todos los metodos de abajo
    void manejarMenuAdmin();
    void manejarMenuUsuario(Usuario &usuarioLogueado);
    Menu(Manager& _manager);

};
