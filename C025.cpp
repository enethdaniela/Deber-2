/*C025 | Clase con atributo calculado
Crea la clase Triangulo con:
  private: double base, altura, hipotenusa

  Constructor que calcula la hipotenusa automáticamente:
    Triangulo(double b, double h) : base(b), altura(h) {
        hipotenusa = sqrt(base*base + altura*altura);
    }

  Getters para los tres atributos (const)
  Sin setter para hipotenusa (es calculada, no se asigna)
  Método imprimir() const

Esto enseña que no todo atributo privado necesita setter.

Entrada: (hardcodeado: base=3, altura=4)
Salida esperada:
  Base     : 3.00
  Altura   : 4.00
  Hipotenusa: 5.00*/

#include <iostream>
#include <cmath>
#include <iomanip>

class Triangulo {
    private:
        double base, altura, hipotenusa;
    public:
        //asumo que para ese ejercicio no se requiere hacer la validacion de base y altura
        Triangulo(double b, double h) : base(b), altura(h) {
            hipotenusa = sqrt(base * base + altura * altura);
        }
        
        double getBase() const { return base; }
        double getAltura() const { return altura; }
        double getHipotenusa() const {return hipotenusa; }

        void setBase(double b) {
            base = b;
            hipotenusa = sqrt(base * base + altura * altura);
        }

        void setAltura(double h) {
            altura = h;
            hipotenusa = sqrt(base * base + altura * altura);
        }
         
        void imprimir() {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Base: " << base << '\n';
            std::cout << "Altura: " << altura << '\n';
            std::cout << "Hipotenusa: " << hipotenusa << '\n';
        }
};

int main() {
    Triangulo t(3, 4);
    t.imprimir();

    return 0;
}