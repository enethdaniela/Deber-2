/*C053 | Sistema de empleados con nómina
Jerarquía completa con encapsulamiento y polimorfismo:

  Empleado (abstracta):
    virtual double calcularSalarioMensual() const = 0
    virtual double calcularImpuesto()       const = 0
    virtual void imprimir()                 const

  EmpleadoFijo    : Empleado
    salario mensual fijo, impuesto = 15% si > $2000, sino 10%

  EmpleadoHora    : Empleado
    horasSemanales * tarifaHora * 4, impuesto = 8%

  EmpleadoComision: Empleado
    salarioBase + (ventas * pctComision), impuesto = 12%

  Nomina:
    Empleado* lista[50], int cantidad
    void agregar(Empleado*)
    double totalBruto()   const  → suma de salarios
    double totalImpuesto()const  → suma de impuestos
    double totalNeto()    const  → bruto - impuesto
    void imprimirNomina() const
    ~Nomina()*/

#include <iostream>
#include <iomanip>

class Empleado {
    private: 
        std::string nombre;
    public:
        Empleado(const std::string& n) : nombre(n) {}

        virtual ~Empleado() {}

        std::string getNombre() const { return nombre; }
        virtual std::string getTipo() const = 0;

        virtual double calcularSalarioMensual() const = 0;
        virtual double calcularImpuesto() const = 0;
        virtual void imprimir () const {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << getTipo() << " | " <<  getNombre() << " | $" << calcularSalarioMensual() << " | $" << calcularImpuesto() << '\n';
        }
};

class EmpleadoFijo : public Empleado {
    private:
        double salario;
    public:
        EmpleadoFijo(const std::string& n, double s) : Empleado(n), salario(s) {}

        std::string getTipo() const override { return "FIJO"; }

        double calcularSalarioMensual() const override {
            return salario;
        }
        double calcularImpuesto() const override {
            return (salario > 2000) ? (salario * 0.15) : (salario * 0.1);
        }
};

class EmpleadoHora : public Empleado {
    private:
        int horasSemanales;
        double tarifaHora;
    public:
        EmpleadoHora(const std::string& n, int horas, double tarifa) : Empleado(n), horasSemanales(horas), tarifaHora(tarifa) {}

        std::string getTipo() const override { return "HORA"; }

        double calcularSalarioMensual() const override {
            return horasSemanales * tarifaHora * 4;
        }
        double calcularImpuesto() const override {
            return calcularSalarioMensual() * 0.08;
        }
};

class EmpleadoComision : public Empleado {
    private:
        double salario, pctComision;
        int ventas;
    public:
        EmpleadoComision(const std::string& n, double s, double c, int v) : Empleado(n), salario(s), pctComision(c), ventas(v) {}

        std::string getTipo() const override { return "COMISION"; }

        double calcularSalarioMensual() const override {
            return salario + (ventas * pctComision);
        }
        double calcularImpuesto() const override {
            return calcularSalarioMensual() * 0.12;
        }
};

class Nomina {
    private:
        Empleado* lista[50];
        int cantidad;
    public:
        Nomina() : cantidad(0) {
            for (int i = 0; i < 50; i++) {
                lista[i] = nullptr;
            }
        }

        ~Nomina() {
            for (int i = 0; i < cantidad; i++) {
                delete lista[i];
            }  
        }

        void agregar(Empleado* m) {
            if (cantidad < 50) {
                lista[cantidad] = m;
                cantidad++;
            } else {
                std::cout << "Lleno\n"; 
                delete m;
            }
        }

        double totalBruto() const {
            double total = 0;
            for (int i = 0; i < cantidad; i++) {
                total += lista[i]->calcularSalarioMensual();
            }
            return total;
        }

        double totalImpuesto() const {
            double total = 0;
            for (int i = 0; i < cantidad; i++){
                total += lista[i]->calcularImpuesto();
            }
            return total;
        }

        double TotalNeto() const {
            return totalBruto() - totalImpuesto();
        }

        void imprimirNomina() const {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "\n=== NOMINA ===\n";
            std::cout << "Total Bruto: " << totalBruto() << '\n';
            std::cout << "Total Impuesto: " << totalImpuesto() << '\n';
            std::cout << "Total Neto: " << TotalNeto() << '\n';
        }
};

int main() {
    Nomina nomina;

    nomina.agregar(new EmpleadoFijo("Alice", 2500.00));
    nomina.agregar(new EmpleadoFijo("Bob", 1500.00));

    nomina.agregar(new EmpleadoHora("Charlie", 40, 15.00)); 

    nomina.agregar(new EmpleadoComision("Diana", 1000.00, 0.10, 5000)); 

    nomina.imprimirNomina();

    return 0;
}