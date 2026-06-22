/*C050 | Integración nivel 4 — sistema de vehículos
Implementa con polimorfismo completo:

  Vehiculo (abstracta):
    protected: marca, modelo, anio
    Constructor, getters, destructor virtual
    virtual double calcularCosto() const = 0
    virtual string getTipo()       const = 0
    void imprimir() const → marca + modelo + tipo + costo

  Auto   → costo = precio base + (anio > 2020 ? 10% extra : 0)
  Moto   → costo = precio base * 0.7 (20% menos que auto)
  Camion → costo = precio base * 2.5 (más caro por porte)

Crea un arreglo de 6 vehículos mixtos.
Ordénalos por costo de mayor a menor (bubble sort con punteros).
Imprímelos en orden.
Libera la memoria.

Salida esperada:
  [lista ordenada de mayor a menor costo con tipo y datos]
  Costo total de flota: $[suma]*/

#include <iostream>
#include <iomanip>

class Vehiculo {
    protected:
        std::string marca, modelo;
        int anio;
        double precioBase;
    public:
        Vehiculo(const std::string& m, const std::string& mod, int a, double pb) : marca(m), modelo(mod), anio(a), precioBase(pb) {}

        virtual ~Vehiculo() {}

        std::string getMarca() const { return marca; }
        std::string getModelo() const { return modelo; }
        int getAnio() const { return anio; }

        virtual std::string getTipo() const = 0;

        virtual double calcularCosto() const = 0;

         virtual void imprimir() const {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << getMarca() << " | " << getModelo() << " | " << getTipo() << " | $" << calcularCosto() << '\n';
        }
};

class Auto : public Vehiculo {
    public:
        Auto(const std::string& m, const std::string& mod, int a, double pb) : Vehiculo(m, mod, a, pb) {}

        std::string getTipo() const override { return "Auto"; }

        double calcularCosto() const override {
            return (anio > 2020) ? (precioBase * 1.1) : precioBase;
        }
};

class Moto : public Vehiculo {
    public:
        Moto(const std::string& m, const std::string& mod, int a, double pb) : Vehiculo(m, mod, a, pb) {}

        std::string getTipo() const override { return "Moto"; }

        double calcularCosto() const override {
            return precioBase * 0.7;
        }
};

class Camion : public Vehiculo {
    public:
        Camion(const std::string& m, const std::string& mod, int a, double pb) : Vehiculo(m, mod, a, pb) {}

        std::string getTipo() const override { return "Camion"; }

        double calcularCosto() const override {
            return precioBase * 2.5;
        }
};

int main() {
    const int TAMANIO = 6;
    double costoTotal = 0;
    Vehiculo* flota[TAMANIO];

    flota[0] = new Auto("Toyota", "Corolla", 2022, 20000);
    flota[1] = new Moto("Yamaha", "MT-07", 2019, 8000);
    flota[2] = new Camion("Volvo", "FH16", 2021, 50000);
    flota[3] = new Auto("Honda", "Civic", 2023, 22000);
    flota[4] = new Moto("Ducati", "Panigale", 2023, 22000);
    flota[5] = new Camion("Scania", "R500", 2017, 45000);

    for (int i = 0; i < TAMANIO - 1; i++) {
        for (int j = 0; j < TAMANIO - i - 1; j++) {
            if (flota[j]->calcularCosto() < flota[j + 1]->calcularCosto()) {
                Vehiculo* temp = flota[j];
                flota[j] = flota[j + 1];
                flota[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < TAMANIO; i++) {
        flota[i]->imprimir();
        costoTotal += flota[i]->calcularCosto();
        delete flota[i];
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Costo Total de la flota: $" << costoTotal << '\n';
    
    return 0;
}