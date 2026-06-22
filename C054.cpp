/*C054 | Sistema de inventario con herencia
Diseña:

  Producto (base abstracta):
    private: codigo, nombre, precio
    virtual string getCategoria() const = 0
    virtual double calcularPrecioFinal() const = 0
      → precio base (puede modificarse en derivadas)
    virtual void imprimir() const

  ProductoFisico : Producto
    private: peso, dimensiones
    calcularPrecioFinal() → precio + costo envío según peso

  ProductoDigital : Producto
    private: tamañoMB, plataforma
    calcularPrecioFinal() → precio * 0.85 (sin costo envío)

  ProductoSuscripcion : Producto
    private: periodoMeses, renovacionAutomatica
    calcularPrecioFinal() → precio * periodoMeses

  Inventario con operaciones CRUD básicas y reporte de valor total.*/

#include <iostream>
#include <iomanip>

class Producto {
    private:
        std::string codigo, nombre;
        double precio;
    public:
        Producto(std::string c, std::string n, double p) : codigo(c), nombre(n), precio(p) {}

        virtual ~Producto() {}

        virtual std::string getCategoria() const = 0;
        virtual double calcularPrecioFinal() const = 0;
        virtual void imprimir() const {
            std::cout << 
        }

        
}