#pragma once
using namespace std;

class Cancion{
private:
    int idCancion;
    char titulo[40];
    int IDInterprete; 
    int genero;
    int reproducciones;
    int likes;
    bool estado;
    char nombreInterprete[50];

public:
    Cancion();
    Cancion(int id, const char* t, int idInt, int gen);

    int getIDCancion();
    const char* getTitulo(); //nose si hacerlo const o no
    int getIDInterprete();
    int getGenero();
    int getReproducciones();
    int getLikes();
    bool getEstado();
    const char* getNombreInterprete();

    void setTitulo(const char* _titulo);
    void setIDInterprete(int _IDInterprete);
    void setGenero(int _genero);
    void setEstado(int _estado);
    void setNombreInterprete(const char* _nombreInterprete);
    
    void cargarCancion();
    void mostrarCancion();

    bool escribirDisco(int pos); //nose si vamos a usar estas funciones
    bool leerDisco(int pos);

};
