#include <iostream>
#include <limits>
#include <string>
#include "menu.h"
using namespace std;

void ejecutarOpcion();

Menu::Menu(Manager& _manager) : m(_manager){}

int Menu::pedirOpcion(){
    int opc;
    bool entradaValida=false;

    while(!entradaValida){
    cout<<"Ingresa una opcion: ";

    //pide el dato y verifica que la opc ingresada corresponda con su tipo de dato (int)
    if(cin>>opc){
        entradaValida=true;
        return opc;
    }
    else{
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //descarta todos los caracteres que haya en el b�fer de entrada hasta encontrar un salto de l�nea ('\n'),
        cout<<"Ingresa una opcion valida"<<endl;
    }
    }
}

void Menu::pedirDatosRegistro(){
    int id;
    char nombre[40], apellido[40], dni[12], telefono[20], mail[60];
    bool suscriptor;

    cout<<"-----Registrate-----"<<endl;
    cout<<"ID: "<<endl;
    cin>>id;
    cout<<"Nombre: ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.getline(nombre, 40);
    cout<<"Apellido: ";
    cin.getline(apellido, 40);
    cout<<"DNI: ";
    cin.getline(dni, 12);
    cout<<"Telefono: ";
    cin.getline(telefono, 20);
    cout<<"Mail: ";
    cin.getline(mail, 60);

    if(m.intentarRegistro(id, nombre, apellido, dni, mail, telefono)){
        cout<<"Usuario registrado correctamente!"<<endl;
    }
    else{
        cout<<"Registro fallido, intenta denuevo!"<<endl;
    }
}

bool Menu::pedirDatosLogin(Usuario& usuarioLogueado){
    int id;
    char mail[60];
    cout<<"---Inicia sesion con tus datos---"<<endl;
    cout<<"MAIL:";
    cin>>mail;
    cout<<"ID: ";
    cin>>id;

    if(m.intentarLogin(id, mail, usuarioLogueado)){
        cout<<"Datos correctos! has iniciado sesion"<<endl;
        return true;
    }
    else{
        cout<<"El mail o el id no coinciden, intenta denuevo"<<endl;
        return false;
    }
}
bool Menu::manejarMenuInicio(Usuario &usuarioLogueado){
    int opc;
    do{
    cout<<"---SISTEMA DE REPRODUCCION DE MUSICA---"<<endl;
    cout<<"1. Iniciar sesion"<<endl;
    cout<<"2. Registrarse"<<endl;
    cout<<"0. Salir"<<endl;
    cout<<"---------------------------------------"<<endl;

    opc=pedirOpcion();
    system("pause");
    system("cls");

    if(opc==1){
        bool logueado=pedirDatosLogin(usuarioLogueado);
        system("pause");
        system("cls");
        return logueado;
    }
    else if(opc==2){
        pedirDatosRegistro();
        system("pause");
        system("cls");
        }
    else{
        cout<<"Gracias por usar nuestra aplicacion!"<<endl;
    }
    }while(opc!=0);
}

//maneja todo lo q tiene q ver con menu
void Menu::manejarMenu(){
    Usuario usuarioLogueado;

    //si se logeo correctamente preguntamos si es admin o no
    if(manejarMenuInicio(usuarioLogueado)){
        if(usuarioLogueado.getEsAdmin()){
            manejarMenuAdmin();
        }else{
            manejarMenuUsuario();
        }
}
}

void Menu::mostrarOpcionesUsuario() {
    cout<<"=========================================="<<endl;
    cout<<"         MENU USUARIO"<<endl;
    cout<<"=========================================="<<endl;
    cout<<"1. Buscar canciones"<<endl;
    cout<<"2. Buscar interprete"<<endl;
    cout<<"3. Ver todas las canciones"<<endl;
    cout<<"4. Crear playlist"<<endl;
    cout<<"5. Ver mi perfil"<<endl;
    cout<<"0. Cerrar sesion"<<endl;
    cout<<"=========================================="<<endl;


}
void Menu::manejarMenuUsuario(){
    int opc;
    int idCancion;
    do{
        mostrarOpcionesUsuario();
        opc=pedirOpcion();
        system("pause");
        system("cls");

        switch(opc){
            case 1:
                system("pause");
                break;
            case 2:
                // misma funcion
                system("pause");
                break;
            case 3:
                break;
            case 4:
                // por implementar
                system("pause");
                break;
            case 5:
                //crear playlist
                break;
            case 6:
                //ver mi perfil
                break;
            case 0:
                cout<<"Cerrando sesion..."<<endl;
                break;
            default:
                cout<<"Opcion no valida, intente de nuevo"<<endl;
        }
    }while(opc!=0);
}
void Menu::mostrarOpcionesAdmin () {
    cout<<"=========================================="<<endl;
    cout<<"         MENU ADMINISTRADOR"<<endl;
    cout<<"=========================================="<<endl;
    cout<<"1. Agregar cancion"<<endl;
    cout<<"2. Eliminar cancion"<<endl;
    cout<<"3. Modificar cancion"<<endl;
    cout<<"4. Ver todas las canciones"<<endl;
    cout<<"5. Ver todos los interpretes"<<endl;
    cout<<"6. Registrar interprete"<<endl;
    cout<<"7. Eliminar interprete"<<endl;
    cout<<"8. Estadisticas"<<endl;
    cout<<"9. Ver todos los usuarios"<<endl;
    cout<<"0. Cerrar sesion"<<endl;
    cout<<"=========================================="<<endl;
}

void Menu::manejarMenuAdmin(){
    int opc;
    int id;

    do{
        mostrarOpcionesAdmin();
        opc = pedirOpcion();
        system("cls");

        switch(opc){
            case 1:
                // mostrar canciones
                system("pause");
                break;

            case 2:
                // agregar cancion
                system("pause");
                break;

            case 3:
                cout<<"Ingrese ID de cancion a eliminar: ";
                cin>>id;
                // eliminar cancion
                system("pause");
                break;

            case 4:
                // funcion que permita cambiarle el nombre por ejemplo
                cout<<"Modificar cancion"<<endl;
                system("pause");
                break;

            case 5:
                // muestra todos los interpretes
                system("pause");
                break;

            case 6:
                // registra nuevo interprete
                system("pause");
                break;

            case 7:
                // eliminar interprete
                system("pause");
                break;

            case 8:
                // estadisticas de reproduccion
                system("pause");
                break;

            case 9:
                // muestra todos los usuarios registrados
                system("pause");
                break;

            case 0:
                cout<<"Cerrando sesion..."<<endl;
                // funcion cerrar sesion
                system("pause");
                break;

            default:
                cout<<"Opcion invalida!"<<endl;
                system("pause");
                break;
        }
        system("cls");

    }while(opc!=0);
}
