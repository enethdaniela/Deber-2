/*C011 | Constructor con parámetros
Escribe la clase Rectangulo COMPLETA (no solo el constructor)
con atributos public: base (double), altura (double).
Agrega el constructor:
  Rectangulo(double b, double h) : base(b), altura(h) {}

Y los métodos: calcularArea(), calcularPerimetro(), imprimir()

Crea dos rectángulos en una sola línea cada uno:
  Rectangulo r1(6.0, 4.0);    // sin asignar atributos manualmente
  Rectangulo r2(10.0, 2.5);

Entrada: (hardcodeado)
Salida esperada:
  Base: 6.00, Altura: 4.00
  Area: 24.00
  Perimetro: 20.00
  Base: 10.00, Altura: 2.50
  Area: 25.00
  Perimetro: 25.00*/

#include <iostream>
#include <iomanip>

class Rectangulo {
    public:
    double base, altura;

    //constructor
    Rectangulo(double b, double h) : base(b), altura(h) {}

    //metodos
    double calcularArea() {
        return base * altura;
    }

    double caluclarPerimetro(){
        return (2 * base) + (2 * altura);
    }

    void imprimir(){
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Base: " << base << ", Altura: " << altura << '\n';
        std::cout << "Area: " << calcularArea() << '\n';
        std::cout << "Perimetro: " << caluclarPerimetro() << '\n';
    }
};

int main() {
    Rectangulo r1(6, 4);
    r1.imprimir();
    Rectangulo r2(10, 2.5);
    r2.imprimir();

    return 0;
}