/*C028 | Integración nivel 2 — clase Inventario item
Crea la clase ItemInventario con encapsulamiento completo:
  private: string codigo, string nombre, int cantidad, double precio

  Constructor con validación (cantidad >= 0, precio >= 0)
  Getters para todos los atributos (const)
  Setters con validación para cantidad y precio
  Métodos:
    double valorTotal() const → cantidad * precio
    void vender(int n) → resta n de cantidad, valida stock
    void reabastecer(int n) → suma n a cantidad
    void imprimir() const

Simula operaciones de inventario en main.

Salida esperada:
  [A001] Laptop | Cant: 10 | Precio: $1200.00 | Total: $12000.00
  Venta de 3 unidades. Quedan: 7
  Stock insuficiente. Solo hay 7 unidades.
  Reabastecido: +20 unidades. Total: 27
  [A001] Laptop | Cant: 27 | Precio: $1200.00 | Total: $32400.00*/

#include <iostream>
#include <iomanip>

class ItemnInventario {
    private:
        std::string codigo, nombre;
        int cantidad;
        double precio;
    public:
        ItemnInventario(std::string cod, std::string n, int cant, double p) : codigo(cod), nombre(n) {
            setCantidad(cant);
            setPrecio(p);
        }

        std::string getCodigo() const { return codigo; }
        std::string getNombre() const { return nombre; }
        int getCantidad() const { return cantidad; }
        double getPrecio() const {return precio; }

        void setCantidad(int cant) {
            cantidad = (cant >= 0) ? cant : 0;
        }
        void setPrecio(double p) {
            precio = (p >= 0) ? p : 0;
        }

        double valorTotal() const {
            return cantidad * precio;
        }
        void vender(int n) {
            if (n <= cantidad) {
                cantidad -= n;
                std::cout << "Venta de " << n << " unidades. Quedan: " << cantidad << '\n';
            } else {
                std::cout << "Stock insuficiente. Solo hay " << cantidad << " unidades\n";
            }  
        }
        void reabastecer(int n) {
            cantidad += n;
            std::cout << "Reabastecido: +" << n << " unidades. Total: " << cantidad << '\n';
        }
        void imprimir() const {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << codigo << ' ' << nombre << " | Cant: " << cantidad << " | Precio: $" << precio << " | Total: $" << valorTotal() << '\n';

        }
};

int main() {
    ItemnInventario i1("[A001]", "Laptop", 10, 1200);

    i1.imprimir();
    i1.vender(3);
    i1.vender(8);
    i1.reabastecer(20);
    i1.imprimir();

}
