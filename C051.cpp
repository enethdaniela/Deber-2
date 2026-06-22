/*C051 | Sistema de biblioteca
Diseña e implementa:

  Material (abstracta):
    private: codigo, titulo, anio
    Constructor, getters, destructor virtual
    virtual string getTipo() const = 0
    virtual bool esPrestable() const = 0
    virtual void imprimir() const

  Libro : Material
    private: autor, paginas
    esPrestable() → siempre true
    getTipo()     → "Libro"

  Revista : Material
    private: numero, editorial
    esPrestable() → solo si numero < 50 (ejemplares viejos no salen)
    getTipo()     → "Revista"

  DVD : Material
    private: duracionMin, clasificacion
    esPrestable() → solo si clasificacion != "18+"
    getTipo()     → "DVD"

  Biblioteca:
    private: Material* catalogo[100], int cantidad
    void agregar(Material* m)
    void listarTodo() const
    void listarPrestables() const
    void buscarPorTitulo(string titulo) const
    ~Biblioteca() → libera toda la memoria

En main popula la biblioteca y realiza búsquedas.*/

#include <iostream>

class Material {
    private:
        std::string titulo;
        int anio;
    public:
        Material(const std::string t, int a) : titulo(t), anio(a) {}

        virtual ~Material() {}

        std::string getTitulo() const { return titulo; }
        int getAnio() const { return anio; }

        virtual std::string getTipo() const = 0;
        virtual bool esPrestable() const = 0;
        virtual void imprimir() const {
            std::cout << getTipo() << " | " << getTitulo() << " | " << getAnio() << " | ";
        }
};

class Libro : public Material {
    private: 
        std::string autor;
        int paginas;
    public:
        Libro(const std::string t, int a, const std::string au, int p) : Material(t, a), autor(au), paginas(p) {}

        std::string getTipo() const override { return "Libro"; }

        bool esPrestable() const override {
            return true;
        }
        void imprimir() const override {
            Material::imprimir();
            std::cout << autor << " | Paginas:" << paginas << '\n';
        }
};

class Revista : public Material {
    private:
        int numero;
        std::string editorial;
    public:
        Revista(const std::string t, int a, int n, const std::string e) : Material(t, a), numero(n), editorial(e) {}

        std::string getTipo() const override { return "Revista"; }

        bool esPrestable() const override { 
            return (numero < 50) ? true : false;
        }

        void imprimir() const override {
            Material::imprimir();
            std::cout << "Nro." << numero << " | " << editorial << '\n';
        }
};

class DVD :  public Material {
    private:
        int DuracionMin;
        std::string clasificacion;
    public:
        DVD(const std::string t, int a, int d, const std::string c) : Material(t, a), DuracionMin(d), clasificacion(c) {}

        std::string getTipo() const override { return "DVD"; }

        bool esPrestable() const override { 
            return (clasificacion != "18+") ? true : false;
        }

        void imprimir() const override {
            Material::imprimir();
            std::cout << DuracionMin << "min | " << clasificacion << '\n';
        }
};

class Biblioteca {
    private:
        //static. Si la constante es la misma para cualquier instancia de la clase
        static const int TAMANIO = 100;
        Material* catalogo[TAMANIO];
        int cantidad;
    public:
    Biblioteca() : cantidad(0) {
        for (int i = 0; i < TAMANIO; i++) {
            catalogo[i] = nullptr;
        }
    } 
    ~Biblioteca() {
        for (int i = 0; i < cantidad; i++) {
            delete catalogo[i];
        }
    }

    void agregar(Material* m) {
        if (cantidad < TAMANIO) {
            catalogo[cantidad] = m;
            cantidad++;
        } else {
            std::cout << "Catalogo lleno\n"; 
            delete m;
        }
    }

    void listarTodo() const {
        std::cout << "\n===  CATALOGO ===\n";
        for (int i = 0; i < cantidad; i++) {
            catalogo[i]->imprimir();
        }
    }

    void listarPrestables() const {
        std::cout << "\n=== PRESTABLES ===\n";
        for (int i = 0; i < cantidad; i++) {
            if (catalogo[i]->esPrestable()) {
                catalogo[i]->imprimir();
            }
        }
    }

    void buscarPorTitulo(const std::string& tituloBuscado) const {
        std::cout << "\n=== RESULTADOS BUSQUEDA ===\n"; 
        std::cout << "Busqueda: " << tituloBuscado << '\n';
        bool encontrado;
        for (int i = 0; i < cantidad; i++) {
            if (catalogo[i]->getTitulo() == tituloBuscado) {
                catalogo[i]->imprimir();
                encontrado = true;
            }
        } 
        if (!encontrado) {
            std::cout << "No se encontro ningun material con ese titulo\n";
        }
    }
};

int main() {
    Biblioteca biblioteca;

    biblioteca.agregar(new Libro("El Aleph", 1949, "Jorge Luis Borges", 180));
    biblioteca.agregar(new Libro("Dune", 1965, "Frank Herbert", 600));
    
    biblioteca.agregar(new Revista("National Geographic", 2023, 12, "NG Media")); // Prestable
    biblioteca.agregar(new Revista("Scientific American", 2021, 75, "Springer")); // NO prestable

    biblioteca.agregar(new DVD("Inception", 2010, 148, "PG-13")); // Prestable
    biblioteca.agregar(new DVD("The Matrix", 1999, 136, "18+"));   // NO prestable

    biblioteca.listarTodo();
    biblioteca.listarPrestables();

    biblioteca.buscarPorTitulo("Dune");       // Éxito
    biblioteca.buscarPorTitulo("The Matrix"); // Éxito
    biblioteca.buscarPorTitulo("dune");       // Fallo
    
    return 0;
}