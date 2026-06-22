/*C046 | Polimorfismo con referencia (no solo puntero)
El polimorfismo también funciona con referencias:
  Animal& ref = perro;  // referencia a base apuntando a derivada
  ref.hacerSonido();    // despacho dinámico con referencia

Implementa una función:
  void describir(const Figura& f)
  → llama f.imprimir() y f.calcularArea()

Pásale figuras de distintos tipos y observa el despacho.

Entrada: (hardcodeado)
Salida esperada:
  [descripción de cada figura según su tipo real]*/


#include <iostream>
#include <iomanip>
#include <cmath>

class Figura {
    public:
        virtual std::string getTipo() const = 0;
        virtual double calcularArea() const = 0;

        virtual void imprimir () const {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Tipo de figura: " << getTipo() << " | Area: " << calcularArea() << '\n';
        }
};

class Circulo : public Figura {
    private:
        double radio;
    public:
        Circulo(double r) : radio(r) {}

        double calcularArea() const override {
            return M_PI * radio * radio;
        }
        std::string getTipo() const override {
            return "Circulo";
        }
};

class Rectangulo : public Figura {
    private:
        double base;
        double altura;
    public:
        Rectangulo(double b, double h) : base(b), altura(h) {}

        double calcularArea() const override {
            return base * altura;
        }
        std::string getTipo() const override {
            return "Rectangulo";
        }
};

void describir(const Figura& f) {
    f.imprimir();
}

int main() {
    Circulo c(5.0);
    Rectangulo r(4.0, 6.0);

    describir(c); 
    describir(r);

    return 0;
}