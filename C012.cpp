/*C012 | Constructor por defecto + constructor con parámetros
Crea la clase Punto3D con atributos x, y, z (double).
Implementa dos constructores:
  Punto3D()              → inicializa en (0, 0, 0)
  Punto3D(double x, double y, double z)

Método: void imprimir()  → imprime (x, y, z)

Crea 3 objetos: uno con el constructor por defecto, dos con
coordenadas específicas.

Entrada: (ninguna)
Salida esperada:
  (0.00, 0.00, 0.00)
  (3.00, 1.00, 4.00)
  (1.00, 5.00, 9.00)*/

#include <iostream>
#include <iomanip>

class Punto3D {
    public:
    double x, y, z;

    //constructores
    Punto3D() : x(0), y(0), z(0) {}
    Punto3D(double a, double b, double c) : x(a), y(b), z(c) {}

    void imprimir() {
      std::cout << std::fixed << std::setprecision(2);
      std::cout << '(' << x << ", " << y << ", " << z << ")\n";    
    }
};

int main() {
    Punto3D p1;
    p1.imprimir();
    Punto3D p2(3, 1, 4);
    p2.imprimir();
    Punto3D p3(1, 5, 9);
    p3.imprimir();

    return 0;
}