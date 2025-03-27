#include <iostream>
using namespace std;

struct Alamat {
  string jalan;
  string kota;
};

struct Mahasiswa {
  string nama;
  string nim;
  float ipk;
  Alamat alamat;
};

#define MAX_MAHASISWA 5

int panjang = 0;

Mahasiswa mhs[MAX_MAHASISWA];

void tampilkanData();

void tambahData();

void ubahData();

void hapusData();
int main() {


  int pilihan;
  do
  {
    cout << "Menu Program" << endl;
    cout << "1. Tampilkan Data" << endl;
    cout << "2. Tambah Data" << endl;
    cout << "3. Ubah Data" << endl;
    cout << "4. Hapus Data" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    switch (pilihan) {
    case 1:
      tampilkanData();
      break;
    case 2:
      tambahData();
      break;
    case 3:
        break;
    case 4:
      hapusData();
      break;
    case 5:
        cout << "Program selesai" << endl;
        break;
    default:
        cout << "Pilihan tidak valid" << endl;
        break;
    }
  } while (pilihan != 5);
}

void tampilkanData() {
  if (panjang == 0) {
    cout << "Belum ada data" << endl;
  } else {
    cout << "Data Mahasiswa" << endl;
    for (int i = 0; i < 2; i++) {
      cout << "Nama\t: " << mhs[i].nama << endl;
      cout << "NIM\t: " << mhs[i].nim << endl;
      cout << "IPK\t: " << mhs[i].ipk << endl;
      cout << "Jalan\t: " << mhs[i].alamat.jalan << endl;
      cout << "Kota\t: " << mhs[i].alamat.kota << endl << endl;
    }
  }
}

void tambahData() {
  if (panjang < MAX_MAHASISWA) {
    cout << "Masukkan Nama : ";
    cin.ignore();
    getline(cin, mhs[panjang].nama);

    cout << "Masukkan NIM : ";
    cin.ignore();
    getline(cin, mhs[panjang].nim);

    cout << "Masukkan IPK : ";
    cin >> mhs[panjang].ipk;

    cout << "Masukkan jalan : ";
    cin.ignore();
    getline(cin, mhs[panjang].alamat.jalan);

    cout << "Masukkan kota : ";
    cin.ignore();
    getline(cin, mhs[panjang].alamat.kota);
    panjang++;
    
    cout << "Mahasiswa berhasil  ditambahkan" << endl;
  } else {
    cout << "Sudah penuh" << endl;
  }
}

void hapusData() {
  cout << "Daftar Mahasiswa" << endl;
  for (int i = 0; i < panjang; i++) {
    cout <<  i + 1 << ". Nama\t: " << mhs[i].nama << endl;
  }

  int index;
  cout << "Masukkan Nomor Mahasiswa : ";
  cin >> index;

  for (int i =  index - 1; i < panjang; i++) {
    mhs[i] = mhs[i+1];
  }
  panjang--;
}