/*C001 | Clase básica con atributos y métodos
Crea la clase Circulo con:
  Atributos public: radio (double)
  Métodos:
    double calcularArea()      → PI * radio * radio  (PI = 3.14159)
    double calcularPerimetro() → 2 * PI * radio
    void imprimir()            → imprime radio, área y perímetro

En main crea dos círculos con radios distintos e imprímelos.

Entrada: (ninguna — radios hardcodeados: 5.0 y 3.0)
Salida esperada:
  Radio: 5.00
  Area: 78.54
  Perimetro: 31.42
  Radio: 3.00
  Area: 28.27
  Perimetro: 18.85*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

class Circulo {
    public:
    // atributos
    double radio;
    
    //metodos
    double calcularArea() {
        return M_PI * radio * radio;
    }

    double calcularPerimetro() {
        return 2 * M_PI * radio;
    }

    void imprimir() {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Radio: " << radio << '\n';
        std::cout << "Area: " << calcularArea() << '\n';
        std::cout << "Perimetro: " << calcularPerimetro() << '\n';
    }
};

int main() {
    Circulo c1;
    c1.radio = 5.00;
    c1.imprimir();

    Circulo c2;
    c2.radio = 3.00;
    c2.imprimir();

    return 0;
}