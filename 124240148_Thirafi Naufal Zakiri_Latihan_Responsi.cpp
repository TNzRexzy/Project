#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Penulis
{
    string nama;
};

struct Buku
{
    int id;
    string judul;
    Penulis penulis;
    int harga;
};

const int MAX_BUKU = 100;
Buku daftarBuku[MAX_BUKU];
int jumlahBuku = 0;

void tambahBuku()
{
    int jumlah;
    cout << "Masukkan jumlah buku yang ingin diinput: ";
    cin >> jumlah;

    if (jumlahBuku + jumlah > MAX_BUKU)
    {
        cout << "Jumlah buku melebihi kapasitas maksimum.\n";
        return;
    }

    for (int i = 0; i < jumlah; i++)
    {
        Buku buku;
        cout << "Masukkan ID buku: ";
        cin >> buku.id;
        cin.ignore();
        cout << "Judul Buku: ";
        getline(cin, buku.judul);
        cout << "Nama Pengarang: ";
        getline(cin, buku.penulis.nama);
        cout << "Harga: ";
        cin >> buku.harga;

        daftarBuku[jumlahBuku++] = buku;
    }
}

void tampilkanDaftarBuku()
{
    cout << "\nDaftar Buku:\n";
    for (int i = 0; i < jumlahBuku; i++)
    {
        cout << "ID Buku: " << daftarBuku[i].id << endl;
        cout << "Judul: " << daftarBuku[i].judul << endl;
        cout << "Pengarang: " << daftarBuku[i].penulis.nama << endl;
        cout << "Harga: Rp" << daftarBuku[i].harga << endl;
        cout << endl;
    }
}

void ubahDataBuku()
{
    int id;
    cout << "Masukkan ID buku yang ingin diubah: ";
    cin >> id;

    for (int i = 0; i < jumlahBuku; i++)
    {
        if (daftarBuku[i].id == id)
        {
            cin.ignore();
            cout << "Judul Baru: ";
            getline(cin, daftarBuku[i].judul);
            cout << "Nama Pengarang Baru: ";
            getline(cin, daftarBuku[i].penulis.nama);
            cout << "Harga Baru: ";
            cin >> daftarBuku[i].harga;
            cout << "Data berhasil diperbarui.\n";
            return;
        }
    }
    cout << "Buku dengan ID tersebut tidak ditemukan.\n";
}

void hapusBuku()
{
    int id;
    cout << "Masukkan ID buku yang ingin dihapus: ";
    cin >> id;

    for (int i = 0; i < jumlahBuku; i++)
    {
        if (daftarBuku[i].id == id)
        {
            for (int j = i; j < jumlahBuku - 1; j++)
            {
                daftarBuku[j] = daftarBuku[j + 1];
            }
            jumlahBuku--;
            cout << "Buku berhasil dihapus.\n";
            return;
        }
    }
    cout << "Buku dengan ID tersebut tidak ditemukan.\n";
}

void hitungTotalHarga()
{
    int jumlah;
    cout << "Masukkan jumlah buku yang ingin dibeli: ";
    cin >> jumlah;
    int idBeli[MAX_BUKU];
    for (int i = 0; i < jumlah; i++)
    {
        cout << "Masukkan ID buku yang ingin dibeli: ";
        cin >> idBeli[i];
    }

    int totalHarga = 0;
    int penulisSama = 0;
    string penulisPertama = "";

    for (int i = 0; i < jumlah; i++)
    {
        for (int j = 0; j < jumlahBuku; j++)
        {
            if (daftarBuku[j].id == idBeli[i])
            {
                totalHarga += daftarBuku[j].harga;
                if (penulisPertama.empty())
                {
                    penulisPertama = daftarBuku[j].penulis.nama;
                    penulisSama = 1;
                }
                else if (daftarBuku[j].penulis.nama == penulisPertama)
                {
                    penulisSama++;
                }
            }
        }
    }

    if (penulisSama >= 2)
    {
        totalHarga -= totalHarga * 0.05;
        cout << "Diskon 5% diterapkan karena Anda membeli minimal dua buku dari pengarang yang sama.\n";
    }

    string kodeVoucher;
    cout << "Masukkan kode voucher (Kosongkan jika tidak ada): ";
    cin >> kodeVoucher;
    if (kodeVoucher == "JPYUM")
    {
        totalHarga -= totalHarga * 0.10;
        cout << "Diskon 10% dari voucher \"JPYUM\" diterapkan.\n";
    }

    cout << "Total Harga Setelah Diskon (jika ada): Rp" << totalHarga << endl;
}

int main()
{
    int pilihan;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Daftar Buku\n";
        cout << "3. Ubah Data Buku\n";
        cout << "4. Hapus Buku\n";
        cout << "5. Hitung Total Harga Pembelian dengan Diskon\n";
        cout << "6. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahBuku();
            break;
        case 2:
            tampilkanDaftarBuku();
            break;
        case 3:
            ubahDataBuku();
            break;
        case 4:
            hapusBuku();
            break;
        case 5:
            hitungTotalHarga();
            break;
        case 6:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Opsi tidak valid.\n";
        }
    } while (pilihan != 6);

    return 0;
}
