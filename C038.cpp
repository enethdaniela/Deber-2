/*C038 | Herencia y arreglos de objetos
Crea la jerarquía Animal → Perro, Gato, Pajaro del C029/C031.
En main crea un arreglo de 6 objetos de tipos mixtos y
llama hacerSonido() e imprimir() para cada uno en un bucle.

Salida esperada:
  Rex    : Guau!
  Luna   : Miau!
  Pío    : Pío pío!
  Max    : Guau!
  Pelusa : Miau!
  Loro   : Loro quiere galleta!*/

#include <iostream>

//clase base
class Animal {
    protected:
        std::string nombre; // protected, para que sea accesible por las clases hijas.

    public:
        //constructior clase base
        Animal(const std::string& n) : nombre(n) {}

        //getter
        std::string getNombre() const { return nombre; }

        //virtual, para el polimorfismo (puede ser sobrescrita y se garantiza que se use la version correcta)
        virtual void hacerSonido() const {
            std::cout << "...";
        }

        virtual void imprimir() const {
            std::cout <<  nombre << ": ";
            hacerSonido();
        }

        //destructor virtual obligatorio
        virtual ~Animal() {}
};

//clase derivada
class Perro : public Animal {
    public:
        //constructor hijo DEBE llamar al del padre en la lista de ini
        Perro(const std::string& n) : Animal(n) {}

        //sobrescribir el metodo con override para seguridad
        void hacerSonido() const override {
            std::cout << "Guau!\n";
        }

        void imprimir() const override {
            std::cout <<  nombre << ": ";
            hacerSonido();
        }
};

class Gato : public Animal {
    public:
        //constructor
        Gato(const std::string& n) : Animal(n) {}

        //metodos sobrescritos
        void hacerSonido() const override {
            std::cout << "Miau!\n";
        }

        void imprimir() const override {
            std::cout <<  nombre << ": ";
            hacerSonido();
        }
};

class Pajaro : public Animal {
    private:
        std::string sonidoPersonalizado;
    public:
        //constructor
        Pajaro(const std::string& n, const std::string& sonidoP = "Pio Pio!") : Animal(n), sonidoPersonalizado(sonidoP) {}

        //metodos sobrescritos
        void hacerSonido() const override {
            std::cout << sonidoPersonalizado << '\n';
        }

        void imprimir() const override {
            std::cout <<  nombre << ": ";
            hacerSonido();
        }

};

int main() {
    // no puedo ocupar un arreglo convencional de objetos: (Animal arr[6])-> es es un arreglo de tamaño fijo(6) del tamaño de animal, 
    //si quiero meter un pajaro que tiene mas que la base animal, simplememnte no cabe y pierdo los extras de Pajaro (object slicing)
    // Debo crear un arreglo de punteros:
    //Animal* arr[6];
    // ahora, arr contiene 6 direcciones de memoria, asi que para llenarlo:
    // a) creo objetos normales, creo el arreglo y paso por referencia.
    // b) o con memoria dinamica, con new y delete.
    // -> new crea mi objeto en la memoria y retorna la direccion de la memoria. Con est evito crear varibles indivuales
 
    Animal* arr[6];

    arr[0] = new Perro("Rex");
    arr[1] = new Gato("Luna");
    arr[2] = new Pajaro("Pio");
    arr[3] = new Perro("Max");
    arr[4] = new Gato("Pelusa");
    arr[5] = new Pajaro("Loro", "Loro quiere galleta");


    for (int i = 0; i < 6; i++) {
        arr[i]->imprimir();
    }

    for (int i = 0; i < 6; i++) {
        delete arr[i];
    }

    return 0;
}  