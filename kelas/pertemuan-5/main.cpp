#include <iostream>
using namespace std;

struct Address{
  string kota;
  string provinsi;
  string negara;
};

// Menggunakan dereference
int ubahNilai(int *a, int b) {
  cout << "Alama a fungsi : " << a << endl;
  return *a = b;
}

// Menggunakan address of
int ubahNilai(int &a, int b) {
  cout << "Alama a fungsi : " << &a << endl;
  return a = b;
}

int main() {

  // int a = 5;
  // int b = 10;

  // // // menggunakan dereference
  // ubahNilai(&a, b);

  // // menggunakan address of
  // ubahNilai(a, b);

  // cout << "nilai a : " << a << endl;
  // cout << "Alama a fungsi : " << &a << endl;

  int a= 5;
  // int b = a;

  // variabel pointer
  int *b = &a;

  *b = 10;
  cout << "nilai a: " << a << endl;
  cout << "alamat a: " << &a << endl;
  cout << "nilai b: " << *b << endl;
  cout << "alamat b: " << b << endl;


  // deklarasi variabel dengan struct
  // Address address1;
  // // mengisi value address1
  // address1.kota = "Samarinda";
  // address1.provinsi = "Kalimantan Timur";
  // address1.negara = "Indonesia";
  // // mengcopy value address1 ke address2
  // Address *address2 = &address1;

  // // mengganti property kota dari samarinda ke ikn
  // address2->kota = "Tenggraong";

  // // value address1
  // cout<< address1.kota <<endl;
  // // value address2
  // cout<< address2->kota <<endl;

  return 0;
}