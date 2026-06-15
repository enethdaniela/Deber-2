/*C016 | Sobrecarga de constructores
Crea la clase Fecha con atributos:
  int dia, mes, anio

Implementa 3 constructores:
  Fecha()                     → inicializa en 1/1/2000
  Fecha(int d, int m, int a)  → inicializa con los valores dados
  Fecha(int d, int m)         → dia y mes dados, anio = 2024

Método: void imprimir() → imprime DD/MM/AAAA

Demuestra los tres constructores en main.

Salida esperada:
  01/01/2000
  15/06/1999
  22/03/2024*/

#include <iostream>

class Fecha {
  public:
    int dia, mes, anio;

    Fecha(): dia(01), mes(01), anio(2000) {}
    Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}
    Fecha(int d, int m) : dia(d), mes(m), anio(2024) {}

    void imprimir() {
      std::cout << dia << '/' << mes << '/' << anio << '\n';
    }
};

int main() {
  Fecha f1;
  Fecha f2(15, 06, 1999);
  Fecha f3(22, 03);

  f1.imprimir();
  f2.imprimir();
  f3.imprimir();

  return 0;
}
