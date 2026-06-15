/*C010 | Integración nivel 0 — clase Cuenta
Crea la clase Cuenta con:
  Atributos public: titular (string), saldo (double)
  Métodos:
    void depositar(double monto)  → saldo += monto, imprime nuevo saldo
    void retirar(double monto)    → si hay saldo: saldo -= monto
                                    si no: imprime "Saldo insuficiente"
    void imprimir()
    bool tieneSaldo(double monto) → retorna true si saldo >= monto

En main simula una secuencia de operaciones.

Entrada: (hardcodeado)
Salida esperada:
  Titular: Ana Torres | Saldo: $500.00
  Deposito: $200.00 | Nuevo saldo: $700.00
  Retiro: $100.00 | Nuevo saldo: $600.00
  Saldo insuficiente.
  Titular: Ana Torres | Saldo: $600.00*/

#include <iostream>
#include <iomanip>

class Cuenta {
  public:
    std::string titular;
    double saldo;

    bool tienesSaldo(double monto) {
      return saldo >= monto;
    }

    void depositar(double monto) {
      saldo += monto;
      std::cout << std::fixed << std::setprecision(2);
      std::cout <<"Deposito: $" << monto << " | Nuevo saldo: $" << saldo << '\n';
    }

    void retirar(double monto) {
      if (tienesSaldo(monto)) {
        saldo -= monto;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Retiro: $" << monto << " | Nuevo saldo: $" << saldo << '\n';
      } else {
        std::cout << "Saldo insuficiente" << '\n';
      }
    }
    void imprimir() {
      std::cout << std::fixed << std::setprecision(2);
      std::cout << "Titular: " << titular << " | Saldo: $" << saldo << '\n';
    }
};

int main() {
  Cuenta c1;
  c1.titular = "Ana Torres";
  c1.saldo = 500;

  c1.imprimir();
  c1.depositar(200);
  c1.retirar(100);
  c1.retirar(800);
  c1.imprimir();

  return 0;
}