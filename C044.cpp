/*C044 | Destructor virtual — por qué importa
TRAZA — predice qué pasa con y sin destructor virtual:

  class Base {
  public:
      Base()  { cout << "Base creada"    << endl; }
      ~Base() { cout << "Base destruida" << endl; }  // NO virtual
  };
  class Derivada : public Base {
  public:
      Derivada()  { cout << "Derivada creada"    << endl; }
      ~Derivada() { cout << "Derivada destruida" << endl; }
  };

  int main() {
      Base* p = new Derivada();
      delete p;
      return 0;
  }

  a) ¿Qué imprime este programa (sin virtual)?
  b) ¿Qué destructor NO se llama? ¿Qué consecuencia tiene?
  c) ¿Qué cambio de UNA SOLA PALABRA arregla el problema?

  Respuestas:
  a) Base creada
     Derivada creada
     Base destruida
  b) ~derivada
  c) virtual

Implementa ambas versiones y verifica.*/

#include <iostream>

using namespace std;

  class Base {
  public:
      Base()  { cout << "Base creada"    << endl; }
      ~Base() { cout << "Base destruida" << endl; }  // NO virtual
  };
  class Derivada : public Base {
  public:
      Derivada()  { cout << "Derivada creada"    << endl; }
      ~Derivada() { cout << "Derivada destruida" << endl; }
  };

  int main() {
      Base* p = new Derivada();
      delete p;
      return 0;
  }