/*C040 | Integración nivel 3 — jerarquía de figuras
Implementa con encapsulamiento completo y herencia:

  Figura (base):
    protected: color (string)
    Constructor(string color)
    virtual double calcularArea() = 0     ← método virtual puro
    virtual double calcularPerimetro() = 0
    virtual void imprimir() const

  Circulo (derivada):
    private: radio (double)
    Constructor(double r, string color)
    calcularArea() override
    calcularPerimetro() override
    void imprimir() const override

  Rectangulo (derivada):
    private: base, altura (double)
    Constructor(double b, double h, string color)
    calcularArea() override
    calcularPerimetro() override
    void imprimir() const override

  Triangulo (derivada):
    private: base, altura (double)
    Constructor(double b, double h, string color)
    calcularArea() override  → b*h/2
    calcularPerimetro() solo si tienes los 3 lados

Crea una figura de cada tipo e imprímelas.

Nota: los métodos "= 0" se explican en el Nivel 4.
Por ahora solo impleméntalos en las hijas.

Salida esperada:
  Circulo rojo | Radio: 5.00 | Area: 78.54 | Perim: 31.42
  Rectangulo azul | 6x4 | Area: 24.00 | Perim: 20.00
  Triangulo verde | Base:3 Altura:4 | Area: 6.00*/


#include <iostream>
#include <iomanip>
#include <cmath>

class Figura {
    protected:
        std::string color;
    public:
        Figura(std::string c) : color(c) {}

        virtual double calcularArea() const = 0;
        virtual double calcularPerimetro() const = 0;
        virtual void imprimir() const {
            std::cout << color;
        }
};

class Circulo : public Figura {
    private:
       double radio;
    public: 
        Circulo(std::string c, double r) : Figura(c), radio(r) {} 

        double calcularArea() const override {
            return M_PI * (radio * radio);
        }
        double calcularPerimetro() const override {
            return 2 * M_PI * radio;
        }
        void imprimir() const override {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Circulo " << color << " | Radio: " << radio << " | Area: " << calcularArea() << " | Perim: " << calcularPerimetro() << '\n';
        }
};

class Rectangulo : public Figura {
    private:
       double base, altura;
    public: 
        Rectangulo(std::string c, double b,double h) : Figura(c), base(b), altura(h) {} 

        double calcularArea() const override {
            return (base  * altura) / 2;
        }
        double calcularPerimetro() const override {
            return 2 * (base * altura);
        }
        void imprimir() const override {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Rectangulo " << color << " | " << base << 'x' << altura << " | Area: " << calcularArea() << " | Perim: " << calcularPerimetro() << '\n';
        }
};

class Triangulo : public Figura {
    private:
       double base, altura;
    public: 
        Triangulo(std::string c, double b,double h) : Figura(c), base(b), altura(h) {} 

        double calcularArea() const override {
            return base  * altura;
        }
        double calcularPerimetro() const override {
            return 3 * base;
        }
        void imprimir() const override {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Triangulo " << color << " | Base: " << base << " Altura: " << altura << " | Area: " << calcularArea() << " | Perim: " << calcularPerimetro() << '\n';
        }
};

int main() {
    Circulo c("rojo", 5);
    Rectangulo r("azul", 6, 4);
    Triangulo t("verde", 3, 4);

    c.imprimir();
    r.imprimir();
    t.imprimir();

    return 0;
}