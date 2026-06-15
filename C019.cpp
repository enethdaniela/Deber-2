/*C019 | Pasar de public a private
Toma la clase Persona del ejercicio C002.
Mueve todos los atributos a private.
Agrega getters y setters con validación:
  setEdad(int e)   → válido solo si 0 <= e <= 120
  setAltura(double h) → válido solo si 0.5 <= h <= 2.5
  (nombre no necesita validación numérica)

En main intenta asignar valores inválidos y verifica que
se rechazan.

Salida esperada:
  Nombre: Ana, Edad: 22, Altura: 1.65m
  Edad invalida.
  Altura invalida.
  Nombre: Ana, Edad: 22, Altura: 1.65m*/

#include <iostream>
#include <string>

class Persona {
  private:
    std::string nombre;
    int edad;
    double altura;

  public:
    //contructor
    Persona( std::string n, int e, double h) : nombre(n) {
        setEdad(e);
        setAltura(h);
    }
    //getters
    std::string getNombre() const {return nombre;}
    int getEdad() const {return edad;}
    double getAltura () const {return altura;}

    //setters
    void setEdad(int e) {
        if (0 <= e && e <= 120) {
            edad = e;
        } else {
            std::cout << "Edad invalida.\n";
        }
    }

    void setAltura(double h) {
        if (0.5 <= h && h <= 2.5) {
            altura = h;
        } else {
            std::cout << "Altura invalida.\n";
        }
    }

  //metodos
  bool esMayorDeEdad() {
    return edad >= 18;
  }

  void imprimir() {
    std::cout << "Nombre: " << nombre << ", Edad: " << edad << ", Altura: " << altura << "m.\n";
  }

};

int main() {
  Persona p1("Ana", 22, 1.65);
  p1.imprimir();

  p1.setEdad(150); //deberia fallar
  p1.setAltura(3.1); //debria fallar

  p1.imprimir();

  return 0;
}

