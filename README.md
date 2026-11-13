# Quiz_SD_Addin_251401068

## Identitas
- Nama  : _Addin Syahid Nugraha_
- NIM   : _251401068_

## Video Penjelasan
YouTube: _https://youtu.be/ti6SzqsxaCw_

## Struktur Folder
```
Quiz_SD_Addin_251401068/
├── README.md
├── nilai_mahasiswa.cpp   # Soal 1
├── perpustakaan.cpp      # Soal 2
├── rute_kampus.cpp       # Soal 3
└── hash_table.cpp        # Soal 4
```

## Deskripsi Program

**Soal 1 - Sistem Pengelolaan Nilai Mahasiswa (`nilai_mahasiswa.cpp`)**
Program mengelola data mahasiswa (NIM, Nama, Nilai).
- **Single Linked List** menyimpan data mahasiswa (`insertLast` dengan pointer `head` dan `tail`).
- **Dynamic Array** menyimpan kumpulan nilai. Kapasitas awal 2 dan digandakan otomatis saat penuh (alokasi array baru, salin data, `delete[]` array lama).
- **Insertion Sort** mengurutkan nilai dari terkecil ke terbesar.
- **Linear Search** mencari mahasiswa berdasarkan NIM pada linked list.
- **Binary Search** mencari nilai tertentu pada array yang sudah terurut. Program menolak pencarian jika data belum diurutkan, dan menampilkan semua mahasiswa yang memiliki nilai tersebut.

**Soal 2 - Sistem Antrean dan Pengelolaan Buku Perpustakaan (`perpustakaan.cpp`)**
Program membantu pengelolaan peminjaman dan pengembalian buku.
- **Queue** (linked list, `front` dan `rear`) untuk antrean mahasiswa peminjam dengan prinsip FIFO (`enqueue`, `dequeue`, tampil antrean).
- **Stack** (linked list, `top`) untuk riwayat pengembalian buku dengan prinsip LIFO (`push`, `pop`, tampil riwayat dari terbaru ke terlama).
- **Binary Search Tree** untuk menyimpan ID buku, dengan fitur tambah, cari (menampilkan setiap langkah perbandingan), serta traversal **Pre-Order**, **In-Order**, dan **Post-Order**.

**Soal 3 - Sistem Pencarian Rute di Lingkungan Kampus (`rute_kampus.cpp`)**
Program memodelkan kampus sebagai graph tidak berarah berbobot dengan 6 vertex (A-F) menggunakan **Adjacency Matrix**, sesuai tabel jarak pada soal.
- **BFS** (menggunakan queue) dan **DFS** (rekursif) dari vertex awal pilihan pengguna.
- **Dijkstra** untuk mencari jarak terpendek dari vertex awal ke vertex tujuan pilihan pengguna, lalu menampilkan rute yang dilalui beserta total jaraknya (rute direkonstruksi dari array `previous`).
- Input vertex divalidasi (hanya A-F, huruf kecil juga diterima).

**Soal 4 - Sistem Pengelolaan Data Mahasiswa dengan Hash Table (`hash_table.cpp`)**
Program menyimpan data mahasiswa dengan NIM sebagai key dan nama sebagai value.
- Ukuran tabel 20, penanganan collision dengan **Double Hashing**:
  `Hash1(key) = key % 20` dan `Hash2(key) = 19 - (key % 19)`.
- Setiap slot memiliki status: `0` kosong, `1` terisi, `2` dihapus (DELETED), sehingga pencarian tetap benar setelah penghapusan.
- Fitur **Insert** (menampilkan info collision dan percobaan ke-berapa, serta memperbarui nama jika NIM sudah ada), **Search**, **Remove**, dan **Display**.
- Menu 5 memuat **16 data uji** yang mencakup kondisi collision.

## Cara Menjalankan

**Gunakan program lewat menu.** Setiap program menampilkan menu angka. Ketik nomor menu lalu tekan Enter, ikuti perintah input yang muncul, dan ketik `0` untuk keluar. Setelah satu menu selesai, tekan sembarang tombol untuk kembali ke menu.

**Soal 1 - Nilai Mahasiswa**

| Menu | Fungsi |
|------|--------|
| 1 | Tambah mahasiswa (input NIM, Nama, Nilai) |
| 2 | Tampilkan data mahasiswa (linked list) dan array nilai |
| 3 | Urutkan nilai dengan Insertion Sort |
| 4 | Cari mahasiswa berdasarkan NIM (Linear Search) |
| 5 | Cari nilai (Binary Search), **harus menjalankan menu 3 dulu** |
| 6 | Isi 5 data contoh |
| 0 | Keluar |

Alur yang disarankan: `6` → `2` → `3` → `5` (masukkan nilai, misal 85) → `4` (masukkan NIM, misal 2411003).

**Soal 2 - Perpustakaan**

| Menu | Fungsi |
|------|--------|
| 1 | Tambah mahasiswa ke antrean (enqueue) |
| 2 | Proses peminjaman, mahasiswa terdepan dilayani (dequeue) |
| 3 | Tampilkan antrean |
| 4 | Kembalikan buku, simpan ke riwayat (push; input ID buku dan nama) |
| 5 | Hapus riwayat terbaru (pop) |
| 6 | Tampilkan riwayat pengembalian |
| 7 | Tambah ID buku ke BST |
| 8 | Cari ID buku di BST |
| 9 | Tampilkan traversal Pre-Order, In-Order, Post-Order |
| 10 | Isi data contoh (4 antrean, 3 riwayat, 7 ID buku di BST) |
| 0 | Keluar |

Alur yang disarankan: `10` → `3` → `2` → `3` → `6` → `9` → `8` (cari ID, misal 60).

**Soal 3 - Rute Kampus**

| Menu | Fungsi |
|------|--------|
| 1 | Tampilkan adjacency matrix |
| 2 | BFS (pilih vertex awal A-F) |
| 3 | DFS (pilih vertex awal A-F) |
| 4 | Dijkstra (pilih vertex awal dan vertex tujuan A-F) |
| 0 | Keluar |

Graph sudah terisi otomatis sesuai tabel soal. Input vertex berupa huruf A-F (huruf besar maupun kecil).

**Soal 4 - Hash Table**

| Menu | Fungsi |
|------|--------|
| 1 | Insert (input NIM dan Nama) |
| 2 | Search berdasarkan NIM |
| 3 | Remove berdasarkan NIM |
| 4 | Display seluruh isi tabel (indeks 0-19) |
| 5 | Muat 16 data uji (mencakup collision) |
| 0 | Keluar |

Alur yang disarankan: `5` → `4` → `3` (hapus NIM 2024041) → `4` → `2` (cari NIM 2024011).

## Contoh Hasil

**Soal 1** - menu 6 (isi data contoh), lalu menu 3 (urutkan) dan menu 5 (Binary Search nilai 85):
```
(Array diperbesar, kapasitas sekarang 4)
(Array diperbesar, kapasitas sekarang 8)
5 data contoh ditambahkan

Sebelum diurutkan : [ 78 85 92 67 85 ]
Sesudah diurutkan : [ 67 78 85 85 92 ]

Nilai ditemukan pada indeks : 2
Mahasiswa dengan nilai tersebut:
- 2411002 | Budi
- 2411005 | Eko
```
Linear Search NIM `2411003`: `Data ditemukan pada urutan ke-3 : 2411003 | Citra | 92`

**Soal 2** - menu 10 (isi data contoh):
```
Antrean (depan -> belakang) : Andi -> Budi -> Citra -> Dewi
Andi dilayani dan meminjam buku            (setelah dequeue, FIFO)

Riwayat pengembalian (terbaru -> terlama):
1. Buku 110 oleh Gita
2. Buku 102 oleh Fani
3. Buku 105 oleh Eko

Pre Order  : 50 30 20 40 70 60 80
In Order   : 20 30 40 50 60 70 80
Post Order : 20 40 30 60 80 70 50
```
Pencarian ID 60: `Bandingkan 60 dengan 50` → `Bandingkan 60 dengan 70` → `Bandingkan 60 dengan 60` → `Buku DITEMUKAN`

**Soal 3** - graph sesuai tabel pada soal:
```
BFS dari A : A B C D E F
DFS dari A : A B C D E F

Dijkstra A -> F
Rute         : A -> C -> B -> E -> F
Total jarak  : 9
```

**Soal 4** - menu 5 (muat 16 data uji). Data yang mengalami collision:
```
Insert 2024021 (Dewi)  -> indeks 12  [COLLISION, percobaan ke-2]
Insert 2024041 (Fani)  -> indeks 11  [COLLISION, percobaan ke-2]
Insert 2024011 (Maman) -> indeks 13  [COLLISION, percobaan ke-2]
Insert 2024012 (Nadia) -> indeks 14  [COLLISION, percobaan ke-3]
Insert 2024013 (Omar)  -> indeks 4   [COLLISION, percobaan ke-10]
Insert 2024014 (Putri) -> indeks 0   [COLLISION, percobaan ke-8]
```
Isi tabel setelah menu 5 (menu 4):
```
 0 : 2024014 - Putri      10 : 2024010 - Lina
 1 : 2024001 - Andi       11 : 2024041 - Fani
 2 : 2024002 - Budi       12 : 2024021 - Dewi
 3 : 2024003 - Citra      13 : 2024011 - Maman
 4 : 2024013 - Omar       14 : 2024012 - Nadia
 5 : 2024005 - Gita       15 : 2024015 - Eko
 6 : 2024006 - Hadi       16-19 : EMPTY
 7 : 2024007 - Intan
 8 : 2024008 - Joko
 9 : 2024009 - Kiki
```
Pengujian penghapusan: hapus NIM `2024041` (Fani) → indeks 11 menjadi `DELETED`. Pencarian NIM `2024011` (Maman, yang melewati indeks 11 saat probing) tetap ditemukan di indeks 13.

## Catatan
- Program menggunakan `system("pause")` dan `system("cls")` sehingga paling sesuai dijalankan di **Windows**. Di Linux/macOS, ganti dengan `system("clear")` dan hapus/ganti `system("pause")` (atau cukup abaikan agar layar tidak dibersihkan).
- Semua program ditulis dalam C++ standar dan masing-masing berdiri sendiri (satu file per soal).
- Setiap program menyediakan menu "isi data contoh" agar pengujian dapat dilakukan dengan cepat saat demo video.
