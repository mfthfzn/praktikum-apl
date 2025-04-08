#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

#define MAX_SPAREPART 100
#define MAX_USER 100

struct User {
  string username;
  string password;
};

struct Sparepart {
  string name;
  int stock;
  int price;
};

bool validateString(string valueOne, string valueTwo);

bool validateString(string value);

void registerMenu();

void loginMenu();

void mainMenu();

void tambahSparepart();

void tampilkanSparepart();

void ubahStokSparepart();

void hapusSparepart();

Sparepart sparepart[MAX_SPAREPART];
User user[MAX_USER];

int currentSparepart = 1;
int currentUser = 1;
int attempts = 2;

int main() {
  sparepart[0].name = "OLI AHM 800ML";
  sparepart[0].stock = 100; 
  sparepart[0].price = 150000;

  user[0].username = "fauzan";
  user[0].password = "2409106048";

  while (true) {
    // Deklarasi variabel inputUserDashboard untuk menampung pilihan user
    int inputUserDashboard;

    // Menampilkan Menu
    cout << "\nDASHBOARD INVENTARIS " << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Keluar" << endl;
    cout << "Masukkan pilihan Anda : ";
    cin >> inputUserDashboard;

    switch (inputUserDashboard) {
      case 1: {
        registerMenu();
      }
      break;
      case 2 : {
        loginMenu();
      }
      break;
      case 3 :
        // Keluar dari program
        cout << "Keluar!" << endl;
        break;
      default:
        // Menampilkan pesan kesalahan input pilihan
        cout << "Maaf, pilihan Anda tidak tersedia!" << endl;
        break;
    }
    if (inputUserDashboard == 3 || attempts == 0){
      break;
    }
  }
}

bool validateString(string valueOne, string valueTwo) {
  if (valueOne.empty() || valueTwo.empty() ){
    return true;
  } else {
    return false;
  }
}

bool validateString(string value) {
  if (value.empty()){
    return true;
  } else {
    return false;
  }
}

void tambahSparepart() {
  // Deklarasi variabel inputName untuk menampung nama sparepart
  string inputName;
  // Deklarasi variabel inputQuantity untuk menampung kuantitas sparepart 
  int inputQuantity;
  // Deklarasi variabel price untuk menampung harga sparepart
  int inputPrice;

  // Melakukan input nama sparepart
  cout << "Masukkan nama sparepart : ";
  cin.ignore();
  getline(cin, inputName);

  // Melakukan input jumlah sparepart
  cout << "Masukkan jumlah sparepart : ";
  cin >> inputQuantity;

  // Melakukan input harga sparepart
  cout << "Masukkan total harga per item : ";
  cin >> inputPrice;

  // Melakukan validasi semua field
  if (inputPrice < 0 || inputQuantity < 0 || validateString(inputName)) {
    cout << "Masukkan nama, jumlah, total harga sparepart yang valid!" << endl;
  } else {
    // Append semua field ke dalam array masing-masing
    sparepart[currentSparepart].name = inputName;
    sparepart[currentSparepart].stock = inputQuantity;
    sparepart[currentSparepart].price = inputPrice;
    currentSparepart++;
    cout << "\nBerhasil menambahkan sparepart!" << endl;
  }
}

void tampilkanSparepart() {
  // Tampilkan Sparepart
  cout << "\nTAMPILKAN SPAREPART" << endl;
  // Menampilkan header tabel
  cout << "+----+------------------------------------------+--------+-------------+" << endl;
  cout << "| No | Sparepart                                | Stok   | Harga       |" << endl;
  cout << "+----+------------------------------------------+--------+-------------+" << endl;

  // Menampilkan data sparepart dalam tabel
  for (int i = 0; i < currentSparepart; i++) {
    cout << "| " << i + 1;
    i + 1 < 10 ? cout << "  " : cout << " ";
    cout << "| " << sparepart[i].name;
    for (int j = sparepart[i].name.length(); j < 40; j++) {
      cout << " ";
    }
    cout << " | " << sparepart[i].stock;
    if (sparepart[i].stock < 10 ) {
      cout << "     ";
    } else if (sparepart[i].stock < 100) {
      cout << "    ";
    } else {
      cout << "   ";
    }
    cout << " | " << sparepart[i].price;
    if (sparepart[i].price < 10000) {
      cout << "       ";
    } else if (sparepart[i].price < 100000) {
      cout << "      ";
    } else {
      cout << "     ";
    }
    cout << " |" << endl;
  }
  // Menutup tabel
  if (currentSparepart != 0) {
    cout << "+----+------------------------------------------+--------+-------------+" << endl;
  }
}

void ubahStokSparepart() {
  int indexSparepart;
  // Melakukan input index sparepart
  cout << "Masukkan No sparepart : ";
  cin >> indexSparepart;

  // Memvalidasi index sparepart
  if (indexSparepart > 0 && indexSparepart <= currentSparepart) {
    int newStcok;
    cout << "Masukkan stok sparepart : ";
    cin >> newStcok;
    if (newStcok < 0) {
      cout << "\nGagal memperbarui stok sparepart!";
    } else {
      // Mengubah stok sparepart
      sparepart[indexSparepart - 1].stock = newStcok;
      cout << "Berhasil mengubah stok!" << endl;
    }
  } else {
    cout << "Nomor sparepart tidak valid" << endl;
  }
}

void hapusSparepart() {
  int indexSparepart;
  // Melakukan input index sparepart
  cout << "Masukkan No sparepart : ";
  cin >> indexSparepart;

  // Memvalidasi index sparepart
  if (indexSparepart > 0 && indexSparepart <= currentSparepart) {
    for (int i = indexSparepart - 1; i < currentSparepart - 1; i++) {
      sparepart[i] = sparepart[i + 1];
    }
    currentSparepart--;
    cout << "Berhasil menghapus sparepart!" << endl;
  } else {
    cout << "Nomor sparepart tidak valid" << endl;
  }
}

void mainMenu() {
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
        cout << "\nTAMBAH SPAREPART" << endl;
        // Tambah Sparepart
        if (currentSparepart < MAX_SPAREPART){
          tambahSparepart();
        } else {
          cout << "Tidak bisa menambahkan sparepart karena inventaris sudah penuh!" << endl;
        }
        break;
      case 2:
        if (currentSparepart == 0) {
          cout << "Tidak ada sparepart yang dapat ditampilkan!" << endl;
        } else {
          tampilkanSparepart();
        }
        break;
      case 3:
        // Update Stok Sparepart
        cout << "\nUBAH STOK SPAREPART" << endl;
        // Mengecek apakah ada sparepart
        if (currentSparepart == 0) {
          cout << "Tidak ada data sparepart yang bisa diubah!" << endl;
        } else {
          //Menampilkan Sparepart
          tampilkanSparepart();

          // Mengubah stok sparepart
          ubahStokSparepart();
        }

        break;
      case 4:
        // Delete Sparepart
        cout << "\nHAPUS SPAREPART" << endl;
        if (currentSparepart == 0) {
          cout << "Tidak ada sparepart yang bisa dihapus!" << endl;
        } else {
          // Menampilkan sparepart
          tampilkanSparepart();
          
          //Melakukan hapus sparepart
          hapusSparepart();
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
}

void registerMenu() {
  // Deklarasi variabel username untuk menampung username
  string usernameRegister;
  // Deklarasi variabel password untuk menampung password user
  string passwordRegister;

  cout << "\nREGISTER" << endl;

  // Melakukan input username
  cout << "Masukkan Username : ";
  cin.ignore();
  getline(cin, usernameRegister);

  // Melakukan input password
  cout << "Masukkan Password : ";
  getline(cin, passwordRegister);

  if (validateString(usernameRegister, passwordRegister)){
    cout << "Masukkan Username dan Password yang valid!" << endl;
  } else {
    user[currentUser].username = usernameRegister;
    user[currentUser].password = passwordRegister;
    currentUser++;
    cout << "\nRegister Berhasil!" << endl;
  }
}

void loginMenu() {
  while (attempts >= 0) {
    
    cout << "\nLogin" << endl;
    // Deklarasi variabel username untuk menampung username
    string usernameLogin;
  
    // Deklarasi variabel password untuk menampung password user
    string passwordLogin;

    // Input username
    cout << "Masukkan Username : ";
    cin.ignore();
    getline(cin, usernameLogin);
  
    // Input password
    cout << "Masukkan Password : ";
    getline(cin, passwordLogin);
    
    // Deklarasi variabel isExist untuk mengecek username dan password
    bool isExist = false;

    // Mengecek username dan password
    for (int i = 0; i < currentUser; i++) {
      if (user[i].username == usernameLogin && user[i].password == passwordLogin) {
        // Jika username dan password ditemukan ubah variable isExist
        isExist = true;
      }
    }
    
    if (isExist) {
      mainMenu();
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
}

