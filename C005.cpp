/*C005 | Arreglo de objetos
Crea la clase Estudiante con:
  Atributos public: nombre (string), nota (double)
  Métodos:
    void imprimir()
    bool aprobo()  → true si nota >= 60

En main crea un arreglo de 4 estudiantes.
Imprime los que aprobaron y los que reprobaron por separado.

Entrada: (datos hardcodeados)
  Ana 85  Luis 45  Carla 92  Pedro 58
Salida esperada:
  === Aprobados ===
  Ana: 85.00
  Carla: 92.00
  === Reprobados ===
  Luis: 45.00
  Pedro: 58.00*/

#include <iostream>
#include <iomanip>

class Estudiante {
  public:
    std::string nombre;
    double nota;

    bool aprobo() {
      return nota >= 60;
    }
    void imprimir() {
      std::cout << std::fixed << std::setprecision(2);
      std::cout << nombre << ": " << nota << '\n';
    }
};

int main() {
  const int N = 4;
  Estudiante lista[N];

  lista[0].nombre = "Ana"; lista[0].nota = 85;
  lista[1].nombre = "Luis"; lista[1].nota = 45;
  lista[2].nombre = "Carla"; lista[2].nota = 92;
  lista[3].nombre = "Pedro"; lista[3].nota = 58;

  std::cout << "=== Aprobados ===\n";
  for (int i = 0; i < N; i++) {
    if (lista[i].aprobo()) {
      lista[i].imprimir();
    } 
  }

  std::cout << "=== Reprobados ===\n";
  for (int i = 0; i < N; i++) {
    if (!lista[i].aprobo()) {
      lista[i].imprimir();
    } 
  }

  return 0;
}
