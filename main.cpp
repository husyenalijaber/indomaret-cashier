#include <iostream>
#include <iomanip>

using namespace std;

int pilihan, total = 0, bayar;
string items[6] = {"INDOMIE RDG", "INDOMIE STO", "INDOMIE KOYA", 
                   "INDOMIE BWG", "INDOMIE KLD", "SB MIDI REG"};
int harga[6] = {3000, 3000, 2900, 2900, 2900, 500};
int jumlah[6] = {0, 0, 0, 0, 0, 0};

void menu() {
    cout << "Selamat datang di Indomaret, silahkan pilih menu yang anda inginkan\n\n";
    cout << "1. INDOMIE RDG 91G  - Rp.3000" << endl;
    cout << "2. INDOMIE STO M17  - Rp.3000" << endl;
    cout << "3. INDOMIE KOYA75G  - Rp.2900" << endl;
    cout << "4. INDOMIE BWG 69G  - Rp.2900" << endl;
    cout << "5. INDOMIE KLD 72G  - Rp.2900" << endl;
    cout << "6. SB MIDI REG L    - Rp.500"  << endl;
    cout << "7. Selesai" << endl;
}

void fpembelian() {
    do {
        cout << "Masukkan nomor pilihan: ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 6) {
            cout << "Jumlah barang: ";
            cin >> jumlah[pilihan - 1];
            total += harga[pilihan - 1] * jumlah[pilihan - 1];
        } else if (pilihan != 7) {
            cout << "Pilihan anda salah!" << endl;
        }
    } while (pilihan != 7);
}

void cetakStruk() {
    cout << "\n          JAVAMART          " << endl;
    cout << "      JL. RAYA NO. 123       " << endl;
    cout << "       TELP: 08123456789      " << endl;
    cout << "----------------------------------------" << endl;
    cout << "ITEM          QTY  HARGA     SUBTOTAL  " << endl;
    cout << "----------------------------------------" << endl;
    
    for (int i = 0; i < 6; i++) {
        if (jumlah[i] > 0) {
            cout << left << setw(13) << items[i] 
                 << right << setw(3) << jumlah[i] << "  " 
                 << setw(6) << harga[i] << "   " 
                 << setw(7) << harga[i] * jumlah[i] << endl;
        }
    }

    cout << "----------------------------------------" << endl;
    cout << "TOTAL                   Rp. " << total << endl;

    do {
        cout << "TUNAI                   Rp. ";
        cin >> bayar;
        if (bayar < total) {
            cout << "Uang tidak mencukupi! Masukkan jumlah yang benar." << endl;
        }
    } while (bayar < total);

    cout << "KEMBALI                 Rp. " << bayar - total << endl;
    cout << "----------------------------------------" << endl;
    cout << "TERIMA KASIH ATAS KUNJUNGAN ANDA" << endl;
    cout << "  SIMPAN BON SEBAGAI BUKTI BELI  " << endl;
}

int main() {
    menu();
    fpembelian();
    cetakStruk();
}
