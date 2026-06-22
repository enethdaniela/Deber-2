/*C035 | Herencia múltiple
C++ permite que una clase herede de MÁS de una clase base.

  class Volador {
  public:
      virtual void volar() {
          cout << "Volando..." << endl;
      }
  };

  class Nadador {
  public:
      virtual void nadar() {
          cout << "Nadando..." << endl;
      }
  };

  class Pato : public Volador, public Nadador {
  private:
      string nombre;
  public:
      Pato(string n) : nombre(n) {}
      void volar() override {
          cout << nombre << " vuela: Fiu fiu!" << endl;
      }
      void nadar() override {
          cout << nombre << " nada: Splash!" << endl;
      }
  };

Implementa la jerarquía y agrega una clase Cisne que también
herede de Volador y Nadador con su propio comportamiento.

Salida esperada:
  Donald vuela: Fiu fiu!
  Donald nada: Splash!
  Odette vuela: Aleteo elegante.
  Odette nada: Deslizamiento suave.*/

#include  <iostream>

class Volador {
  public:
    virtual void volar() {
    std::cout << "Volando..." << std::endl;
    }
};

class Nadador {
  public:
    virtual void nadar() {
    std::cout << "Nadando..." << std::endl;
    }
};

class Pato : public Volador, public Nadador {
  private:
    std::string nombre;
  public:
    Pato(std::string n) : nombre(n) {}
    void volar() override {
        std::cout << nombre << " vuela: Fiu fiu!" << std::endl;
    }
    void nadar() override {
        std::cout << nombre << " nada: Splash!" << std::endl;
    }
};

class Cisne : public Volador, public Nadador {
    private:
        std::string nombre;
    public:
        Cisne(std::string n) : nombre(n) {}
        void volar() override {
        std::cout << nombre << " vuela: Aleteo elegante." << std::endl;
    }
    void nadar() override {
        std::cout << nombre << " nada: Deslizamiento suave." << std::endl;
    }
};

int main() {
    Pato p("Donald");
    Cisne c("Odette");

    p.volar();
    p.nadar();
    c.volar();
    c.nadar();

    return 0;
}