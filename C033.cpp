/*C033 | Llamar al método del padre con ::
Cuando la hija sobrescribe un método, puede llamar la versión
del padre usando: ClasePadre::metodo()

  class Vehiculo {
  public:
      void imprimir() const {
          cout << "Vehiculo: " << marca << endl;
      }
  };

  class Auto : public Vehiculo {
  public:
      void imprimir() const override {
          Vehiculo::imprimir();   // llama la versión del padre
          cout << "Auto: " << puertas << " puertas" << endl;
      }
  };

Implementa la jerarquía Figura → Rectangulo → Cuadrado donde:
  Figura::imprimir()    → imprime "Figura: [area]"
  Rectangulo::imprimir()→ llama Figura::imprimir()
                          + imprime "Base:[b] Altura:[h]"
  Cuadrado::imprimir()  → llama Rectangulo::imprimir()
                          + imprime "Lado:[l]"

Salida esperada:
  Figura: 25.00
  Base: 5.00 Altura: 5.00
  Lado: 5.00*/

#include <iostream>
#include <iomanip>

class Figura {
    protected:
        double area;
    public:
        Figura(double a) : area(a) {}

        virtual void imprimir() const {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Figura: " << area << '\n';
        }
};

class Rectangulo : public Figura {
    private:
        double base, altura;
    public:
        Rectangulo(double b, double h) : Figura(b * h), base(b), altura(h) {}

        void imprimir() const override {
            Figura::imprimir();
            std::cout << "Base: " << base << " Altura: " << altura << '\n';
        }
};

class Cuadrado : public Rectangulo {
    private:
        double lado;
    public:
        Cuadrado(double l) : Rectangulo(l, l), lado(l) {}

        void imprimir() const override {
            Rectangulo::imprimir();
            std::cout << "Lado: " << lado << '\n';
        }
};

int main() {
    Cuadrado c(5);
    c.imprimir();

    return 0;
}