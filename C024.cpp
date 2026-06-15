/*C024 | ANÁLISIS — diseño de encapsulamiento
Tienes esta clase. Identifica todos los problemas
de diseño y escribe la versión corregida.

  class Empleado {
  public:
      string nombre;
      double salario;
      int    edad;
      string contrasena;   // contraseña del sistema interno

      void setSalario(double s) { salario = s; }
      double getSalario() { return salario; }
  };

  Preguntas:
  a) ¿Qué atributos deberían ser private y por qué?
  b) ¿El setter tiene validación? ¿Qué pasa si s = -5000?
  c) ¿getSalario debería ser const? ¿Por qué?
  d) ¿contrasena debería tener getter? ¿Y setter? ¿Por qué?

  Tu respuesta:
  a) Todos los atributos deberían ser private para proteger la integridad de los datos y evitar que sean modificados directamente desde fuera de la clase. 
  b) El setter no tiene validación, lo que significa que si se establece un salario negativo, el objeto Empleado tendría un estado inválido.
  c) Sí, getSalario debería ser const porque no modifica el estado del objeto y permite llamar a este método en objetos const.
  d) No, contrasena no debería tener getter ni setter para proteger la seguridad de la información. La contraseña debe ser manejada de manera segura y no debería ser accesible ni modificable directamente desde fuera de la clase.
 */

#include <iostream>

class Empleado {
    private:
        std::string nombre;
        double salario;
        int edad;
        std::string contrasena;
    public:
        void setSalario(double s) {
            salario = (s >= 0) ? s : 0;
        }

        double getSalario() const { return salario; }
};

