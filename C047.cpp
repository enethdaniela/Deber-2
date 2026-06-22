/*C047 | TRAZA — despacho dinámico complejo
RESUELVE A MANO antes de implementar:

  class A {
  public:
      virtual void f() { cout << "A::f" << endl; }
      void g()         { cout << "A::g" << endl; }
  };
  class B : public A {
  public:
      void f() override { cout << "B::f" << endl; }
      void g()          { cout << "B::g" << endl; }
  };
  class C : public B {
  public:
      void f() override { cout << "C::f" << endl; }
  };

  int main() {
      A* p1 = new B();
      A* p2 = new C();
      B* p3 = new C();

      p1->f();   // línea 1
      p1->g();   // línea 2
      p2->f();   // línea 3
      p2->g();   // línea 4
      p3->f();   // línea 5
      p3->g();   // línea 6

      delete p1; delete p2; delete p3;
  }

  Línea 1: B::f  Línea 2: A::g  Línea 3: C::f
  Línea 4: A::g  Línea 5: C::f  Línea 6: B::g*/

#include <iostream>

using namespace std;

  class A {
  public:
      virtual void f() { cout << "A::f" << endl; }
      void g()         { cout << "A::g" << endl; }
  };
  class B : public A {
  public:
      void f() override { cout << "B::f" << endl; }
      void g()          { cout << "B::g" << endl; }
  };
  class C : public B {
  public:
      void f() override { cout << "C::f" << endl; }
  };

  int main() {
      A* p1 = new B();
      A* p2 = new C();
      B* p3 = new C();

      p1->f();   // línea 1
      p1->g();   // línea 2
      p2->f();   // línea 3
      p2->g();   // línea 4
      p3->f();   // línea 5
      p3->g();   // línea 6

      delete p1; delete p2; delete p3;
  }