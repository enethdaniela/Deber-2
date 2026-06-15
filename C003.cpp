/*C003 | Método que usa otros métodos
Crea la clase Triangulo con:
  Atributos public: lado1, lado2, lado3 (double)
  Métodos:
    double calcularPerimetro()
    double calcularArea()  → usa la fórmula de Herón:
      s = (lado1+lado2+lado3)/2
      area = sqrt(s*(s-lado1)*(s-lado2)*(s-lado3))
      Requiere: #include <cmath>
    bool esEquilatero()    → true si los tres lados son iguales
    bool esRectangulo()    → true si cumple el teorema de Pitágoras
                             con cierta tolerancia (usa el lado mayor)
    void imprimir()        → llama a los otros métodos

Entrada: (hardcodeado: 3.0, 4.0, 5.0)
Salida esperada:
  Lados: 3.00, 4.00, 5.00
  Perimetro: 12.00
  Area: 6.00
  Equilatero: NO
  Rectangulo: SI*/

#include <iostream>
#include <cmath>
#include <iomanip>

class Triangulo {
  public:
    double lado1, lado2, lado3;

    double calcularPerimetro() {
      return lado1 + lado2 + lado3;
    }
    double calcularArea() {
      double s = calcularPerimetro() / 2;
      return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3)); 
    }

    bool esEquilatero() {
      return lado1 == lado2 == lado3;
    }

    bool esRectangulo() {
      double cateto1, cateto2, hipotenusa;

      if (lado1 >= lado2 && lado1 >= lado3) {
        hipotenusa = lado1;
        cateto1 = lado2;
        cateto2 = lado3;
      } else if (lado2 >= lado1 && lado2 >= lado3) {
        hipotenusa = lado2;
        cateto1 = lado1;
        cateto2 = lado3;
      } else {
        hipotenusa = lado3;
        cateto1 =  lado1;
        cateto2 = lado2;
      }

      double diferencia = std::abs((hipotenusa * hipotenusa) - ((cateto1 * cateto1) + (cateto2 * cateto2)));

      return diferencia < 0.001;
    }

    void imprimir() {
      std::cout << std::fixed << std::setprecision(2);
      std::cout << "Lados: " << lado1 << ", " << lado2 << ", " << lado3 << '\n';
      std::cout << "Perimetro: " << calcularPerimetro() << '\n';
      std::cout << "Area: " << calcularArea() << '\n';
      std::cout << "Equilatero: " << (esEquilatero() ? "SI" : "NO") << '\n';
      std::cout << "Rectangulo: " << (esRectangulo() ? "SI" : "NO") << '\n';
    }
};

int main() {
  Triangulo t1;
  t1.lado1 = 3.00;
  t1.lado2 = 4.0;
  t1.lado3 = 5.0;
  t1.imprimir();

  return 0;
}



