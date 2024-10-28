#include <iostream>
using namespace std;

int main()
{
    // Login
    cout << "Selamat Datang di Permainan Tebak Angka" << endl;
    cout << "Silahkan Login Terlebih Dahulu!" << endl;
    string nama, nim;
    int check = 0;
    cout << "Masukkan Nama dan NIM" << endl;

    do
    {
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> nim;
        if (nama == "Rafi" && nim == "148")
        {
            cout << "Login Berhasil!" << endl;
            break;
        }
        check++;
    } while (check < 3);
    if (check >= 3)
    {
        cout << "Login Gagal! Nama atau NIM yang anda input salah!" << endl;
        return 0;
    }

    string menu1, menu2;
    int pilihanmenu;

    // Menu
    cout << "\n===== Menu Utama =====" << endl;
    cout << "1. Game Tebak Angka" << endl;
    cout << "2. Keluar" << endl;
    cout << "Silahkan Pilih Salah Satu Menu : " << endl;
    cin >> pilihanmenu;

    if (pilihanmenu == 1)
    {
        int angka_tebak;
        int angka_benar = 8;
        cout << "Selamat Datang di Permainan Tebak Angka" << endl;
        cout << "Tebak Angka dari (1 hingga 10)" << endl;
        do
        {
            cout << "Masukkan Angka: ";
            cin >> angka_tebak;
            if (angka_tebak > angka_benar)
            {
                cout << "Angkanya Terlalu Besar!" << endl;
            }
            else if (angka_tebak < angka_benar)
            {
                cout << "Angkanya Terlalu Kecil!" << endl;
            }
            else
            {
                cout << "Selamat!, Tebakan Anda Benar! Angkanya adalah: " << angka_benar << endl;
                break;
            }

        } while (angka_tebak = angka_benar);
        return 0;
    }
    else if (pilihanmenu == 2)
    {
        cout << "\nKeluar dari program...";
        return 0;
    }
    else
    {
        cout << "\nPilihan tidak valid!" << endl;
        cout << "Keluar dari program...";
        return 0;
    }
}
