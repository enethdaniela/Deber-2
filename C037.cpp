/*C037 | Reutilización de código con herencia
Sin herencia tendrías que repetir código en cada clase.
Con herencia el código del padre se reutiliza automáticamente.

Crea:
  Empleado (base):
    protected: nombre, salario (double)
    Constructor, getters, virtual double calcularBono()
    void imprimir() const → nombre + salario + bono

  Programador (derivada):
    private: lenguaje (string)
    calcularBono() override → 10% del salario

  Gerente (derivada):
    private: departamento (string)
    calcularBono() override → 20% del salario

  Director (derivada de Gerente):
    private: presupuesto (double)
    calcularBono() override → 30% del salario
    imprimir() const override → agrega info de presupuesto

Crea uno de cada tipo y muestra la info de cada uno.

Salida esperada:
  Ana (Programador/Python): $3000.00 | Bono: $300.00
  Luis (Gerente/Sistemas): $5000.00 | Bono: $1000.00
  Carla (Directora): $8000.00 | Bono: $2400.00 | Ppto: $500000.00*/

#include <iostream>
#include <iomanip>

class Empleado {
    protected:
        std::string nombre;
        double salario;
    public:
        Empleado(std::string n, double s) : nombre(n), salario(s) {}

        std::string getNombre() { return nombre; }
        double getSalario() { return salario; }

        virtual double calcularBono() const{
            return 0;
        }
        virtual void imprimir() const {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << nombre << ": $" << salario << " | Bono: $" << calcularBono() << '\n';
        }
};

class Programador : public Empleado {
    private:
        std::string lenguaje;
    public:
        Programador(std::string n, double s, std::string l) : Empleado(n, s), lenguaje(l) {}
        double calcularBono() const override {
            return salario * 0.1;
        }
        void imprimir() const override {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << nombre << " (Programador/" << lenguaje <<  "): $" << salario << " | Bono: $" << calcularBono()  << '\n';
        }
};

class Gerente : public Empleado {
    private:
        std::string departamento;
    public:
        Gerente(std::string n, double s, std::string d) : Empleado(n, s), departamento(d) {}
        double calcularBono() const override {
            return salario * 0.2;
        }
        void imprimir() const override {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << nombre << " (Gerente/" << departamento <<  "): $" << salario << " | Bono: $" << calcularBono() << '\n';
        }
};

class Director : public Empleado {
    private:
        double presupuesto;
    public:
        Director(std::string n, double s, double d) : Empleado(n, s), presupuesto(d) {}
        double calcularBono() const override {
            return salario * 0.3;
        }
        void imprimir() const override {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << nombre << " (Directora): $" << salario << " | Bono: $" << calcularBono() << " | Ppto: $" << presupuesto << '\n';
        }
};

int main() {
    Programador p("Ana", 3000, "Python");
    Gerente g("Luis", 5000, "Sistemas");
    Director d("Carla", 8000, 500000);

    p.imprimir();
    g.imprimir();
    d.imprimir();
}
