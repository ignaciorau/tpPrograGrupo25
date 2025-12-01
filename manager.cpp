#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <limits>
#include <vector>
#include "usuario.h"
#include "manager.h"
using namespace std;

Manager::Manager(Repositorio* repo) {
    _repo = repo;
}

bool Manager::eliminarCancion(){
    char nombre[40];
    int pos;
    cout<<"ELIMINAR CANCION"<<endl;
    cout<<"Ingresa el nombre de la cancion: ";

    //limpio el buffer
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.getline(nombre, 40);

    FILE* pfileCanciones=fopen("canciones.dat", "rb+");

    if(pfileCanciones == nullptr) {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }

    Cancion c;
    char respuesta;

    while(fread(&c, sizeof(c), 1, pfileCanciones)){

        //buscamos cancion
        if(strcmp(c.getTitulo(), nombre)==0){

            cout<<"Tarea a eliminar: "<<endl;
            c.mostrarCancion();
            cout<<"Estas seguro de que quieres eliminarla? (S=si/N=no)"<<endl;
            cin>>respuesta;

            if(respuesta=='S' || respuesta=='s'){

                //cambio el estado
                c.setEstado(false);

                //vuelvo un registro atras y lo sobreescribo
                fseek(pfileCanciones, -sizeof(Cancion), SEEK_CUR);

                fwrite(&c, sizeof(Cancion), 1, pfileCanciones);

                fclose(pfileCanciones);
                return true;
            }
            else{
                fclose(pfileCanciones);
                return false;
            }
        }
    }
    cout<<"No se encontro la cancion."<<endl;
    fclose(pfileCanciones);
    return false;
}

Cancion Manager::pedirDatosCancion(){
    char titulo[40];
    int idCancion, IDInterprete, genero;

    cout<<"NUEVA CANCION"<<endl;
    cout<<"Ingresa el titulo: ";
    //limpiamos el buffer
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.getline(titulo, 40);
    cout<<"Ingresa el id de cancion: ";
    cin>>idCancion;

    if(!verificarDatosCancion(idCancion, titulo)){
        return Cancion(); //devuelve un objeto vacio si es q se repiten los datos
    }

    cout<<"Ingresa el id de interprete: ";
    cin>>IDInterprete;
    cout<<"Generos!!"<<endl;
    cout<<"1. Pop"<<endl;
    cout<<"2. Rock"<<endl;
    cout<<"3. Trap"<<endl;
    cout<<"4. Hip hop"<<endl;
    cout<<"5. Rap"<<endl;
    cout<<"6. Reggaeton"<<endl;
    cout<<"7. Clasica"<<endl;
    cout<<"Ingresa el genero: ";
    cin>>genero;

    //si siguio el flujo significa q no se repite, creo un objeto temporal ya q solo lo necesito para retornalo
    //por lo tanto no hace falta ponerle nombre
    return Cancion(idCancion, titulo, IDInterprete, genero);
}

bool Manager::verificarDatosCancion(int idCancion, const char* titulo){
    FILE* pfileCanciones=fopen("canciones.dat", "rb");

    if(pfileCanciones == nullptr) {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }

    Cancion c;

    while(fread(&c, sizeof(c), 1, pfileCanciones)){

        //verificar ID
        if(c.getIDCancion()==idCancion){
            cout<<"Ya existe una cancion con ese id! "<<endl;

            fclose(pfileCanciones);
            return false;
        }

        //verificar TITULO
        if(strcmp(c.getTitulo(), titulo)==0){
            cout<<"Ya existe una cancion con ese titulo! "<<endl;

            fclose(pfileCanciones);
            return false;
        }

    }
    fclose(pfileCanciones);
    return true;
}

bool Manager::agregarCancion(){
    //"ab" agrega en el archivo, si el archivo no existe, lo crea
    FILE* pFileCanciones=fopen("canciones.dat", "ab");

    if (pFileCanciones == nullptr) {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }

    //pedir datos y crear objeto cancion
    Cancion nuevaCancion=pedirDatosCancion();

    //si el id es 0 no guardamos la cancion en archivo
    if(nuevaCancion.getIDCancion()==0){
        return false;
    }

    //si llega hasta aca se registra la cancion en archivo
    fwrite(&nuevaCancion, sizeof(Cancion), 1, pFileCanciones);
    fclose(pFileCanciones);
    return true;
}

bool Manager::buscarCancion(Cancion &cancionBuscada){
    int opc;

    cout<<"BUSQUEDA DE CANCION"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"1.Buscar por nombre"<<endl;
    cout<<"2. Buscar por ID"<<endl;
    cout<<"3. Buscar por genero"<<endl; //esta me muestra varias pq hay muchas de un solo genero
    cout<<"Ingresa una opcion: ";
    cin>>opc;
    system("cls");

    switch(opc){
    case 1:
        char nombre[40];
        cout<<"Ingresa el nombre: ";

        //limpio el buffer
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.getline(nombre, 40);

        if(buscarCancionPorNombre(nombre, cancionBuscada)){
            cancionBuscada.mostrarCancion();
            return true;
        }
        else{
            cout<<"No se encontro resultado.."<<endl;
            return false;
        }

    case 2:
        int id;
        cout<<"Ingresa el ID: ";
        cin>>id;
        if(buscarCancionPorId(id, cancionBuscada)){
            cancionBuscada.mostrarCancion();
            return true;
        }
        else{
            cout<<"No se encontro resultado.."<<endl;
            return false;
        }

    case 3:
        int genero;
        cout<<"Genero"<<endl;
        cout<<"1. Pop"<<endl;
        cout<<"2. Rock"<<endl;
        cout<<"3. Trap"<<endl;
        cout<<"4. Hip hop"<<endl;
        cout<<"5. Rap"<<endl;
        cout<<"6. Reggaeton"<<endl;
        cout<<"7. Clasica"<<endl;
        cout<<"Selecciona el genero: ";
        cin>>genero;

        vector<Cancion> encontradas=buscarCancionPorGenero(genero);

        if(encontradas.empty()){
           cout<<"No se encontraron resultados.."<<endl;
           return false;
        }
        else{
            cancionBuscada=seleccionarCancion(encontradas);
            return true;
        }
    }
}

bool Manager::buscarCancionPorId(int id, Cancion& cancionEncontrada){

    FILE* pFileCanciones= fopen("canciones.dat", "rb");

    if (pFileCanciones == nullptr) {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }

    Cancion c;

    while(fread(&c, sizeof(Cancion), 1, pFileCanciones)){
        if(c.getIDCancion()==id && c.getEstado()==true){
                cancionEncontrada=c;
                fclose(pFileCanciones);
                return true;
            }
        }
    fclose(pFileCanciones);
    return false;
}

bool Manager::buscarCancionPorNombre(const char* nombre, Cancion& cancionEncontrada){

    FILE* pFileCanciones= fopen("canciones.dat", "rb");

    if (pFileCanciones == nullptr) {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }

    Cancion c;

    while(fread(&c, sizeof(Cancion), 1, pFileCanciones)){
        if(strcmp(c.getTitulo(), nombre)==0 && c.getEstado()==true){
                cancionEncontrada=c;
                fclose(pFileCanciones);
                return true;
            }
        }
            fclose(pFileCanciones);
            return false;
}

vector<Cancion> Manager::buscarCancionPorGenero(int genero){

    vector<Cancion> resultados;
    FILE* pFileCanciones= fopen("canciones.dat", "rb");

    if (pFileCanciones == nullptr) {
        cout << "No se pudo abrir el archivo." << endl;
    }

    Cancion c;
    int indice=0;

    cout<<"Resultados encontrados: "<<endl;
    while(fread(&c, sizeof(Cancion), 1, pFileCanciones)){
        if(c.getGenero()==genero && c.getEstado()==true){
            indice++;
            cout<<indice<<") "<<c.getTitulo()<<endl;
            resultados.push_back(c);
        }
    }
    fclose(pFileCanciones);
    return resultados;
}

Cancion Manager::seleccionarCancion(const vector<Cancion> &lista){
    int seleccion;
    cout<<"Seleccione una cancion: "<<endl;
    cin>>seleccion;

    return lista[seleccion-1];
}

bool seguirArtista();
bool dejarDeSeguirArtista();

bool Manager::registrarInteraccion(int _idUsuario, int _idCancion, int _tipo, int _idPlaylist){
    int idGenerado;

    //generamos id de la nueva interaccion
    idGenerado=generarIdInteraccion();

    //creamos interaccion
    Interaccion nuevaInt(idGenerado, _idUsuario, _idCancion, _tipo, _idPlaylist);

    //guardar en el disco y la ram
    if(guardarInteraccionEnDisco(nuevaInt)){
        _repo->agregarInteraccion(nuevaInt);
        return true;
    }
    else{
        return false;
    }
}

bool Manager::guardarInteraccionEnDisco(const Interaccion &nuevaInteraccion){
    FILE *pFileInteraccion = fopen("interaccion.dat", "ab");

    if(pFileInteraccion==nullptr){
        cout<<"No se pudo abrir el archivo"<<endl;
        return false;
    }

    fwrite(&nuevaInteraccion, sizeof(Interaccion), 1, pFileInteraccion);
    fclose(pFileInteraccion);
    return true;

}

int Manager::generarIdInteraccion(){
    idGenerado++;
    return idGenerado;
}

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

bool Manager::buscarInterprete(Interprete &interpreteBuscado) {
    int opc;
    cout << "BUSQUEDA DE INTERPRETE" << endl;
    cout << "-------------------" << endl;
    cout << "1.Buscar por nombre" << endl;
    cout << "Ingresa una opcion: ";
    cin >> opc;

    switch (opc) {
    case 1:
        char nombre[30];
        cout << "Ingresa el nombre: ";
        cin.ignore();
        cin.getline(nombre, 30);

        if (buscarInterpretePorNombre(nombre, interpreteBuscado)) {
            cout << "Interprete encontrado:" << endl;
            interpreteBuscado.mostrarInterprete();
            return true;
        } else {
            cout << "No se encontro resultado.." << endl;
            return false;
        }
    }

    return false;
}


bool Manager::buscarInterpretePorNombre(const char* nombre, Interprete& interpreteEncontrado) {
    FILE *pFile = fopen("interpretes.dat", "rb");
    if (!pFile) {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }

    Interprete i;

    while (fread(&i, sizeof(Interprete), 1, pFile) == 1) {
        if (strcmp(i.getNombre(), nombre) == 0) {
            interpreteEncontrado = i;
            fclose(pFile);
            return true;
        }
    }

    fclose(pFile);
    return false;
}

/*  
vector<Interprete> Manager::buscarInterpretePorGenero(int genero) {
    vector<Interprete> resultados;
    FILE* pFile = fopen("interpretes.dat", "rb");

    if (pFile == nullptr) {
        cout << "No se pudo abrir el archivo." << endl;
        fclose(pFile);
    }

    Interprete i;

    cout << "Interpretes del genero " << genero << ":" << endl;
    while (fread(&i, sizeof(Interprete), 1, pFile)) {
        // Suponiendo que Interprete tiene un método getGenero()
        if (i.getGenero() == genero) {
            cout << i.getNombre() << endl;
            resultados.push_back(i);
        }
    }
    fclose(pFile);
    return resultados;  
} */
Interprete Manager::seleccionarInterprete(const vector<Interprete> &lista) {
    int seleccion;
    cout << "Seleccione un interprete: " << endl;
    cin >> seleccion;

    return lista[seleccion - 1];

}
