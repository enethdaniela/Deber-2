/*C030 | TRAZA — orden de constructores y destructores
RESUELVE A MANO antes de implementar:
¿En qué orden se imprimen los mensajes?

  class Base {
  public:
      Base()  { cout << "Base creada"    << endl; }
      ~Base() { cout << "Base destruida" << endl; }
  };

  class Derivada : public Base {
  public:
      Derivada()  { cout << "Derivada creada"    << endl; }
      ~Derivada() { cout << "Derivada destruida" << endl; }
  };

  int main() {
      Derivada d;
      return 0;
  }

Escribe la salida esperada A MANO:
  Línea 1: Base creada
  Línea 2: Derivada creada
  Línea 3: Derivada destruida
  Línea 4: Base destruida*/


#include <iostream>

using namespace std;

  class Base {
  public:
      Base()  { cout << "Base creada"    << endl; }
      ~Base() { cout << "Base destruida" << endl; }
  };

  class Derivada : public Base {
  public:
      Derivada()  { cout << "Derivada creada"    << endl; }
      ~Derivada() { cout << "Derivada destruida" << endl; }
  };

  int main() {
      Derivada d;
      return 0;
  }