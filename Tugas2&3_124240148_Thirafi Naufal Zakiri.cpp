#include <iostream>
#include <string>
using namespace std;

const int max_motor = 10;

struct Motor
{
    string namaMotor;
    int stok;
};

// Tambah motor baru
void tambahMotor(Motor motorList[], int &jumlahMotor)
{
    if (jumlahMotor >= max_motor)
    {
        cout << "Kapasitas data motor penuh!\n";
        return;
    }

    cout << "Nama motor: ";
    cin.ignore();
    getline(cin, motorList[jumlahMotor].namaMotor);
    cout << "Jumlah stok: ";
    cin >> motorList[jumlahMotor].stok;
    jumlahMotor++;
    cout << "Motor berhasil ditambahkan!\n";
}

// Daftar motor
void tampilkanDataMotor(const Motor motorList[], int jumlahMotor)
{
    cout << "\nDaftar Motor di Dealer Kawasaki:\n";
    for (int i = 0; i < jumlahMotor; i++)
    {
        cout << "- " << motorList[i].namaMotor << " (Stok: " << motorList[i].stok << ")\n";
    }
}

// Cek stok motor
void cekStokMotor(const Motor motorList[], int jumlahMotor)
{
    string namaMotor;
    cout << "Nama motor yang ingin dicek: ";
    cin.ignore();
    getline(cin, namaMotor);

    for (int i = 0; i < jumlahMotor; i++)
    {
        if (motorList[i].namaMotor == namaMotor)
        {
            cout << "Stok " << namaMotor << ": " << motorList[i].stok << endl;
            return;
        }
    }
    cout << "Motor tidak ditemukan.\n";
}

int main()
{
    // Login
    cout << "Selamat Datang di Dealer Motor Kawasaki\nSilakan Login Terlebih Dahulu\n";
    string username, password;
    int check = 0;

    do
    {
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        if (username == "Rafi" && password == "148")
        {
            cout << "Login Berhasil!\n";
            break;
        }
        cout << "Login Gagal! Username atau Password salah.\n";
        check++;
    } while (check < 3);

    if (check >= 3)
    {
        cout << "Anda telah gagal login 3 kali. Program keluar.\n";
        return 0;
    }

    // Daftar motor
    Motor motorList[max_motor];
    int jumlahMotor = 0, pilihan;

    while (true)
    {
        cout << "\n=== Menu Dealer Motor Kawasaki ===\n";
        cout << "1. Tambah Motor\n2. Tampilkan Daftar Motor\n3. Cek Stok Motor\n4. Keluar\nPilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahMotor(motorList, jumlahMotor);
            break;
        case 2:
            tampilkanDataMotor(motorList, jumlahMotor);
            break;
        case 3:
            cekStokMotor(motorList, jumlahMotor);
            break;
        case 4:
            cout << "Keluar dari program.\n";
            return 0;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }
    }
    return 0;
}
