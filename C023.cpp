/*C023 | Getter que retorna referencia constante
Para tipos grandes como string, retornar por valor
crea una copia innecesaria. La solución:

  const string& getNombre() const { return nombre; }

Crea la clase Libro con:
  private: string titulo, string autor, int anio, double precio

Implementa getters que retornen:
  - int y double: por valor (son pequeños)
  - string: por referencia constante (const string&)

Setter con validación:
  setPrecio(double p) → válido solo si p >= 0

Entrada: (hardcodeado)
Salida esperada:
  Titulo: El Principito
  Autor : Antoine de Saint-Exupery
  Anio  : 1943
  Precio: $12.50*/

#include <iomanip>
#include <iostream>

class Libro {
    private:
        std::string titulo, autor;
        int anio;
        double precio;
    public:
        Libro(std::string t, std::string au, int a, double p) : titulo(t), autor(au), anio(a) {
            setPrecio(p);
        }

        void setPrecio(double precio) {
            if (precio >= 0) {
                this->precio = precio; 
            } else {
                std::cout << "Error: precio debe ser positivo. \n";
            }
        }

        int getAnio() const {return anio;}
        double getPrecio() const {return precio;}
        const std::string& getTitulo() const {return titulo;}
        const std::string& getAutor() const {return autor;}

        void imprimir() {
            std::cout << "Titulo: " << titulo << '\n';
            std::cout << "Autor: " << autor << '\n';
            std::cout << "Anio: " << anio << '\n';
            std::cout << std::fixed << std::setprecision(2) 
                      << "Precio: $" << precio << '\n';
        }
};

int main() {
    Libro l1("El Principito", "Antoine de Saint-Exupery", 1943, 12.50);
    l1.imprimir();

    return 0;
}