/*C006 | Método que recibe objeto como parámetro
Crea la clase Punto con:
  Atributos public: x, y (double)
  Métodos:
    void imprimir()
    double distanciaA(Punto otro)
      → sqrt((x-otro.x)^2 + (y-otro.y)^2)
    Punto puntoMedio(Punto otro)
      → retorna un Punto con ((x+otro.x)/2, (y+otro.y)/2)

En main crea dos puntos y calcula distancia y punto medio.

Entrada: (hardcodeado: P1(3,4) y P2(7,1))
Salida esperada:
  P1: (3.00, 4.00)
  P2: (7.00, 1.00)
  Distancia: 5.00
  Punto medio: (5.00, 2.50)*/

#include <iostream>
#include <cmath>
#include <iomanip>

class Punto {
  public:
    double x, y;

    void imprimir() {
      std::cout << "(" << std::fixed << std::setprecision(2) << x << ", " << y << ")" << '\n';
    }

    double distanciaA(Punto otro) {
      double dx = x - otro.x;
      double dy = y - otro.y;
      return sqrt((dx * dx) + (dy * dy));
    }

    Punto puntoMedio(Punto otro) {
      Punto medio;
      medio.x = (x + otro.x) / 2;
      medio.y = (y + otro.y) / 2;
      return medio;
    }
};

int main() {
  Punto p1;
  p1.x = 3;
  p1.y = 4;


  Punto p2;
  p2.x = 7;
  p2.y = 1;

  std::cout << "P1: "; 
  p1.imprimir();
  std::cout << "P2: "; 
  p2.imprimir();
  double dist = p1.distanciaA(p2);
  std::cout << "Distancia: " << std::fixed <<std::setprecision(2) << dist << '\n';
  Punto pm = p1.puntoMedio(p2);
  std::cout << "Punto medio: ";
  pm.imprimir();

  return 0;
}