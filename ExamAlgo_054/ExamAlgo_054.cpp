#include <iostream>
#include <string>
using namespace std;

const int MAX_MAHASISWA = 100;

struct Queue {
    int arr[MAX_MAHASISWA];
    int front;
    int rear;
    int size;
    int maxSize;
    int NIM[MAX_MAHASISWA];
    string nama[MAX_MAHASISWA];
    int tahunMasuk[MAX_MAHASISWA];
};

Queue* createQueue(int maxSize) {
    Queue* queue = new Queue();
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    queue->maxSize = maxSize;
    return queue;
}

bool isQueueEmpty(Queue* queue) {
    return (queue->size == 0);
}

bool isQueueFull(Queue* queue) {
    return (queue->size == queue->maxSize);
}

void enqueue(Queue* queue, int nim, string nama, int tahunMasuk) {
    if (isQueueFull(queue)) {
        cout << "Tidak dapat menambahkan elemen. Queue penuh.\n";
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_MAHASISWA;
    queue->arr[queue->rear] = nim;
    queue->NIM[queue->rear] = nim;
    queue->nama[queue->rear] = nama;
    queue->tahunMasuk[queue->rear] = tahunMasuk;
    queue->size++;
}

void dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        cout << "Kosong, tidak dapat menghapus elemen.\n";
        return;
    }
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    else {
        queue->front = (queue->front + 1) % MAX_MAHASISWA;
    }
    queue->size--;
}

void tampilkanSemuaMahasiswa(Queue* queue) {
    if (isQueueEmpty(queue)) {
        cout << "Queue kosong.\n";
        return;
    }
    cout << "Isi Queue: ";
    int index = queue->front;
    while (index != queue->rear) {
        cout << "NIM: " << queue->NIM[index] << ", Nama: " << queue->nama[index] << ", Tahun Masuk: " << queue->tahunMasuk[index] << endl;
        index = (index + 1) % MAX_MAHASISWA;
    }
    cout << "NIM: " << queue->NIM[index] << ", Nama: " << queue->nama[index] << ", Tahun Masuk: " << queue->tahunMasuk[index] << endl;
}

int getFront(Queue* queue) {
    if (isQueueEmpty(queue)) {
        cout << "Queue kosong. Tidak ada elemen yang dapat ditemukan.\n";
        return -1;
    }
    return queue->arr[queue->front];
}

int main() {
    Queue* queue = createQueue(100);

    int choice;
    int nim, tahunMasuk;
    string nama;
    int pilihan;
    do {
        cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Tampilkan Semua Mahasiswa" << endl;
        cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
        cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
        case 1:
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan Nama: ";
            cin >> nama;
            cout << "Masukkan Tahun Masuk: ";
            cin >> tahunMasuk;
            enqueue(queue, nim, nama, tahunMasuk);
            break;
        case 2:
            tampilkanSemuaMahasiswa(queue);
            break;
        case 3:
            algorithmacariMahasiswaByNIM();
            break;
        case 4:
            algorithmaSortByTahunMasuk();
            break;
        case 5:
            cout << "Terima kasih! Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
        cout << endl;
    } while (pilihan != 5);

    return 0;
}



//2. queue using array

//3. stack adalah cara menyimpan data dengan cara ditumpuk (LIFO), menggunakan 2 oprasi push(menambahkan data) dan pop(menghapus data paling atas)
//3. Queue adalah cara menyimpan data dengan cara ditumpuk (FIFO) first in first out, menggunakan 2 operasi insertt dan delete, memiliki elemen rear dan front.

//4. stack digunakan biasanya untuk membuat sebuah output atau program yang jika pemogramnya ingin menambahkan dan menghapusnya berdasarkan masuk terakhir namun yang akan terhapus yang data pertama yang masuk

//5a. 5
//5b. salah, benar, benar