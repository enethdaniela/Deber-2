/*C015 | Destructor — orden de destrucción
Crea la clase Recurso con:
  string nombre
  Constructor: imprime "[nombre] creado."
  Destructor:  imprime "[nombre] destruido."

En main declara 3 objetos en distintos bloques anidados
y observa el orden en que se destruyen.

  int main() {
      Recurso r1("A");
      {
          Recurso r2("B");
          {
              Recurso r3("C");
          }    // ← r3 se destruye aquí
      }        // ← r2 se destruye aquí
               // ← r1 se destruye al salir de main
      return 0;
  }

TRAZA A MANO: escribe el orden de los mensajes antes de
implementar.
Salida esperada:
  A creado.
  B creado.
  C creado.
  C destruido.
  B destruido.
  A destruido.*/

//Traza a mano
//  A creado.
//  B creado.
//  C creado.
//  C destruido.
//  B destruido.
//  A destruido.
#include <iostream>

class Recurso {
    public:
        std::string nombre;

        Recurso(std::string nom) : nombre(nom) {
            std::cout << nombre << " creado." << std::endl; 
        }
        ~Recurso(){
            std::cout << nombre << " destruido" << std::endl;
        }
};

int main() {
     Recurso r1("A");
      {
          Recurso r2("B");
          {
              Recurso r3("C");
          }    // ← r3 se destruye aquí
      }        // ← r2 se destruye aquí
               // ← r1 se destruye al salir de main

    return 0; 
}