#include <iostream>
using namespace std;

struct Alamat {
  string jalan;
  int nomor;
  string kota;
};

struct Mahasiswa {
  string nama;
  string nim;
  string prodi;
  float ipk;
  int angkatan;
  Alamat alamat;
};



int main() {

  Mahasiswa mhs[5];

  mhs[0].nama = "Dimas";
  mhs[0].nim = "2460";
  mhs[0].prodi = "informatika";
  mhs[0].ipk = 4.1;
  mhs[0].angkatan = 24;
  mhs[0].alamat.jalan = "Pramuka";
  mhs[0].alamat.nomor = 20;
  mhs[0].alamat.kota = "Samarinda";

  mhs[0].nama = "Harahap";
  mhs[0].nim = "2465";
  mhs[0].prodi = "informatika";
  mhs[0].ipk = 4.2;
  mhs[0].angkatan = 24;
  mhs[0].alamat.jalan = "Pramuka";
  mhs[0].alamat.nomor = 20;
  mhs[0].alamat.kota = "Samarinda";

  for (int i = 0; i < 2; i++) {
    cout << "Nama\t: " << mhs[i].nama << endl;
    cout << "nim\t: " << mhs[i].nim << endl;
    cout << "prodi\t: " << mhs[i].prodi << endl;
    cout << "ipk\t: " << mhs[i].ipk << endl;
    cout << "angkatan: " << mhs[i].angkatan << endl;
    cout << "Jalan: " << mhs[i].alamat.jalan << endl;
    cout << "Nomor: " << mhs[i].alamat.nomor << endl;
    cout << "Kota: " << mhs[i].alamat.kota << endl;
  }
  

  return 0;
}