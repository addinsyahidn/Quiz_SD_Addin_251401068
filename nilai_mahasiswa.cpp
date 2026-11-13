#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nim;
    string nama;
    int nilai;
    Node *next;
};

void insertLast(Node *&head, Node *&tail, string nim, string nama, int nilai) {
    Node *newNode = new Node;
    newNode->nim = nim;
    newNode->nama = nama;
    newNode->nilai = nilai;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = head;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void tampilMahasiswa(Node *head) {
    if (head == nullptr) {
        cout << "Data mahasiswa kosong" << endl;
        return;
    }
    int no = 1;
    Node *temp = head;
    while (temp != nullptr) {
        cout << no << ". " << temp->nim << " | " << temp->nama << " | " << temp->nilai << endl;
        temp = temp->next;
        no++;
    }
}

void tambahNilai(int *&data, int &jumlah, int &kapasitas, int nilai) {
    if (jumlah == kapasitas) {
        int kapasitasBaru = kapasitas * 2;
        int *dataBaru = new int[kapasitasBaru];
        for (int i = 0; i < jumlah; i++) {
            dataBaru[i] = data[i];
        }
        delete[] data;
        data = dataBaru;
        kapasitas = kapasitasBaru;
        cout << "(Array diperbesar, kapasitas sekarang " << kapasitas << ")" << endl;
    }
    data[jumlah] = nilai;
    jumlah++;
}

void tampilArray(int data[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << "]" << endl;
}

void insertionSort(int data[], int n) {
    for (int i = 1; i < n; i++) {
        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

int linearSearch(Node *head, string target, Node *&hasil) {
    int index = 0;
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->nim == target) {
            hasil = temp;
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

int binarySearch(int data[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (data[mid] == target) {
            return mid;
        } else if (target < data[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    Node *head = nullptr;
    Node *tail = nullptr;

    int kapasitas = 2;
    int jumlah = 0;
    int *nilaiArr = new int[kapasitas];
    bool sudahUrut = false;

    int pilihan;
    do {
        cout << "\n=== SISTEM PENGELOLAAN NILAI MAHASISWA ===" << endl;
        cout << "1. Tambah mahasiswa" << endl;
        cout << "2. Tampilkan data mahasiswa" << endl;
        cout << "3. Urutkan nilai (Insertion Sort)" << endl;
        cout << "4. Cari mahasiswa berdasarkan NIM (Linear Search)" << endl;
        cout << "5. Cari nilai (Binary Search)" << endl;
        cout << "6. Isi data contoh" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih : ";
        cin >> pilihan;

        if (pilihan == 1) {
            string nim, nama;
            int nilai;
            cout << "NIM   : "; cin >> nim;
            cout << "Nama  : "; getline(cin >> ws, nama);
            cout << "Nilai : "; cin >> nilai;

            insertLast(head, tail, nim, nama, nilai);
            tambahNilai(nilaiArr, jumlah, kapasitas, nilai);
            sudahUrut = false;
            cout << "Data berhasil ditambahkan" << endl;

        } else if (pilihan == 2) {
            cout << "Data mahasiswa:" << endl;
            tampilMahasiswa(head);
            cout << "Array nilai : ";
            tampilArray(nilaiArr, jumlah);

        } else if (pilihan == 3) {
            if (jumlah == 0) {
                cout << "Data kosong" << endl;
            } else {
                cout << "Sebelum diurutkan : "; tampilArray(nilaiArr, jumlah);
                insertionSort(nilaiArr, jumlah);
                sudahUrut = true;
                cout << "Sesudah diurutkan : "; tampilArray(nilaiArr, jumlah);
            }

        } else if (pilihan == 4) {
            string nim;
            cout << "Masukkan NIM : "; cin >> nim;
            Node *hasil = nullptr;
            int pos = linearSearch(head, nim, hasil);
            if (pos != -1) {
                cout << "Data ditemukan pada urutan ke-" << pos + 1 << " : "
                     << hasil->nim << " | " << hasil->nama << " | " << hasil->nilai << endl;
            } else {
                cout << "Data tidak ditemukan" << endl;
            }

        } else if (pilihan == 5) {
            if (!sudahUrut) {
                cout << "Urutkan nilai dulu (menu 3) sebelum Binary Search" << endl;
            } else {
                int target;
                cout << "Masukkan nilai yang dicari : "; cin >> target;
                int hasil = binarySearch(nilaiArr, jumlah, target);
                if (hasil != -1) {
                    cout << "Nilai ditemukan pada indeks : " << hasil << endl;
                    cout << "Mahasiswa dengan nilai tersebut:" << endl;
                    Node *temp = head;
                    while (temp != nullptr) {
                        if (temp->nilai == target) {
                            cout << "- " << temp->nim << " | " << temp->nama << endl;
                        }
                        temp = temp->next;
                    }
                } else {
                    cout << "Nilai tidak ditemukan" << endl;
                }
            }

        } else if (pilihan == 6) {
            string nim[] = {"2411001", "2411002", "2411003", "2411004", "2411005"};
            string nama[] = {"Andi", "Budi", "Citra", "Dewi", "Eko"};
            int nilai[] = {78, 85, 92, 67, 85};
            for (int i = 0; i < 5; i++) {
                insertLast(head, tail, nim[i], nama[i], nilai[i]);
                tambahNilai(nilaiArr, jumlah, kapasitas, nilai[i]);
            }
            sudahUrut = false;
            cout << "5 data contoh ditambahkan" << endl;
        }

        system("pause");
        system("cls");

    } while (pilihan != 0);

    delete[] nilaiArr;
    return 0;
}
