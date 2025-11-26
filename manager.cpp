#include <iostream>
#include <cstdio>
#include <cstring>
#include "usuario.h"
#include "manager.h"
using namespace std;

Manager::Manager(Repositorio* repo) {
    _repo = repo;
}

bool seguirArtista();
bool dejarDeSeguirArtista();

bool Manager::intentarRegistro(int idUsuario, const char* nombre, const char* apellido, const char* dni, const char* mail, const char* telefono){

    //el primer usuario creado sera admin, los demas seran usuarios
    FILE *pFileUsuarios = fopen("usuarios.dat", "rb");
    bool esAdmin_=true;

    Usuario u;

    if(pFileUsuarios!=nullptr){

        //si encuentra al menos un archivo, entonces no es el primero por lo tanto no sera admin
        if((fread(&u, sizeof(u), 1, pFileUsuarios)==1)){
            esAdmin_=false;

            //posiciono al inicio denuevo
            fseek(pFileUsuarios, 0, SEEK_SET);

        //aca va a leer para verificar q no exista un usuario con el mismo id o mail
        while(fread(&u, sizeof(u), 1, pFileUsuarios)){

        //verificar ID
        if(u.getID()==idUsuario){
            cout<<"Ya existe un usuario con ese id!"<<endl;

            fclose(pFileUsuarios);
            return false;
        }

        //verificar GMAIL
        if(strcmp(u.getMail(), mail)==0){
            cout<<"Ya existe un usuario con ese mail!"<<endl;

            fclose(pFileUsuarios);
            return false;
        }

    }
    fclose(pFileUsuarios);
    }
    }


    Usuario nuevoUsuario(idUsuario, nombre, apellido, dni, telefono, mail, esAdmin_);

    //luego agregamos el usuario al archivo .dat y luego a la ram, en ese orden
    if(guardarUsuarioEnArchivo(nuevoUsuario)){
        _repo -> agregarUsuario(nuevoUsuario);
        return true;
        }
        else{
            return false;
        }
}

bool Manager::intentarLogin(int idUsuario, const char* mail, Usuario &usuarioLogueado){
    FILE *pFileUsuarios = fopen("usuarios.dat", "rb");

    if(pFileUsuarios==nullptr){
        cout<<"No se pudo abrir el archivo"<<endl;
        return false;
    }

    Usuario u;

    while(fread(&u, sizeof(u), 1, pFileUsuarios)){
        //verificar ID y MAIL
        if(u.getID()==idUsuario && strcmp(u.getMail(), mail)==0){
                usuarioLogueado=u;
                fclose(pFileUsuarios);
                return true;
        }
    }
    fclose(pFileUsuarios);
    return false;
}

bool Manager::cargarDatosDesdeArchivos(){
    // verificar el repositorio
    if (!_repo) {
        cout << "Repositorio no inicializado." << endl;
        return false;
    }
    // abrir archivo de usuarios
    FILE *pFileUsuarios = fopen("usuarios.dat", "rb");

    if(pFileUsuarios==nullptr){
        cout<<"No se pudo abrir el archivo"<<endl;
        return false;
    }

    Usuario u;

    //leelos usuarios del archivo y los agrego al repositorio
    while(fread(&u, sizeof(Usuario), 1, pFileUsuarios) == 1){
        // agregar al repositorio mediante el puntero
        _repo -> agregarUsuario(u);
    }

    fclose(pFileUsuarios);
    return true;
}

bool Manager::guardarUsuarioEnArchivo(const Usuario& nuevoUsuario){
    FILE *pFileUsuarios = fopen("usuarios.dat", "ab");

    if(pFileUsuarios==nullptr){
        cout<<"No se pudo abrir el archivo"<<endl;
        return false;
    }

    fwrite(&nuevoUsuario, sizeof(Usuario), 1, pFileUsuarios);
    fclose(pFileUsuarios);
    return true;
}

int Manager::buscarInterprete() {
    // verifica q el repo exista
    if (!_repo) return -1;


    char nombreBuscado[100];
    cout << "Ingrese el nombre del interprete: ";
    cin >> nombreBuscado;

    cin.getline(nombreBuscado, 100);

    const auto& lista = _repo->getInterpretes();

    for (const auto& interprete : lista) {
        if (strcmp(interprete.getNombre(), nombreBuscado) == 0) {
            cout << "Interprete encontrado: " << interprete.getNombre() << endl;
            return interprete.getIDInterprete();
        }
    }
    cout << "Interprete no encontrado." << endl;
    return -1;
}