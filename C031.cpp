/*C031 | Constructor heredado con parámetros
Crea:
  Persona (base):
    protected: nombre (string), edad (int)
    Constructor(string n, int e) : nombre(n), edad(e)
    virtual void imprimir() const

  Empleado (derivada de Persona):
    private: empresa (string), salario (double)
    Constructor(string n, int e, string emp, double sal)
      → llama a Persona(n, e) en la lista de inicialización
    void imprimir() const override → muestra todos los datos

  Estudiante (derivada de Persona):
    private: carrera (string), semestre (int)
    Constructor apropiado
    void imprimir() const override

Crea un empleado y un estudiante en main.

Salida esperada:
  Ana Torres | 28 años | Empresa: USFQ | Salario: $2500.00
  Luis Mora  | 20 años | Carrera: Computacion | Semestre: 4*/

#include <iostream>
#include <iomanip>

class Persona {
    protected:
        std::string nombre;
        int edad;
    public:
        Persona(std::string n, int e) : nombre(n), edad(e) {}

        virtual void imprimir() const {
            std::cout << nombre << " | " << edad << " anios\n";
        }
};

class Empleado : public Persona {
    private:
        std::string empresa;
        double salario;
    public:
        Empleado(std::string n, int e, std::string emp, double sal) : Persona(n, e), empresa(emp), salario(sal) {}

        void imprimir() const override {
            std::cout << nombre << " | " << edad << " anios | Empresa: " << empresa 
                      << std::fixed << std::setprecision(2) << " | Salario: $" << salario << '\n';
        }
};

class Estudiante : public Persona {
    private:
        std::string carrera;
        int semestre;
    public:
        Estudiante(std::string n, int e, std::string c, int sem) : Persona(n, e), carrera(c), semestre(sem) {}

        void imprimir() const override {
            std::cout << nombre << " | " << edad << " anios | Carrera: " << carrera << " | Semestre: " << semestre << '\n';
        }
};

int main() {
    Empleado em("Ana Torres", 28, "USFQ", 2500);
    em.imprimir();

    Estudiante es("Luis Mora", 20, "COmputacion", 4);
    es.imprimir();

    return 0;
}