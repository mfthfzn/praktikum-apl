#include <iostream>
using namespace std;

int main() {

  // string nama[5]= {"Dimas", "Harahap", "Santoso", "Kalingga", "Ucup"};

  // int angka[3];
  // angka[0] = 1;
  // angka[1] = 2;
  // angka[2] = 3;

  int angka[5] = {1, 2, 3, 4, 5};
  int panjang1 = sizeof(angka) / sizeof(angka[0]);

  // cout << "Array :" << angka << endl;

  angka[1] = 6;
  for (int i = 0; i < panjang1; i++){
    cout << &angka[i] << endl;
  }

  // for (int result : angka) {
  //   cout << result << endl;
  // }
  

  // cout << angka << endl;
  // int panjang1 = sizeof(angka) / sizeof(angka[0]);
  // int panjang2 = sizeof(angka) / sizeof(int);

  // cout << "Panjang :" << panjang1 << endl;
  // cout << "Panjang :" << panjang2 << endl;

  // cout << "Nama :" << nama[2] << endl;
  // cout << "Angka :"<< angka[2] << endl;

  return 0;
}