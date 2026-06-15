/*C027 | Constructor copia básico
C++ genera automáticamente un CONSTRUCTOR COPIA que copia
todos los atributos. Se invoca así:
  Clase copia = original;   o   Clase copia(original);

  class Punto {
  private:
      double x, y;
  public:
      Punto(double a, double b) : x(a), y(b) {}
      // C++ genera automáticamente:
      // Punto(const Punto& otro) : x(otro.x), y(otro.y) {}
  };

  Punto p1(3.0, 4.0);
  Punto p2 = p1;   // copia — p2 es independiente de p1

Crea la clase Vector2D con x, y privados.
Copia un vector, modifica la copia y verifica que el original
no cambió.

Salida esperada:
  Original: (3.00, 4.00)
  Copia:    (3.00, 4.00)
  [modificar copia a (10, 20)]
  Original: (3.00, 4.00)   ← no cambió
  Copia:    (10.00, 20.00) ← sí cambió*/

#include <iostream>
#include <iomanip>

class Vector2D {
    private: 
        double x, y;
    public:
        Vector2D(double a, double b) : x(a), y(b) {
        }

        void setX(double a) {
            x = a;
        }

        void setY(double b) {
            y = b;
        }

        void imprimir() {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "(" << x << ", " << y << ")\n";
        }
};

int main() {
    Vector2D p1(3, 4);
    Vector2D p2 = p1;

    std::cout << "Original: ";
    p1.imprimir();
    std::cout << "Copia: ";
    p2.imprimir();
    p2.setX(10);
    p2.setY(20);
    std::cout << "Original: ";
    p1.imprimir();
    std::cout << "Copia: ";
    p2.imprimir();

}