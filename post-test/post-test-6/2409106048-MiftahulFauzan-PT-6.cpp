#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

#define MAX_SPAREPART 100
#define MAX_USER 10

struct User {
  string username;
  string password;
};

struct Sparepart {
  string name;
  int stock;
  int price;
};

bool validateString(string &valueOne, string &valueTwo);

bool validateString(string &value);

void registerMenu(User *user[], int &currentUser);

void loginMenu(User *user[], Sparepart *sparepart[], int &currentUser, int &currentSparepart);

void mainMenu(Sparepart *sparepart[], int &currentSparepart);

void tambahSparepart(Sparepart *sparepart[], int &currentSparepart);

void printSparepart(Sparepart *sparepart[], int &currentSparepart);

void ubahStokSparepart(Sparepart *sparepart[], int &currentSparepart);

void hapusSparepart(Sparepart *sparepart[], int &currentSparepart);

void tampilkanSparepart(Sparepart *sparepart[], int &currentSparepart);

void insertionSort(Sparepart *sparepart[], int &currentSparepart);

void selectionSort(Sparepart *sparepart[], int &currentSparepart);

void bubbleSort(Sparepart *sparepart[], int &currentSparepart);

int attempts = 2;

int main() {
  Sparepart sparepart[MAX_SPAREPART];
  User user[MAX_USER];

  Sparepart *sparepartPtr[MAX_SPAREPART];
  User *userPtr[MAX_USER];

  for (int i = 0; i < MAX_SPAREPART; i++) {
    sparepartPtr[i] = &sparepart[i];
  }

  for (int i = 0; i < MAX_USER; i++) {
    userPtr[i] = &user[i];
  }

  int currentSparepart = 4;
  int currentUser = 1;

  sparepart[0].name = "AHM Oil SPX-2 800ML";
  sparepart[0].stock = 100; 
  sparepart[0].price = 70000;

  sparepart[1].name = "Motul Oil Green 800ML";
  sparepart[1].stock = 45; 
  sparepart[1].price = 144000;

  sparepart[2].name = "Federal Matic 30 800ML";
  sparepart[2].stock = 35; 
  sparepart[2].price = 50000;

  sparepart[3].name = "Shell Advance AX7 Matic 1L";
  sparepart[3].stock = 80; 
  sparepart[3].price = 65000;

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
        registerMenu(userPtr, currentUser);
      }
      break;
      case 2 : {
        loginMenu(userPtr, sparepartPtr, currentUser, currentSparepart);
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

void insertionSort(Sparepart *sparepart[], int &currentSparepart) {
  for (int i = 1; i < currentSparepart; i++) {
    Sparepart* key = sparepart[i];
    int j = i - 1;
    while (j >= 0 && sparepart[j]->name < key->name) {
      sparepart[j + 1] = sparepart[j];
      j = j - 1;
    }
    sparepart[j + 1] = key;
  }
}

void selectionSort(Sparepart *sparepart[], int &currentSparepart) {
  for (int i = 0; i < currentSparepart - 1; i++) {
    int min = i;
    for (int j = i + 1; j < currentSparepart; j++) {
      if (sparepart[j]->price < sparepart[min]->price){
        min = j;
      }
    }
    Sparepart* temp = sparepart[i];
    sparepart[i] = sparepart[min];
    sparepart[min] = temp;
  }
}

void bubbleSort(Sparepart *sparepart[], int &currentSparepart) {
  for (int i = 0; i < currentSparepart; i++) {
    for (int j = 0; j < (currentSparepart - i - 1); j++) {
      if (sparepart[j]->stock > sparepart[j + 1]->stock) {
        // Menukar elemen jika elemen sebelumnya lebih besar
        Sparepart* temp = sparepart[j];
        sparepart[j] = sparepart[j + 1];
        sparepart[j + 1] = temp;
      }
    }
  }
}

bool validateString(string &valueOne, string &valueTwo) {
  if (valueOne.empty() || valueTwo.empty() ){
    return true;
  } else {
    return false;
  }
}

bool validateString(string &value) {
  if (value.empty()){
    return true;
  } else {
    return false;
  }
}

void tambahSparepart(Sparepart *sparepart[], int &currentSparepart) {
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
    sparepart[currentSparepart]->name = inputName;
    sparepart[currentSparepart]->stock = inputQuantity;
    sparepart[currentSparepart]->price = inputPrice;
    currentSparepart++;
    cout << "\nBerhasil menambahkan sparepart!" << endl;
  }
}

void tampilkanSparepart(Sparepart *sparepart[], int &currentSparepart) {
  
  if (currentSparepart == 1) {
    printSparepart(sparepart, currentSparepart);
  } else {
    int inputUser;

    // Menu Tampilkan
    cout << "\nTAMPILKAN SPAREPART" << endl;
    cout << "1. Sort by Name (Z-A)" << endl;
    cout << "2. Sort by Price (Ascending)" << endl;
    cout << "3. Sort by Stock (Ascending)" << endl;
    cout << "Masukkan pilihan Anda : ";
    cin >> inputUser;
  
    switch (inputUser) {
      case 1:
        insertionSort(sparepart, currentSparepart);
        cout << endl << "Sort by Name (Z-A)" << endl;
        printSparepart(sparepart, currentSparepart);
        break;
      case 2:
        selectionSort(sparepart, currentSparepart);
        cout << endl << "Sort by Price (Ascending)" << endl;
        printSparepart(sparepart, currentSparepart);
        break;
      case 3:
        bubbleSort(sparepart, currentSparepart);
        cout << endl << "Sort by Stock (Ascending)" << endl;
        printSparepart(sparepart, currentSparepart);
        break;
      default:
        // Menampilkan pesan kesalahan input pilihan
        cout << "Maaf, pilihan Anda tidak tersedia!" << endl;
        break;
    }
  }
  
}

void printSparepart(Sparepart *sparepart[], int &currentSparepart) {
  // Menampilkan header tabel
  cout << "+----+------------------------------------------+--------+-------------+" << endl;
  cout << "| No | Sparepart                                | Stok   | Harga       |" << endl;
  cout << "+----+------------------------------------------+--------+-------------+" << endl;

  // Menampilkan data sparepart dalam tabel
  for (int i = 0; i < currentSparepart; i++) {
    cout << "| " << i + 1;
    i + 1 < 10 ? cout << "  " : cout << " ";
    cout << "| " << sparepart[i]->name;
    for (int j = sparepart[i]->name.length(); j < 40; j++) {
      cout << " ";
    }
    cout << " | " << sparepart[i]->stock;
    if (sparepart[i]->stock < 10 ) {
      cout << "     ";
    } else if (sparepart[i]->stock < 100) {
      cout << "    ";
    } else {
      cout << "   ";
    }
    cout << " | " << sparepart[i]->price;
    if (sparepart[i]->price < 10000) {
      cout << "       ";
    } else if (sparepart[i]->price < 100000) {
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

void ubahStokSparepart(Sparepart *sparepart[], int &currentSparepart) {
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
      sparepart[indexSparepart - 1]->stock = newStcok;
      cout << "Berhasil mengubah stok!" << endl;
    }
  } else {
    cout << "Nomor sparepart tidak valid" << endl;
  }
}

void hapusSparepart(Sparepart *sparepart[], int &currentSparepart) {
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

void mainMenu(Sparepart *sparepart[], int &currentSparepart) {
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
          tambahSparepart(sparepart, currentSparepart);
        } else {
          cout << "Tidak bisa menambahkan sparepart karena inventaris sudah penuh!" << endl;
        }
        break;
      case 2:
        if (currentSparepart == 0) {
          cout << "Tidak ada sparepart yang dapat ditampilkan!" << endl;
        } else {
          tampilkanSparepart(sparepart, currentSparepart);
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
          printSparepart(sparepart, currentSparepart);

          // Mengubah stok sparepart
          ubahStokSparepart(sparepart, currentSparepart);
        }

        break;
      case 4:
        // Delete Sparepart
        cout << "\nHAPUS SPAREPART" << endl;
        if (currentSparepart == 0) {
          cout << "Tidak ada sparepart yang bisa dihapus!" << endl;
        } else {
          // Menampilkan sparepart
          printSparepart(sparepart, currentSparepart);
          
          //Melakukan hapus sparepart
          hapusSparepart(sparepart, currentSparepart);
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

void registerMenu(User *user[], int &currentUser) {
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
    user[currentUser]->username = usernameRegister;
    user[currentUser]->password = passwordRegister;
    currentUser++;
    cout << "\nRegister Berhasil!" << endl;
  }
}

void loginMenu(User *user[], Sparepart *sparepart[], int &currentUser, int &currentSparepart) {
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
      if (user[i]->username == usernameLogin && user[i]->password == passwordLogin) {
        // Jika username dan password ditemukan ubah variable isExist
        isExist = true;
      }
    }
    
    if (isExist) {
      mainMenu(sparepart, currentSparepart);
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



