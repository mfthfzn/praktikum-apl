#include <iostream>
using namespace std;

#define MAX_SPAREPART 100

int main() {
  
  string sparepart[MAX_SPAREPART];
  int quantities[MAX_SPAREPART];
  int prices[MAX_SPAREPART];
  int currentAmount = 2;


  int attempts = 2;

  while (attempts >= 0) {

    // Deklarasi variabel username untuk menampung username
    string username;

    // Deklarasi variabel password untuk menampung password user
    string password;
    cout << "Masukkan Username : ";

    // Input username
    cin >> username;
    
    cout << "Masukkan Password : ";

    // Input password
    cin >> password;
    
    sparepart[0] = "OLI AHM 800ML";
    sparepart[1] = "KAMPAS REM";
    quantities[0] = 100;
    quantities[1] = 10;
    prices[0] = 50000;
    prices[1] = 150000;

    // Melakukan validasi username dan password
    if (username == "fauzan" && password == "2409106048") {
      while (true) {
        // Menampilkan Menu
        int inputUser;
        cout << "\nMENU INVENTARIS " << endl;
        cout << "1. Tambah Sparepart" << endl;
        cout << "2. Tampilkan Sparepart" << endl;
        cout << "3. Ubah Stok Sparepart" << endl;
        cout << "4. Hapus Sparepart" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan Anda : ";
        cin >> inputUser;

        switch (inputUser) {
          case 1:
            // Tambah Sparepart
            if (currentAmount < MAX_SPAREPART){
              // Deklarasi variabel nameOfSparepart untuk menampung nama sparepart
              string nameOfSparepart;
              // Deklarasi variabel quantity untuk menampung kuantitas sparepart 
              int quantity;
              // Deklarasi variabel price untuk menampung harga sparepart
              int price;
              
              // Melakukan input nama sparepart
              cout << "Masukkan nama sparepart : ";
              cin.ignore();
              getline(cin, nameOfSparepart);

              // Melakukan input jumlah sparepart
              cout << "Masukkan jumlah sparepart : ";
              cin >> quantity;

              // Melakukan input harga sparepart
              cout << "Masukkan total harga per item : ";
              cin >> price;

              // Melakukan validasi semua field
              if (price < 0 || quantity < 0 || nameOfSparepart.empty()) {
                cout << "Masukkan nama, jumlah, total harga sparepart yang valid!" << endl;
              } else {
                // Append semua field ke dalam array masing-masing
                sparepart[currentAmount] = nameOfSparepart;
                quantities[currentAmount] = quantity;
                prices[currentAmount] = price;
                currentAmount++;
                cout << "\nBerhasil menambahkan sparepart!" << endl;
              }
            } else {
              cout << "Tidak bisa menambahkan sparepart karena inventaris sudah penuh!" << endl;
            }
            break;
          case 2:
            // Tampilkan Sparepart

            // Menampilkan header tabel
            cout << "+----+------------------------------------------+--------+-------------+" << endl;
            cout << "| No | Sparepart                                | Stok   | Harga       |" << endl;
            cout << "+----+------------------------------------------+--------+-------------+" << endl;
    
            // Menampilkan data sparepart dalam tabel
            for (int i = 0; i < currentAmount; i++) {
              cout << "| " << i + 1;
              i + 1 < 10 ? cout << "  " : cout << " ";
              cout << "| " << sparepart[i];
              for (int j = sparepart[i].length(); j < 40; j++) {
                cout << " ";
              }
              cout << " | " << quantities[i];
              if (quantities[i] < 10 ) {
                cout << "     ";
              } else if (quantities[i] < 100) {
                cout << "    ";
              } else {
                cout << "   ";
              }
              cout << " | " << prices[i];
              if (prices[i] < 10000) {
                cout << "       ";
              } else if (prices[i] < 100000) {
                cout << "      ";
              } else {
                cout << "     ";
              }
              cout << " |" << endl;
            }
            // Menutup tabel
            if (currentAmount != 0) {
              cout << "+----+------------------------------------------+--------+-------------+" << endl;
            }
            break;
          case 3:
            // Update Stok Sparepart
            
            // Mengecek apakah ada sparepart
            if (currentAmount == 0) {
              cout << "Tidak ada sparepart yang bisa diubah!" << endl;
            } else {
              // Menampilkan header tabel
              cout << "+----+------------------------------------------+--------+-------------+" << endl;
              cout << "| No | Sparepart                                | Stok   | Harga       |" << endl;
              cout << "+----+------------------------------------------+--------+-------------+" << endl;
              
              // Menampilkan data sparepart dalam tabel
              for (int i = 0; i < currentAmount; i++) {
                cout << "| " << i + 1;
                i + 1 < 10 ? cout << "  " : cout << " ";
                cout << "| " << sparepart[i];
                for (int j = sparepart[i].length(); j < 40; j++) {
                  cout << " ";
                }
                cout << " | " << quantities[i];
                if (quantities[i] < 10 ) {
                  cout << "     ";
                } else if (quantities[i] < 100) {
                  cout << "    ";
                } else {
                  cout << "   ";
                }
                cout << " | " << prices[i];
                if (prices[i] < 10000) {
                  cout << "       ";
                } else if (prices[i] < 100000) {
                  cout << "      ";
                } else {
                  cout << "     ";
                }
                cout << " |" << endl;
              }
              // Menutup tabel
              if (currentAmount != 0) {
                cout << "+----+------------------------------------------+--------+-------------+" << endl;
              }

              int indexSparepart;
              // Melakukan input index sparepart
              cout << "Masukkan No sparepart : ";
              cin >> indexSparepart;

              // Memvalidasi index sparepart
              if (indexSparepart > 0 && indexSparepart <= currentAmount) {
                int newStcok;
                cout << "Masukkan stok sparepart : ";
                cin >> newStcok;
                if (newStcok < 0) {
                  cout << "Gagal memperbarui stok sparepart!";
                } else {
                  // Mengubah stok sparepart
                  quantities[indexSparepart - 1] = newStcok;
                  cout << "Berhasil mengubah stok!" << endl;
                }
              } else {
                cout << "Nomor sparepart tidak valid" << endl;
              }
            }
            
            break;
          case 4:
            // Delete Sparepart

            if (currentAmount == 0) {
              cout << "Tidak ada sparepart yang bisa dihapus!" << endl;
            } else {
              // Menampilkan header tabel
              cout << "+----+------------------------------------------+--------+-------------+" << endl;
              cout << "| No | Sparepart                                | Stok   | Harga       |" << endl;
              cout << "+----+------------------------------------------+--------+-------------+" << endl;
              
              // Menampilkan data sparepart dalam tabel
              for (int i = 0; i < currentAmount; i++) {
                cout << "| " << i + 1;
                i + 1 < 10 ? cout << "  " : cout << " ";
                cout << "| " << sparepart[i];
                for (int j = sparepart[i].length(); j < 40; j++) {
                  cout << " ";
                }
                cout << " | " << quantities[i];
                if (quantities[i] < 10 ) {
                  cout << "     ";
                } else if (quantities[i] < 100) {
                  cout << "    ";
                } else {
                  cout << "   ";
                }
                cout << " | " << prices[i];
                if (prices[i] < 10000) {
                  cout << "       ";
                } else if (prices[i] < 100000) {
                  cout << "      ";
                } else {
                  cout << "     ";
                }
                cout << " |" << endl;
              }
              // Menutup tabel
              if (currentAmount != 0) {
                cout << "+----+------------------------------------------+--------+-------------+" << endl;
              }

              int indexSparepart;
              // Melakukan input index sparepart
              cout << "Masukkan No sparepart : ";
              cin >> indexSparepart;

              // Memvalidasi index sparepart
              if (indexSparepart > 0 && indexSparepart <= currentAmount) {
                for (int i = indexSparepart - 1; i < currentAmount - 1; i++) {
                  sparepart[i] = sparepart[i + 1];
                  quantities[i] = quantities[i + 1];
                  prices[i] = prices[i + 1];
                }
                currentAmount--;
                cout << "Berhasil menghapus sparepart!" << endl;
              } else {
                cout << "Nomor sparepart tidak valid" << endl;
              }
            }
            break;
          case 5:
            // Keluar dari program
            cout << "Keluar dari MENU INVENTARIS!" << endl;
            break;
          default:
            // Menampilkan pesan kesalahan input pilihan
            cout << "Maaf, pilihan Anda tidak tersedia!" << endl;
            break;
        }
        if (inputUser == 5) {
          break;
        }
        
      }
      break;
    } else if (attempts == 0) {
      cout << "Kesempatan Anda memasukkan untuk login telah habis, tunggu 15 menit untuk login kembali!" << endl;
      break;
    } else {
      // Menampilkan pesan kesalahan input PIN 
      cout << "Username atau Password yang Anda masukkan salah, tersisa " << attempts;
      cout << " percobaan" << endl;
      attempts -= 1;
    }
  }
  return 0;
}
