#pragma once

//registra todo tipo de relacion con las canciones
class Interaccion {
    private:
    int idInteraccion;
    int idUsuario;
    int idCancion;
    int tipo; // 1=Reproduccion 2= me gusta 3= skip 4= agregado 5= eliminar
    int idPlaylist;
    bool estado;
    public:
    //constructor
    Interaccion(int _idInteraccion, int _idUsuario, int _idCancion, int _tipo, int _idPlaylist);
    // getters setters
    long getID();
    int getIDUsuario();
    int getIDCancion();
    int getTipo();
    int getIDPlaylist();
    bool getEstado();

    //setters
    void setID(int _id);
    void setIDUsuario (int _idUsuario);
    void setIDCancion (int _idCancion);
    void setTipo(int _tipo);
    void setIDPlaylist(int _idPlaylist);
    void setEstado(bool _estado);

    // metodos irian en el managerr
    void cargar();
    void mostrar();

    /*
    bool escribirDisco(int pos);
    bool leerDisco(int pos);
    */
};
