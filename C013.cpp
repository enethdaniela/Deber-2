/*C013 | Lista de inicialización — atributo constante
Crea la clase Circulo con:
  const double PI = 3.14159  (constante — DEBE ir en lista)
  double radio

  Constructor: Circulo(double r) : PI(3.14159), radio(r) {}
  Métodos: area(), perimetro(), imprimir()

NOTA: un atributo const SOLO puede inicializarse en la lista
de inicialización. Si intentas asignarlo en el cuerpo del
constructor obtendrás un error de compilación.

Entrada: (hardcodeado: radio = 7.0)
Salida esperada:
  Radio: 7.00
  Area: 153.94
  Perimetro: 43.98*/

#include <iostream>
#include <iomanip>

class Circulo {
  public:
    const double PI;
    double radio;

    Circulo(double r) : PI(3.14159), radio(r) {}

    double area() {
      return PI * radio * radio;
    }

    double perimetro() {
      return 2 * PI * radio;
    }

    void imprimir() {
      std::cout << std::fixed << std::setprecision(2);
      std::cout << "Radio: " << radio << '\n';
      std::cout << "Area: " << area() << '\n';
      std::cout << "Perimetro: " << perimetro() << '\n';
    }
};

int main(){

  Circulo c(7);
  c.imprimir();
    
  return 0;
}