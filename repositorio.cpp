#include "repositorio.h"

//getters
const std::vector <Usuario>& Repositorio::getUsuarios() const{
        return _usuarios;
}

//metodos
void Repositorio::agregarUsuario(const Usuario& nuevoUsuario){
    _usuarios.push_back(nuevoUsuario);
}


void Repositorio::agregarInterprete(const Interprete& nuevoInterprete){
    _interpretes.push_back(nuevoInterprete);
}


const std::vector <Interprete>& Repositorio::getInterpretes() const{
    return _interpretes;
} 

void Repositorio::agregarInterprete(const Interprete& nuevoInterprete){
    _interpretes.push_back(nuevoInterprete);
}

//la funcion push back agrega un nuevo elemento al final del vector
void Repositorio::agregarInteraccion(const Interaccion& nuevaInteraccion){
    _interacciones.push_back(nuevaInteraccion);
}
