/*C042 | Primera clase abstracta
Implementa la jerarquía del ejemplo resuelto completa:
  Figura (abstracta): calcularArea() = 0, calcularPerimetro() = 0,
                      destructor virtual, imprimir()
  Circulo, Rectangulo, Triangulo (concretas)

Crea un arreglo de 5 figuras de tipos mixtos.
Recorre el arreglo llamando imprimir() para cada una.
Al final imprime la suma total de áreas.
Libera toda la memoria correctamente.

Salida esperada:
  [según los valores que elijas — al menos una de cada tipo]
  Area total: [suma correcta]*/

#include <iostream>
  #include <iomanip>
  using namespace std;

  class Figura {
  protected:
      string color;
  public:
      Figura(string c) : color(c) {}
      virtual ~Figura() {}

      virtual double calcularArea()       const = 0;
      virtual double calcularPerimetro()  const = 0;

      virtual void imprimir() const {
          cout << fixed << setprecision(2);
          cout << "Color: " << color
               << " | Area: " << calcularArea()
               << " | Perim: " << calcularPerimetro() << endl;
      }
  };

  class Circulo : public Figura {
  private:
      double radio;
  public:
      Circulo(double r, string c) : Figura(c), radio(r) {}

      double calcularArea()      const override { return 3.14159*radio*radio; }
      double calcularPerimetro() const override { return 2*3.14159*radio;     }

      void imprimir() const override {
          cout << "Circulo (r=" << radio << ") | ";
          Figura::imprimir();
      }
  };

  class Rectangulo : public Figura {
  private:
      double base, altura;
  public:
      Rectangulo(double b, double h, string c)
          : Figura(c), base(b), altura(h) {}

      double calcularArea()      const override { return base * altura;       }
      double calcularPerimetro() const override { return 2*(base + altura);   }

      void imprimir() const override {
          cout << "Rect (" << base << "x" << altura << ") | ";
          Figura::imprimir();
      }
  };

  int main() {
      Figura* figuras[5];
      figuras[0] = new Circulo(5.0, "rojo");
      figuras[1] = new Rectangulo(4.0, 3.0, "azul");
      figuras[2] = new Circulo(2.0, "verde");
      figuras[3] = new Rectangulo(5, 3.0, "amarillo");
      figuras[4] = new Circulo(1, "turquesa");

      double totalArea = 0;
      for (int i = 0; i < 5; i++) {
          figuras[i]->imprimir();
          totalArea += figuras[i]->calcularArea();
      }
      cout << "Area total: " << totalArea << endl;

      for (int i = 0; i < 5; i++) {
          delete figuras[i];
          figuras[i] = nullptr;
      }
      return 0;
  }
