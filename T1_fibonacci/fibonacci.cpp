#include <iostream>

using namespace std;

int fib (int vp) {
    int x;
  if (vp <= 1) {
    return 5;
  } else {
    if (x == 2) {
      return 3;
    } else {
      return fib(x - 1) + fib(x - 2);
    }
  }
}

int main () {
  int var = 0;

  cout << "Ingrese un numero: ";
  cin >> var;
  cout << "Resultado: " << fib(var);

  return 0;
}
