/*C045 | Clase abstracta — Empleado
Implementa la jerarquía de empleados con clase abstracta:

  Empleado (abstracta):
    protected: nombre, salario
    Constructor, getters, destructor virtual
    virtual double calcularBono() const = 0   ← puro
    virtual string getTipo()      const = 0   ← puro
    void imprimir() const → nombre + tipo + salario + bono

  Programador  → bono = 10%, getTipo() = "Programador"
  Gerente      → bono = 20%, getTipo() = "Gerente"
  Director     → bono = 30%, getTipo() = "Director"

Crea un arreglo de 4 punteros Empleado* con tipos mixtos.
Imprime cada uno y al final el total de bonos.
Libera la memoria.

Salida esperada:
  Ana | Programador | $3000.00 | Bono: $300.00
  Luis | Gerente    | $5000.00 | Bono: $1000.00
  Carla | Director  | $8000.00 | Bono: $2400.00
  Pedro | Programador| $2800.00 | Bono: $280.00
  Total bonos: $3980.00*/

#include  <iostream>
#include  <iomanip>

class  Empleado {
    protected:
        std::string nombre;
        double salario;
    public:
        Empleado(const std::string& n, double s) : nombre(n), salario(s) {}

        std::string getNombre() const { return nombre; }
        double getSalario() const { return salario; }
        
        virtual double calcularBono() const = 0;

        virtual std::string getTipo() const = 0;

        void imprimir() const {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << nombre << " | " << getTipo() << " | $" << getSalario() << " | Bono: $" << calcularBono() << '\n';
        }
        
        virtual ~Empleado() {}
};

class Programador : public Empleado{
    public:
        Programador(const std::string& n, double s) : Empleado(n, s) {}

        double calcularBono() const override {
            return salario * 0.1;
        }

        std::string getTipo() const override {
            return "Programador";
        }
};

class Gerente : public Empleado{
    public:
        Gerente(const std::string& n, double s) : Empleado(n, s) {}

        double calcularBono() const override {
            return salario * 0.2;
        }

        std::string getTipo() const override {
            return "Gerente";
        }
};

class Director : public Empleado{
    public:
        Director(const std::string& n, double s) : Empleado(n, s) {}

        double calcularBono() const override {
            return salario * 0.3;
        }

        std::string getTipo() const override {
            return "Director";
        }
};

int main() {
    double totalBono = 0;
    Empleado* arr[4];
    arr[0] = new Programador("Ana", 3000);
    arr[1] = new Gerente("Luis", 5000);
    arr[2] = new Director("Carla", 8000);
    arr[3] = new Programador("Pedro", 2800);

    for (int i = 0; i < 4; i++) {
        arr[i]->imprimir();
        totalBono += arr[i]->calcularBono();
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total bonos: $" << totalBono;

    for (int i = 0; i < 4; i++) {
        delete arr[i];
    }

    return 0;
}
