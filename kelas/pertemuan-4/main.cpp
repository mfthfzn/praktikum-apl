#include <iostream>
using namespace std;

int kali(int a, int b);
int kali(double a, double b);

int faktorial(int angka) {
  if (angka == 0)
  {
    return 1;
  }
  else {
    return angka * faktorial(angka - 1);
  }
  
}

int main() {
  cout << kali(5,5);
  return 0;
}

int kali(int a, int b) {
  return a * b;
}

int kali(double a, double b) {
  return a * b;
}
