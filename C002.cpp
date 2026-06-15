/*C002 | Múltiples atributos
Crea la clase Persona con:
  Atributos public: nombre (string), edad (int), altura (double)
  Métodos:
    void imprimir()
    bool esMayorDeEdad()  → retorna true si edad >= 18
    string saludar()      → retorna "Hola, soy [nombre] y tengo
                             [edad] años."

En main crea 3 personas con datos distintos.

Entrada: (datos hardcodeados)
Salida esperada:
  Nombre: Ana, Edad: 22, Altura: 1.65m
  Mayor de edad: SI
  Hola, soy Ana y tengo 22 años.*/

#include <iostream>
#include <string>

class Persona {
  public:
  std::string nombre;
  int edad;
  double altura;

  std::string saludar() {
    return "Hola, soy " + nombre + " y tengo " + std::to_string(edad) + " anios.\n";
  }

  bool esMayorDeEdad() {
    return edad >= 18;
  }

  void imprimir() {
    std::cout << "Nombre: " << nombre << ", Edad: " << edad << ", Altura: " << altura << "m.\n";
    std::cout << "Es mayor de edad: " << (esMayorDeEdad() ? "SI" : "NO") << '\n';
    std::cout << saludar();
  }

};

int main() {
  Persona p1;
  p1.nombre = "Ana";
  p1.edad = 22;
  p1.altura = 1.65;
  p1.imprimir();

  Persona p2;
  p2.nombre = "Sara";
  p2.edad = 21;
  p2.altura = 1.65;
  p2.imprimir();

  Persona p3;
  p3.nombre = "Leandro";
  p3.edad = 18;
  p3.altura = 1.70;
  p3.imprimir();

  return 0;
}