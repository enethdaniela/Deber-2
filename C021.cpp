/*C021 | Las tres capas de protección
Crea la clase CuentaBancaria con:
  private: string titular, double saldo

  CAPA 1 — Constructor: valida saldo >= 0
  CAPA 2 — Setters: depositar y retirar con validación completa
  CAPA 3 — Atributos private: nadie puede hacer cuenta.saldo = -999

Demuestra intentando:
  - Crear cuenta con saldo negativo (se corrige a 0)
  - Retirar más de lo disponible (se rechaza)
  - Depositar monto negativo (se rechaza)

Salida esperada:
  Ana Torres: $0.00    ← nació con saldo negativo, corregido
  Deposito: $500.00. Saldo: $500.00
  Retiro: $200.00. Saldo: $300.00
  Error: saldo insuficiente.
  Error: monto debe ser positivo.
  Ana Torres: $300.00*/

#include <iostream>
#include <iomanip>

class CuentaBancaria {
    private:
        std::string titular;
        double saldo;
    public:
        //constructor
        CuentaBancaria(std::string t, double s) : titular(t) {
            saldo = (s >= 0) ? s : 0;
        }

        bool tienesSaldo(double monto) {
        return saldo >= monto;
        }

        void depositar(double monto) {
            if(monto <= 0) {
                std::cout << "Error: monto debe ser positivo.\n";
            } else {
                saldo += monto;
                std::cout << std::fixed << std::setprecision(2);
                std::cout <<"Deposito: $" << monto << ". Saldo: $" << saldo << '\n';
            }
            
        }

        void retirar(double monto) {
            if (tienesSaldo(monto)) {
                saldo -= monto;
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "Retiro: $" << monto << ". Saldo: $" << saldo << '\n';
            } else if(monto <= 0) {
                std::cout << "Error: monto debe ser positivo./n";
            } else {
                std::cout << "Error: Saldo insuficiente" << '\n';
            }
        }
        void imprimir() {
             std::cout << std::fixed << std::setprecision(2);
            std::cout << titular << ": $" << saldo << '\n';
        }

};

int main() {
    CuentaBancaria c1("Ana Torres", -45);
    c1.imprimir();
    c1.depositar(500);
    c1.retirar(200);
    c1.retirar(400);
    c1.depositar(-34);
    c1.imprimir();

    return 0;
}