/*C049 | Factory — crear objetos sin saber el tipo exacto
Una función "factory" crea y retorna objetos de distintos
tipos derivados según un parámetro, sin que el código
que llama sepa qué tipo concreto recibe.

  Figura* crearFigura(string tipo, double a, double b) {
      if (tipo == "circulo")     return new Circulo(a, "rojo");
      if (tipo == "rectangulo")  return new Rectangulo(a, b, "azul");
      return nullptr;
  }

Implementa la función factory para la jerarquía Figura.
Lee el tipo y dimensiones del teclado.

Entrada:
  circulo 5.0 0
  rectangulo 6.0 4.0
Salida esperada:
  Circulo (r=5.00): Area=78.54
  Rect (6.00x4.00): Area=24.00*/

#include <iostream>
#include <iomanip>
#include <cmath>

class Figura {
    public:
        virtual ~Figura() {}

        virtual double calcularArea() const = 0;

        virtual void imprimir() const = 0;
};

class Circulo : public Figura {
    private:
        double radio;
    public:
        Circulo(double r) : radio(r) {}
        
        double calcularArea() const override {
            return M_PI * radio * radio;
        }

        void imprimir() const override{
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Circulo (r=)" << radio << "): Area=" << calcularArea() << '\n';
        }
};

class Rectangulo : public Figura {
    private:
        double base, altura;
    public:
        Rectangulo(double b, double h) : base(b), altura(h) {}
        
        double calcularArea() const override{
            return base * altura;
        }

        void imprimir() const override{
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Rect (" << base << 'x' << altura << "): Area=" << calcularArea() << '\n';
        }
};

Figura* crearFrigura(const std::string& tipo, double a, double b = 0) {
    if (tipo == "circulo") {
        return new Circulo(a);
    }else if (tipo == "rectangulo") {
        return new Rectangulo(a, b);
    } else {return nullptr;}
}

int main() {
    Figura* arr[2];
    arr[0] = crearFrigura("circulo", 5);
    arr[1]= crearFrigura("rectangulo", 6, 4);

    for (int i = 0; i < 2; i++) {
        if (arr[i] != nullptr) {
            arr[i]->imprimir();
            delete arr[i];
        }
    }

    return 0;
}