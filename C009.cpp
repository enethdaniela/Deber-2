/*C009 | Clase con método estático

TEORÍA PREVIA — ¿Qué es un método estático?
Un método estático pertenece a la CLASE, no a una instancia.
No recibe el puntero this — por eso no puede acceder a
atributos de instancia (no sabe de qué objeto hablar).
Se llama con el nombre de la clase, sin crear objeto:

  class MiClase {
  public:
      int atributo;        // pertenece a cada instancia
      static int contador; // pertenece a la CLASE (una sola copia)

      void metodoNormal() {
          atributo++;       // OK: tiene this
      }

      static void metodoEstatico() {
          // atributo++;    ERROR: no tiene this, no sabe qué instancia
          contador++;       // OK: contador es de la clase, no instancia
      }
  };

  MiClase::metodoEstatico();  // sin crear objeto
  MiClase obj;
  obj.metodoEstatico();       // también válido pero menos claro

Crea la clase Matematica con métodos estáticos SOLAMENTE:
  static int maximo(int a, int b)
  static int minimo(int a, int b)
  static bool esPrimo(int n)
  static double potencia(double base, int exp)

En main usa los cuatro métodos sin instanciar la clase.

Entrada: (hardcodeado)
Salida esperada:
  Maximo(8, 3): 8
  Minimo(8, 3): 3
  Es primo 7: SI
  Es primo 9: NO
  2 elevado a 10: 1024.00*/

#include <iostream>
#include <iomanip>
#include <cmath>

class Matematica {
  public:
    static int maximo(int a, int b) {
    return (a > b) ? a : b ; 
    }

    static int minimo(int a, int b) {
      return (a < b) ? a : b;
    }

    static bool esPrimo(int n) {
      if (n <= 1) {
        return false;
      }

      for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
          return false;
        }
      }

      return true;
    }

    static double potencia(double base, int exp) {
      if (exp == 0) {
        return 1;
      } else if (exp > 0) {
        return base * potencia(base, exp - 1);
      } else {
        return 1 / potencia(base, -exp);
      }
  }
};

int main() {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Maximo(8, 3): " << Matematica::maximo(8, 3) << '\n';
  std::cout << "Minimo(8, 3): " << Matematica::minimo(8, 3) << '\n';
  std::cout << "Es primo 7: " << (Matematica::esPrimo(7) ? "SI" : "NO") << '\n';
  std::cout << "Es primo 9: " << (Matematica::esPrimo(9) ? "SI" : "NO") << '\n';
  std::cout << "2 elavado a 10: " << Matematica::potencia(2, 10) << '\n';

  return 0;
}

