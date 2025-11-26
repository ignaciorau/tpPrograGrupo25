#pragma once

class Interprete{
private:
    int idInterprete;
    char nombre[40];
    char nacionalidad[30];
    int suscriptores;
    bool notificaciones;
    bool estado;
public:
    const int getIDInterprete() const;
    const char* getNombre() const; //no se si hacerlo const a este tmb
    int getSuscriptores();
    bool getNotificaciones();
    bool getEstado();

    void setNombre(const char* _nombre);
    void setNacionalidad(const char* _nacionalidad);
    void setSuscriptores(int _suscriptores);
    void setEstado(bool _estado);
    void setNotificaciones(bool _notificaciones);

    void cargarInterprete();
    void mostrarInterprete();

    /*
    bool escribirDisco(int pos); nose si vamos a usar estas funciones
    bool leerDisco(int pos);
    */
};
