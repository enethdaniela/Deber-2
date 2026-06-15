/*C029 | Primera herencia — Animal y Perro
Implementa la jerarquía de la teoría:
  Animal (base):
    protected: nombre (string)
    public: Constructor(string n), getNombre() const,
            virtual hacerSonido(), imprimir()

  Perro (derivada de Animal):
    private: raza (string)
    public: Constructor(string n, string r) llama a Animal(n)
            hacerSonido() override → "Guau!"
            imprimir() override    → muestra nombre y raza

  Gato (derivada de Animal):
    private: esCallejero (bool)
    public: Constructor(string n, bool c)
            hacerSonido() override → "Miau!"
            imprimir() override

En main crea un perro y un gato. Llama hacerSonido()
e imprimir() para cada uno.

Salida esperada:
  Rex (Labrador) dice: Guau!
  Rex - Raza: Labrador
  Luna (Callejero: No) dice: Miau!
  Luna - Callejero: No*/


#include <iostream>

//clase base
class Animal {
    protected:
        std::string nombre; // protected, para que sea accesible por las clases hijas.

    public:
        //constructior clase base
        Animal(std::string n) : nombre(n) {}

        //getter
        std::string getNombre() const { return nombre; }

        //virtual, para el polimorfismo (puede ser sobrescrita y se garantiza que se use la version correcta)
        virtual void hacerSonido() const {
            std::cout << "...";
        }

        virtual void imprimir() const {
            std::cout <<  nombre;
        }

        //destructor virtual obligatorio
        virtual ~Animal() {}
};

//clase derivada
class Perro : public Animal {
    private:
        std::string raza;

    public:
        //constructor hijo DEBE llamar al del padre en la lista de ini
        Perro(std::string n, std::string r) : Animal(n), raza(r) {}

        //sobrescribir el metodo con override para seguridad
        void hacerSonido() const override {
            std::cout << "Guau!\n";
        }

        void imprimir() const override {
            std::cout << nombre << " - Raza: " << raza << '\n';
        }
};

class Gato : public Animal {
    private:
        bool esCallejero;
    
    public:
        //constructor
        Gato(std::string n, bool c) : Animal(n), esCallejero(c) {}

        //se podria crear un getter para acceder a la raza desde el main

        //metodos sobrescritos
        void hacerSonido() const override {
            std::cout << "Miau!\n";
        }

        void imprimir() const override {
            std::cout <<  nombre << " - Callejero: " << (esCallejero ? "Si" : "No");
        }
};

int main() {
    Perro perro("Rex", "Labrador");
    Gato gato("Luna", false);

    std::cout << perro.getNombre() << " (Labrador) dice: ";
    perro.hacerSonido();
    perro.imprimir();

    std::cout << gato.getNombre() << " (Callejero: No) dice: ";
    gato.hacerSonido();
    gato.imprimir();

    return 0;
}