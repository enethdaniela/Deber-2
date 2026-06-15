/*C018 | Integración nivel 1 — clase Producto
Crea la clase Producto con:
  string nombre
  double precio
  int    stock

Constructores:
  Producto(string n, double p, int s) con validación:
    precio >= 0, si no: precio = 0
    stock  >= 0, si no: stock  = 0
  Producto(string n, double p) : stock en 0

Destructor: imprime "Producto [nombre] eliminado del sistema."

Métodos:
  void vender(int cantidad)
    → si hay stock: stock -= cantidad, imprime "Venta exitosa"
    → si no: imprime "Stock insuficiente"
  void reabastecer(int cantidad) → stock += cantidad
  void imprimir() const

Simula compra y venta en main.

Salida esperada:
  Laptop | $1200.00 | Stock: 5
  Venta exitosa. Stock restante: 3
  Stock insuficiente.
  Reabastecer: 10 unidades. Stock: 13
  Laptop | $1200.00 | Stock: 13
  Producto Laptop eliminado del sistema.*/

#include <iostream>
#include <iomanip>

class Producto {
    public:
        std::string nombre;
        double precio;
        int stock;

        Producto(std::string n, double p, int s) : nombre(n) {
            precio = (p >= 0) ? p : 0;
            stock = (s >= 0) ? s : 0;
        }

        Producto(std::string n, double p) : nombre(n), precio(p), stock(0) {}

        ~Producto() {
            std::cout << "Producto " << nombre << " eliminado del sistema.\n";
        }

        void vender(int cantidad) {
            if(cantidad <= stock) {
                stock -= cantidad;
                std::cout << "Venta exitosa. Stock restante: " << stock << '\n';
            } else {
                std::cout << "Stock insuficiente.\n";
            }
        }

        void reabastecer(int cantidad) {
            stock += cantidad;
            std::cout << "Reabastecer: " << cantidad << " unidades. Stock: " << stock << '\n';
        }

        void imprimir() const {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << nombre << " | $" << precio << " | " << "Stock: " << stock << '\n';
        }
};

int main() {
    Producto p1("Laptop", 1200, 5);
    p1.imprimir();
    p1.vender(2);
    p1.vender(4);
    p1.reabastecer(10);
    p1.imprimir();

    return 0;
}