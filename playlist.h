#pragma once
#include <string>
#include "cancion.h"
#include <vector>

class Playlist {
   private:
   int id;
   std::string nombre;
   int idUsuario;
   int cantidadCanciones;
   bool estado;
   std::vector<Cancion> canciones;

   public:
   // getters
     int getID() const;
    std::string getNombre() const;
    int getIDUsuario() const;
    bool getEstado() const;
    int getCantidadCanciones() const;

   // setters
   void setID(int _id);
   void setNombre(std::string _nombre);
   void setIDUsuario(int _idUsuario);
   void setEstado(bool _estado);
   void setCantidadCanciones(int _cantidadCanciones);
   // void cargar();
   // void mostrar();

   // bool escribirDisco();
   // bool leerDisco();
   void agregarCancion(const Cancion& c);
    const std::vector<Cancion>& getCanciones() const;
};
