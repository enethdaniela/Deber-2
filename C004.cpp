/*C004 | TRAZA — leer código y predecir salida
Lee este código y escribe A MANO qué imprime sin ejecutarlo.
Luego impleméntalo para verificar.

  class Contador {
  public:
      int valor;

      void incrementar()      { valor++;      }
      void decrementar()      { valor--;      }
      void incrementarEn(int n){ valor += n;  }
      void reset()            { valor = 0;    }
      void imprimir()         { cout << "Valor: " << valor << endl; }
  };

  int main() {
      Contador c;
      c.valor = 10;
      c.imprimir();
      c.incrementar();
      c.incrementar();
      c.imprimir();
      c.decrementar();
      c.incrementarEn(5);
      c.imprimir();
      c.reset();
      c.imprimir();
      return 0;
  }

Escribe la salida esperada A MANO:
  Línea 1: Valor: 10
  Línea 2: Valor: 12
  Línea 3: Valor: 16
  Línea 4: Valor: 0*/

#include <iostream>

using namespace std;

  class Contador {
  public:
      int valor;

      void incrementar()      { valor++;      }
      void decrementar()      { valor--;      }
      void incrementarEn(int n){ valor += n;  }
      void reset()            { valor = 0;    }
      void imprimir()         { cout << "Valor: " << valor << endl; }
  };

  int main() {
      Contador c;
      c.valor = 10;
      c.imprimir();
      c.incrementar();
      c.incrementar();
      c.imprimir();
      c.decrementar();
      c.incrementarEn(5);
      c.imprimir();
      c.reset();
      c.imprimir();
      return 0;
  }