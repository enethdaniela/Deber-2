/*C052 | Sistema de figuras con área total y promedio
Implementa la jerarquía completa de figuras (Circulo,
Rectangulo, Triangulo, Cuadrado, Rombo).

Crea una clase Lienzo:
  private: Figura* figuras[50], int cantidad
  void agregar(Figura* f)
  double areaTotalCanvas() const
  double areaPromedio() const
  Figura* figuraMayor() const   → puntero a la de mayor área
  Figura* figurasMenor() const  → puntero a la de menor área
  void imprimirTodas() const
  ~Lienzo() → libera memoria

En main crea un lienzo con al menos 8 figuras de tipos mixtos.*/

#include <iostream>
#include <iomanip>
#include <cmath>

class Figura {
    public:
        virtual ~Figura() {}

        virtual std::string getTipo() const = 0;
        virtual double calcularArea() const = 0;

        virtual void imprimir() const {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << getTipo() << " | Area: " << calcularArea() << '\n';
        };
};

class Circulo : public Figura {
    private:
        double radio;
    public:
        Circulo(double r) : radio(r) {}
        
        std::string getTipo() const override { return "Circulo"; }

        double calcularArea() const override {
            return M_PI * radio * radio;
        }
};

class Rectangulo : public Figura {
    private:
        double base, altura;
    public:
        Rectangulo(double b, double h) : base(b), altura(h) {}
        
        std::string getTipo() const override { return "Rectangulo"; }

        double calcularArea() const override {
            return base * altura;
        }
};

class Triangulo : public Figura {
    private:
        double base, altura;
    public:
        Triangulo(double b, double h) : base(b), altura(h) {}
        
        std::string getTipo() const override { return "Triangulo"; }

        double calcularArea() const override {
            return (base * altura) / 2;
        }
};

class Cuadrado : public Figura {
    private:
        double lado;
    public:
        Cuadrado(double l) : lado(l) {}
        
        std::string getTipo() const override { return "Cuadrado"; }

        double calcularArea() const override {
            return lado * lado;
        }
};

class Rombo : public Figura {
    private:
        double diagonal1, diagonal2;
    public:
        Rombo(double d1, double d2) : diagonal1(d1), diagonal2(d2) {}
        
        std::string getTipo() const override { return "Rombo"; }

        double calcularArea() const override {
            return (diagonal1 * diagonal2) / 2;
        }
};

class Lienzo {
    private:
        Figura* figuras[50];
        int cantidad;
    public:
        Lienzo() : cantidad(0) {
            for (int i = 0; i < 50; i++) {
                figuras[i] = nullptr;
            }   
        }

        ~Lienzo() {
            for (int i = 0; i < cantidad; i++) {
                delete figuras[i];
            }  
        }

        void agregar(Figura* m) {
            if (cantidad < 50) {
                figuras[cantidad] = m;
                cantidad++;
            } else {
                std::cout << "Lleno\n"; 
                delete m;
            }
        }

        double areaTotalCanvas() const {
            double areaTotal = 0;
            for (int i = 0; i < cantidad; i++) {
                areaTotal += figuras[i]->calcularArea();
            }
            return areaTotal;
        }

        double areaPromedio() const {
            if (cantidad == 0) return 0;
            return areaTotalCanvas() / cantidad;
        }

        Figura* figuraMayor() const {
            Figura* mayor = figuras[0];
            for (int i = 1; i < cantidad; i++) {
                if (figuras[i]->calcularArea() > mayor->calcularArea()) {
                    mayor = figuras[i];
                }
            }
            return mayor;
        }

        Figura* figuraMenor() const {
            Figura* menor = figuras[0];
            for (int i = 1; i < cantidad; i++) {
                if (figuras[i]->calcularArea() < menor->calcularArea()) {
                    menor = figuras[i];
                }
            }
            return menor;
        }

        void imprimirTodas() const {
            for (int i = 0; i < cantidad; i++) {
                figuras[i]->imprimir();
            }
        }
};

int main() {
    Lienzo lienzo;

    lienzo.agregar(new Circulo(3.5));        
    lienzo.agregar(new Rectangulo(4.0, 5.5)); 
    lienzo.agregar(new Triangulo(6.0, 3.0));  
    lienzo.agregar(new Cuadrado(2.5));        
    lienzo.agregar(new Rombo(8.0, 4.0));      
    lienzo.agregar(new Circulo(1.2));         //menor
    lienzo.agregar(new Cuadrado(7.0));        // mayor
    lienzo.agregar(new Rectangulo(2.0, 8.0));

    std::cout << "=== FIGURAS EN EL LIENZO ===\n";
    lienzo.imprimirTodas();
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area Total del Canvas: " << lienzo.areaTotalCanvas() << '\n';
    std::cout << "Area Promedio: " << lienzo.areaPromedio() << '\n';
   
    Figura* mayor = lienzo.figuraMayor();
    Figura* menor = lienzo.figuraMenor();

    if (mayor != nullptr && menor != nullptr) {
        std::cout << "Figura con MAYOR area: ";
        mayor->imprimir();
        
        std::cout << "Figura con MENOR area: ";
        menor->imprimir();
    }

    return 0;
}
