#include "repositorio.h"

const std::vector <Usuario>& Repositorio::getUsuarios() const{
        return _usuarios;
}

void Repositorio::agregarUsuario(const Usuario& nuevoUsuario){
    _usuarios.push_back(nuevoUsuario);
}

const std::vector <Interprete>& Repositorio::getInterpretes() const{
    return _interpretes;
} 

void Repositorio::agregarInterprete(const Interprete& nuevoInterprete){
    _interpretes.push_back(nuevoInterprete);
}