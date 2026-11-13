#include <iostream>
#include <string>
using namespace std;

struct QNode {
    string nama;
    QNode *next;
};

void enqueue(QNode *&front, QNode *&rear, string nama) {
    QNode *newNode = new QNode();
    newNode->nama = nama;
    newNode->next = nullptr;

    if (front == nullptr) {
        front = newNode;
    } else {
        rear->next = newNode;
    }
    rear = newNode;
}

void dequeue(QNode *&front, QNode *&rear) {
    if (front == nullptr) {
        cout << "Antrean kosong" << endl;
        return;
    }
    QNode *temp = front;
    cout << temp->nama << " dilayani dan meminjam buku" << endl;
    front = temp->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
}

void tampilAntrean(QNode *front) {
    if (front == nullptr) {
        cout << "Antrean kosong" << endl;
        return;
    }
    cout << "Antrean (depan -> belakang) : ";
    QNode *temp = front;
    while (temp != nullptr) {
        cout << temp->nama;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

struct SNode {
    int idBuku;
    string peminjam;
    SNode *next;
};

void push(SNode *&top, int idBuku, string peminjam) {
    SNode *nodeBaru = new SNode();
    nodeBaru->idBuku = idBuku;
    nodeBaru->peminjam = peminjam;
    nodeBaru->next = top;
    top = nodeBaru;
}

void pop(SNode *&top) {
    if (top == nullptr) {
        cout << "Riwayat kosong" << endl;
        return;
    }
    SNode *temp = top;
    cout << "Riwayat teratas dihapus : buku " << top->idBuku << " oleh " << top->peminjam << endl;
    top = top->next;
    delete temp;
}

void tampilRiwayat(SNode *top) {
    if (top == nullptr) {
        cout << "Riwayat pengembalian kosong" << endl;
        return;
    }
    cout << "Riwayat pengembalian (terbaru -> terlama):" << endl;
    SNode *temp = top;
    int no = 1;
    while (temp != nullptr) {
        cout << no << ". Buku " << temp->idBuku << " oleh " << temp->peminjam << endl;
        temp = temp->next;
        no++;
    }
}

struct Node {
    int data;
    Node *kiri;
    Node *kanan;
};

Node *tambah(Node *root, int data) {
    if (root == NULL) {
        root = new Node();
        root->data = data;
        root->kiri = NULL;
        root->kanan = NULL;
        return root;
    }

    if (data < root->data) {
        root->kiri = tambah(root->kiri, data);
    }
    if (data > root->data) {
        root->kanan = tambah(root->kanan, data);
    }
    return root;
}

bool cari(Node *root, int data) {
    Node *temp = root;
    while (temp != NULL) {
        cout << "Bandingkan " << data << " dengan " << temp->data << endl;
        if (data == temp->data) {
            return true;
        } else if (data < temp->data) {
            temp = temp->kiri;
        } else {
            temp = temp->kanan;
        }
    }
    return false;
}

void preOrder(Node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

int main() {
    QNode *front = nullptr;
    QNode *rear = nullptr;
    SNode *top = nullptr;
    Node *root = NULL;

    int pilihan;
    do {
        cout << "\n=== PERPUSTAKAAN ===" << endl;
        cout << "1. Tambah mahasiswa ke antrean (enqueue)" << endl;
        cout << "2. Proses peminjaman (dequeue)" << endl;
        cout << "3. Tampilkan antrean" << endl;
        cout << "4. Kembalikan buku (push riwayat)" << endl;
        cout << "5. Hapus riwayat terbaru (pop)" << endl;
        cout << "6. Tampilkan riwayat pengembalian" << endl;
        cout << "7. Tambah ID buku ke BST" << endl;
        cout << "8. Cari ID buku di BST" << endl;
        cout << "9. Traversal Pre-Order, In-Order, Post-Order" << endl;
        cout << "10. Isi data contoh" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih : ";
        cin >> pilihan;

        if (pilihan == 1) {
            string nama;
            cout << "Nama mahasiswa : "; getline(cin >> ws, nama);
            enqueue(front, rear, nama);
            cout << nama << " masuk antrean" << endl;
        } else if (pilihan == 2) {
            dequeue(front, rear);
        } else if (pilihan == 3) {
            tampilAntrean(front);
        } else if (pilihan == 4) {
            int id; string nama;
            cout << "ID buku : "; cin >> id;
            cout << "Nama pengembali : "; getline(cin >> ws, nama);
            push(top, id, nama);
            cout << "Buku " << id << " dikembalikan" << endl;
        } else if (pilihan == 5) {
            pop(top);
        } else if (pilihan == 6) {
            tampilRiwayat(top);
        } else if (pilihan == 7) {
            int id;
            cout << "ID buku : "; cin >> id;
            root = tambah(root, id);
            cout << "ID " << id << " diproses ke BST" << endl;
        } else if (pilihan == 8) {
            int id;
            cout << "ID buku dicari : "; cin >> id;
            if (cari(root, id)) cout << "Buku DITEMUKAN" << endl;
            else cout << "Buku TIDAK ditemukan" << endl;
        } else if (pilihan == 9) {
            if (root == NULL) {
                cout << "BST kosong" << endl;
            } else {
                cout << "Pre Order  : "; preOrder(root);  cout << endl;
                cout << "In Order   : "; inOrder(root);   cout << endl;
                cout << "Post Order : "; postOrder(root); cout << endl;
            }
        } else if (pilihan == 10) {
            string nama[] = {"Andi", "Budi", "Citra", "Dewi"};
            for (int i = 0; i < 4; i++) enqueue(front, rear, nama[i]);
            push(top, 105, "Eko");
            push(top, 102, "Fani");
            push(top, 110, "Gita");
            int ids[] = {50, 30, 70, 20, 40, 60, 80};
            for (int i = 0; i < 7; i++) root = tambah(root, ids[i]);
            cout << "Data contoh dimuat" << endl;
        }

        system("pause");
        system("cls");
    } while (pilihan != 0);

    return 0;
}
