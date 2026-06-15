/*C026 | Múltiples objetos con encapsulamiento
Crea la clase Semaforo con:
  private: string estado  → "rojo", "amarillo" o "verde"

  Constructor: inicializa en "rojo"
  Método avanzar():
    rojo → verde → amarillo → rojo (ciclo)
  Getter: getEstado() const
  Método imprimir() const

En main simula 7 cambios de estado y muestra el estado
después de cada cambio.

Salida esperada:
  Estado: rojo
  Estado: verde
  Estado: amarillo
  Estado: rojo
  Estado: verde
  Estado: amarillo
  Estado: rojo
  Estado: verde*/

#include <iostream>

class Semaforo {
    private:
        std::string estado;
    public:
        Semaforo() : estado("rojo") {}

        void avanzar() {
            if (estado == "rojo") { 
                estado = "verde";
            } else if (estado == "verde") {
                estado = "amarillo";
            } else {
                estado = "rojo";
            }
        }

        std::string getEstado() const { return estado; }

        void imprimir() const {
            std::cout << "Estado: " << estado << '\n';
        }
};

int main() {
    Semaforo s;
    s.imprimir();
    
    for (int i = 0; i < 7; i++) {
        s.avanzar();
        s.imprimir();
    }
}