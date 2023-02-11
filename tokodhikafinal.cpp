#include <iostream>
#include <vector>
#include <map>

using namespace std;

std::vector< int > total;
std::vector< string > salesname;
std::vector< int > jumlah;
std::vector< string > namapelanggan;


int menuid[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
string menuname[] = {"Nasi Goreng", "Mie Goreng","Bakso", "Es Teh", "Es Jeruk", "Es Soda", "Kopi", "Teh", "Jus Alpukat", "Jus Mangga"};
string menucategory[] = {"Makanan", "Makanan", "Makanan", "Minuman", "Minuman", "Minuman", "Minuman", "Minuman", "Minuman", "Minuman",};
int menuprice[] = {12000, 10000, 15000, 4000, 6000, 7000, 5000, 4000, 8000, 8000};


//string namapelanggan[];
//string salesname[];
//int jumlah[];
//int total[];

void display_menu() {
    for (int i = 0; i < 10; i++){
        cout << "ID Menu: " << menuid[i] << endl;
        cout << "Nama Menu: " << menuname[i] << endl;
        cout << "Kategori: " << menucategory[i] << endl;
        cout << "Harga: " << menuprice[i] << endl;
    }

}

int main() {
    int choice;
    while (true) {
        cout << "Pemilik Toko:" << endl;
        cout << "1. Pelanggan masuk" << endl;
        cout << "2. Tutup" << endl;
        cout << "Masukkan pilihan Anda (1/2): ";
        cin >> choice;
        if (choice == 2) {
            if (!namapelanggan.empty()) {
                for (int i = 0; i < 10; i++){
                    cout << (i + 1) << ". " << "Nama Pelanggan: " << namapelanggan[i] << endl;
                    cout << "Nama Menu: " << salesname[i] << endl;
                    cout << "Jumlah: " << jumlah[i] << endl;
                    cout << "Total Harga: " << total[i] << endl;
                }

            } else {
                cout << "Tidak Ada Penjualan" << endl;
            }
            break;
        } else {
            string customer_name;
            cout << "Masukkan nama pelanggan: ";
            cin >> customer_name;
            bool pelanggan = true;
            while (pelanggan) {
                cout << "Pelanggan:" << endl;
                cout << "1. Lihat Menu" << endl;
                cout << "2. Beli Makanan/Minuman" << endl;
                cout << "3. Keluar" << endl;
                int choicep;
                cout << "Masukkan pilihan Anda (1/2/3): ";
                cin >> choicep;
                if (choicep == 1){
                    display_menu();
                } else if (choicep == 2){
                    int idmakanan;
                    int quantity;
                    cout << "Masukkan ID menu: ";
                    cin >> idmakanan;
                    if (idmakanan < 11){
                        cout << "Masukkan Jumlah: ";
                        cin >> quantity;
                        jumlah.push_back(quantity);
                        namapelanggan.push_back(customer_name);
                        salesname.push_back(menuname[idmakanan - 1]);
                        total.push_back(menuprice[idmakanan-1] * quantity);
                    } else {
                        cout << "Barang tidak ada" << endl;

                    }

                } else if (choicep == 3){
                    pelanggan = false;
                }
            }
        }
    }
}
