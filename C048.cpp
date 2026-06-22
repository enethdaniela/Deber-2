/*C048 | Clase abstracta con método no puro
Una clase abstracta puede tener métodos con implementación
(no puros). Las hijas pueden sobrescribirlos o usarlos tal cual.

  class Forma {
  public:
      virtual double area() const = 0;   // puro: obliga a implementar
      void imprimir() const {            // no puro: implementación default
          cout << "Area: " << area() << endl;
      }
  };

Implementa la jerarquía:
  Forma (abstracta): area() = 0, imprimir() ya implementado
  Cuadrado → area = lado^2
  Rombo    → area = (d1 * d2) / 2
  Pentagono→ area = (perimetro * apotema) / 2

Crea un arreglo y llama imprimir() para cada figura.
Nota que imprimir() se hereda sin cambios — polimorfismo
llama la versión correcta de area() desde imprimir().

Salida esperada:
  Area: 25.00
  Area: 24.00
  Area: 34.41*/

#include <iostream>
#include <iomanip>

class Forma {
    public:
        virtual ~Forma() {}
        virtual double area() const = 0;
        void imprimir() const {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Area: " << area() << std::endl;
        }
}; 

class Cuadrado : public Forma {
    private:
        double lado;
    public:
        Cuadrado(double l) : lado(l) {}

        double area() const {
            return lado * lado;
        }
};

class Rombo : public Forma {
    private:
        double d1, d2;
    public:
        Rombo(double x1, double x2) : d1(x1), d2(x2) {}

        double area() const {
            return (d1 * d2) / 2;
        }
};

class Pentagono : public Forma {
    private:
        double perimetro, apotema;
    public:
        Pentagono(double p, double a) : perimetro(p), apotema(a) {}

        double area() const {
            return (perimetro * apotema) / 2;
        }
};

int main() {
    Forma* arr[3];

    arr[0] = new Cuadrado(5);
    arr[1] = new Rombo(6, 8);
    arr[2] = new Pentagono(9, 7.64);

    for (int i = 0; i < 3; i++) {
        arr[i]->imprimir();
    }

    for (int i = 0; i < 3; i++) {
        delete arr[i];
    }
}
