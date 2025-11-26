#include "repositorio.h"

//getters
const std::vector <Usuario>& Repositorio::getUsuarios() const{
        return _usuarios;
}

//metodos
void Repositorio::agregarUsuario(const Usuario& nuevoUsuario){
    _usuarios.push_back(nuevoUsuario);
}

<<<<<<< HEAD
const std::vector <Interprete>& Repositorio::getInterpretes() const{
    return _interpretes;
} 

void Repositorio::agregarInterprete(const Interprete& nuevoInterprete){
    _interpretes.push_back(nuevoInterprete);
}
=======
//la funcion push back agrega un nuevo elemento al final del vector
void Repositorio::agregarInteraccion(const Interaccion& nuevaInteraccion){
    _interacciones.push_back(nuevaInteraccion);
}
>>>>>>> bb57a5445eb30141b33259ec9c69e649514c4b41
