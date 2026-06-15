/*C017 | Constructor con objeto como parámetro
Crea la clase Segmento que use la clase Punto.
Incluye la clase Punto en el mismo archivo:

  class Punto {
  public:
      double x, y;
      Punto(double a, double b) : x(a), y(b) {}
      void imprimir() const {
          cout << fixed << setprecision(2);
          cout << "(" << x << ", " << y << ")";
      }
      double distanciaA(Punto otro) const {
          return sqrt((x-otro.x)*(x-otro.x)+(y-otro.y)*(y-otro.y));
      }
  };

Crea la clase Segmento con:
  Punto inicio, Punto fin
  Constructor: Segmento(Punto p1, Punto p2) : inicio(p1), fin(p2) {}
  double longitud() → distancia entre inicio y fin
  void imprimir()

Entrada: (hardcodeado: Punto(0,0) a Punto(3,4))
Salida esperada:
  Inicio: (0.00, 0.00)
  Fin   : (3.00, 4.00)
  Longitud: 5.00*/

#include <iostream>
#include <iomanip>
#include <cmath>

  class Punto {
  public:
      double x, y;
      Punto(double a, double b) : x(a), y(b) {}
      void imprimir() const {
          std::cout << std::fixed << std::setprecision(2);
          std::cout << "(" << x << ", " << y << ")";
      }
      double distanciaA(Punto otro) const {
          return sqrt((x-otro.x)*(x-otro.x)+(y-otro.y)*(y-otro.y));
      }
  };

  class Segmento {
    public:
        Punto inicio, fin;

        Segmento(Punto p1, Punto p2) : inicio(p1), fin(p2) {}

        double longitud() {
            return inicio.distanciaA(fin);
     }

     void imprimir() {
           std::cout << std::fixed << std::setprecision(2);
           std::cout << "Inicio: (" << inicio.x << ", " << inicio.y << ")\n";
           std::cout << "Fin: (" << fin.x << ", " << fin.y << ")\n";
           std::cout << "Longitud: " << longitud() << '\n'; 
     }
  };

int main() {
    Punto p1(0, 0);
    Punto p2(3,4);
    Segmento seg(p1, p2);
    seg.imprimir();

    return 0;
}