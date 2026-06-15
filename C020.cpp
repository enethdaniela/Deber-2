/*C020 | this explícito
Crea la clase Rectangulo con atributos private: base, altura.
En el setter usa this explícitamente porque el parámetro
tiene el mismo nombre que el atributo:

  void setBase(double base) {
      if (base > 0) this->base = base;
      else cout << "Base debe ser positiva." << endl;
  }

Implementa ambos setters con this explícito, getters const,
constructor y método imprimir.

Salida esperada:
  Base: 5.00, Altura: 3.00, Area: 15.00
  Base debe ser positiva.
  Base: 5.00, Altura: 3.00, Area: 15.00
  Base: 8.00, Altura: 3.00, Area: 24.00*/

#include <iostream>
#include <iomanip>

class Rectangulo {
    private: 
        double base, altura;
    public:
        //constructor
        Rectangulo(double base, double altura) {
            this->base = 0;
            this->altura = 0;
            setBase(base);
            setAltura(altura);
        }  

        //setters
        void setBase(double base) {
            if (base > 0) {
                this->base = base;
            } else {
                std::cout<< "Base debe ser positva.\n";
            }
        }

        void setAltura(double altura) {
            if ( altura > 0) {
                this->altura = altura;
            } else {
                std::cout << "Altura debe sert positiva.\n";
            }
        }

        //getters
        double getBase() const {return base;}
        double getAltura() const {return altura;}

        //metodos
        double calcularArea() {
            return base * altura;
        }

        void imprimir() {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Base: " << base << ", Altura: " << altura << ", Area: " << calcularArea() << '\n';
        }
};

int main() {
    Rectangulo rec1(5, 3);
    rec1.imprimir();
    rec1.setBase(-3);
    rec1.imprimir();
    rec1.setBase(8);
    rec1.imprimir();

    return 0;
}