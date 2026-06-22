/*C034 | Herencia con encapsulamiento completo
Crea con encapsulamiento correcto (todo private/protected):
  Cuenta (base):
    protected: titular (string), saldo (double)
    Constructor con validación de saldo >= 0
    Getters const para titular y saldo
    virtual void depositar(double)
    virtual void retirar(double)
    virtual void imprimir() const

  CuentaAhorro (derivada):
    private: tasaInteres (double)
    Constructor llama a Cuenta(...)
    void aplicarInteres() → saldo += saldo * tasaInteres
    void imprimir() const override

  CuentaCorriente (derivada):
    private: sobregiroMax (double)
    void retirar(double) override → permite retirar hasta
      saldo + sobregiroMax (saldo puede quedar negativo)
    void imprimir() const override

Salida esperada:
  [Ahorro] Ana: $1000.00 | Interes: 5%
  Deposito: $200.00. Saldo: $1200.00
  Interes aplicado. Saldo: $1260.00
  [Corriente] Luis: $500.00 | Sobregiro max: $200.00
  Retiro: $600.00. Saldo: -$100.00  ← sobregiro permitido
  Retiro: $200.00. RECHAZADO: supera limite de sobregiro.*/

#include <iostream>
#include <iomanip>

class Cuenta {
    protected:
        std::string titular;
        double saldo;
    public:
        Cuenta(std::string t, double s) : titular(t) {
            saldo = (saldo >= 0) ? s : 0;
        }

        std::string getTitular() const { return titular; }
        double getSaldo() const { return saldo; }


        virtual void depositar(double cant) {
            saldo += cant;
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Deposito: $" << ". Saldo: $" << saldo << '\n';
        }

        virtual void retirar(double cant) {
            if (cant <= saldo) {
                saldo -= cant;
            } else {
                std::cout << "Saldo insuficiente.\n";
            }
        }

        virtual void imprimir() const {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << titular << ": $" << saldo; 
        }
} ;

class CuentaAhorro : public Cuenta {
    private:
        double tasaInteres;
    public:
        CuentaAhorro(std::string t, double s, double tI) : Cuenta(t, s), tasaInteres(tI) {}

        void aplicarInteres() {
            saldo += saldo * tasaInteres;
            std::cout << "Interes aplicado. Saldo: $" << saldo << '\n';
        }

        void imprimir() const override {
            Cuenta::imprimir();
            std::cout << " | Interes: " << tasaInteres << "%\n"; 
        }
};

class cuentaCorriente : public Cuenta {
    private:
        double sobregiroMax;
    public:
        cuentaCorriente(std::string t, double s, double sgMax) : Cuenta(t,s), sobregiroMax(sgMax) {}

        void retirar(double cant) override {
            if (cant <= (saldo + sobregiroMax)) {
                saldo -= cant;
                std::cout << "Retiro: $" << cant << "\n";
            } else {
                std::cout << "Retiro: $" << cant << ". RECHAZADO: supera limite de sobregiro.\n";
            }
        }

        void imprimir() const override {
            Cuenta::imprimir();
            std::cout << " | Sobregiro max: $" << sobregiroMax << '\n'; 
        }
};

int main() {
    CuentaAhorro ca("Ana", 1000, 5);

    ca.imprimir();
    ca.depositar(200);
    ca.aplicarInteres();
    
    cuentaCorriente cc("Luis", 500, 200);
    
    cc.imprimir();
    cc.retirar(600);
    cc.retirar(200);

    return 0;
}
    
    
   
    
