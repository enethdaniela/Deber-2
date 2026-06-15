/*C007 | Método definido fuera de la clase
Crea la clase Temperatura con atributos:
  double celsius (public)

Define todos los métodos FUERA de la clase usando el operador ::
  double Temperatura::getCelsius()
  double Temperatura::getFahrenheit()  → C*9/5 + 32
  double Temperatura::getKelvin()      → C + 273.15
  void   Temperatura::imprimir()

Esto enseña a separar la declaración de la implementación.

Entrada: (hardcodeado: 100.0 celsius)
Salida esperada:
  Celsius   : 100.00
  Fahrenheit: 212.00
  Kelvin    : 373.15*/

#include <iostream>
#include <iomanip>

class Temperatura {
 
  public:
    double  celsius;

    double getCelsius();
    double getFahrenheit();
    double getKelvin();
    void imprimir();
};

double Temperatura::getCelsius() {
  return celsius;
}

double Temperatura::getFahrenheit()  {
  return (celsius * 9 / 5.0) + 32;
}

double Temperatura::getKelvin() {
  return celsius + 273.15;
}

void Temperatura::imprimir() {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Celsius   : " << getCelsius() << '\n';
  std::cout << "Fahrenheit: " << getFahrenheit() << '\n';
  std::cout << "Kelvin    : " << getKelvin() << '\n';
}

int main() {
  Temperatura t1;
  t1.celsius = 100;
  t1.imprimir();

  return 0;
}