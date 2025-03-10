#include <iostream>
using namespace std;

int main() {
  
  int percobaan = 2;

  while (percobaan >= 0) {

    // Deklarasi variabel PIN untuk menampung PIN ATM user
    int PIN;
    // Deklarasi varieabel saldo
    int saldo = 1000000;
    cout << "Masukkan PIN ATM Anda : ";

    // Input PIN ATM user
    cin >> PIN;
    
    // Melakukan validasi PIN ATM user
    if (PIN == 6048) {
      while (true) {
        // Menampilkan Menu ATM
        string inputUser;
        cout << "\nMENU ATM " << endl;
        cout << "1. Setor Tunai" << endl;
        cout << "2. Cek Saldo" << endl;
        cout << "3. Tarik Tunai" << endl;
        cout << "4. Exit" << endl;
        cout << "Masukkan pilihan Anda : ";
        cin >> inputUser;

        // Melakukan validasi pilihan user
        if (inputUser == "1") {
          
          int setorTunai;

          // Melakukan input nominal setor tunai
          cout << "Masukkan nominal setor tunai : ";
          cin >> setorTunai;

          // Melakukan validasi nominal setor tunai yang diinputkan
          if (setorTunai < 0) {
            cout << "Masukkan jumlah setor tunai yang valid" << endl;
          } else {

            // Menjumlahkan saldo dengan setor tunai
            saldo += setorTunai;
            cout << "Berhasil melakukan setor tunai!" << endl;
            cout << "Saldo Anda sekarang berjumlah " << saldo << endl;
          }
        } else if (inputUser == "2") {
          // Menampilkan total saldo user
          cout << "Saldo Anda sekarang berjumlah " << saldo << endl;
        } 
        else if (inputUser == "3") {
          int tarikTunai;

          // Melakukan input nominal tarik tunai
          cout << "Masukkan nominal tarik tunai : ";
          cin >> tarikTunai;

          // Melakukan validasi nominal tarik tunai yang diinputkan
          if (tarikTunai < 0) {
            cout << "Masukkan jumlah tarik tunai yang valid" << endl;
          } else if (tarikTunai > saldo) {
            cout << "Saldo Anda tidak memenuhi untuk melakukan tarik tunai dengan nominal tersebut" << endl;
          } else {

            // Mengurangkan nominal saldo dengan nominal tarik tunai
            saldo -= tarikTunai;
            cout << "Berhasil melakukan tarik tunai!" << endl;
            cout << "Saldo Anda sekarang berjumlah " << saldo << endl;
          }
        } else if (inputUser == "4") {

          // Keluar dari program
          cout << "EXIT" << endl;
          cout << "Terima kasih telah menggunakan layanan ATM kami!" << endl;
          break;
        } else {
          // Menampilkan pesan kesalahan input pilihan
          cout << "Maaf, pilihan Anda tidak tersedia!" << endl;
        }
      }
      break;
    } else if (percobaan == 0) {
      cout << "Kesempatan Anda memasukkan PIN telah habis, ATM Anda dibekukan" << endl;
      break;
    } else {
      // Menampilkan pesan kesalahan input PIN 
      cout << "PIN yang Anda masukkan salah, tersisa " << percobaan;
      cout << " percobaan" << endl;
      percobaan -= 1;
    }
  }
  return 0;
}