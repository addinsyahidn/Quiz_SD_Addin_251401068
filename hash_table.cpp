#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

const int TABLE_SIZE = 20;

class HashTable {
    private:
        vector<pair<int, string>> table;
        vector<int> status;

        int hash1(int key) {
            return key % TABLE_SIZE;
        }

        int hash2(int key) {
            return 19 - (key % 19);
        }

    public:
        HashTable() {
            table.resize(TABLE_SIZE);
            status.resize(TABLE_SIZE, 0);
        }

        void insert(int key, string value) {
            int index = hash1(key);
            int step = hash2(key);
            int initialIndex = index;
            int percobaan = 1;
            int deletedIndex = -1;
            int deletedPercobaan = 0;

            while (true) {
                if (status[index] == 1 && table[index].first == key) {
                    table[index].second = value;
                    cout << "NIM " << key << " sudah ada, nama diperbarui" << endl;
                    return;
                }

                if (status[index] == 2 && deletedIndex == -1) {
                    deletedIndex = index;
                    deletedPercobaan = percobaan;
                }

                if (status[index] == 0) {
                    if (deletedIndex != -1) {
                        index = deletedIndex;
                        percobaan = deletedPercobaan;
                    }
                    table[index] = make_pair(key, value);
                    status[index] = 1;
                    cout << "Insert " << key << " (" << value << ") -> indeks " << index;
                    if (percobaan > 1) cout << "  [COLLISION, percobaan ke-" << percobaan << "]";
                    cout << endl;
                    return;
                }

                index = (index + step) % TABLE_SIZE;
                percobaan++;

                if (index == initialIndex) {
                    break;
                }
            }

            if (deletedIndex != -1) {
                table[deletedIndex] = make_pair(key, value);
                status[deletedIndex] = 1;
                cout << "Insert " << key << " (" << value << ") -> indeks " << deletedIndex
                     << " (slot bekas hapus)" << endl;
            } else {
                cout << "Tabel penuh, gagal insert " << key << endl;
            }
        }

        void search(int key) {
            int index = hash1(key);
            int step = hash2(key);
            int initialIndex = index;

            while (status[index] != 0) {
                if (status[index] == 1 && table[index].first == key) {
                    cout << "Data ditemukan di indeks " << index << " : " << table[index].second << endl;
                    return;
                }

                index = (index + step) % TABLE_SIZE;

                if (index == initialIndex) {
                    break;
                }
            }

            cout << "Data tidak ditemukan" << endl;
        }

        void remove(int key) {
            int index = hash1(key);
            int step = hash2(key);
            int initialIndex = index;

            while (status[index] != 0) {
                if (status[index] == 1 && table[index].first == key) {
                    status[index] = 2;
                    cout << "Data NIM " << key << " berhasil dihapus dari indeks " << index << endl;
                    return;
                }

                index = (index + step) % TABLE_SIZE;

                if (index == initialIndex) {
                    break;
                }
            }

            cout << "Data tidak ditemukan" << endl;
        }

        void display() {
            for (int i = 0; i < TABLE_SIZE; i++) {
                cout << setw(2) << i << " : ";

                if (status[i] == 1) {
                    cout << table[i].first << " - " << table[i].second;
                } else if (status[i] == 2) {
                    cout << "DELETED";
                } else {
                    cout << "EMPTY";
                }

                cout << endl;
            }
        }
};

int main() {
    HashTable ht;
    int pilihan;

    do {
        cout << "\n=== HASH TABLE MAHASISWA (Double Hashing) ===" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Remove" << endl;
        cout << "4. Display" << endl;
        cout << "5. Muat 16 data uji" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih : ";
        cin >> pilihan;

        if (pilihan == 1) {
            int nim; string nama;
            cout << "NIM  : "; cin >> nim;
            cout << "Nama : "; getline(cin >> ws, nama);
            ht.insert(nim, nama);
        } else if (pilihan == 2) {
            int nim;
            cout << "NIM : "; cin >> nim;
            ht.search(nim);
        } else if (pilihan == 3) {
            int nim;
            cout << "NIM : "; cin >> nim;
            ht.remove(nim);
        } else if (pilihan == 4) {
            ht.display();
        } else if (pilihan == 5) {
            int nim[] = {2024001, 2024002, 2024003, 2024021, 2024015, 2024041, 2024005, 2024006,
                         2024007, 2024008, 2024009, 2024010, 2024011, 2024012, 2024013, 2024014};
            string nama[] = {"Andi", "Budi", "Citra", "Dewi", "Eko", "Fani", "Gita", "Hadi",
                             "Intan", "Joko", "Kiki", "Lina", "Maman", "Nadia", "Omar", "Putri"};
            for (int i = 0; i < 16; i++) ht.insert(nim[i], nama[i]);
        }

        system("pause");
        system("cls");
    } while (pilihan != 0);

    return 0;
}
