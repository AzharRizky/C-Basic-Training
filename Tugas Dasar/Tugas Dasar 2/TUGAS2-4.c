/* Menerapkan tugas sebelumnya untuk membuat tugas berikut

Memori dialokasikan untuk setiap kasus, buatlah untuk memungkinkan penambahan data, penghapusan, dan perubahan. 
Memungkinkan untuk memilih tampilan daftar data, tampilan satu kasus, inputan tambahan, perubahan, penghapusan, dan end.
Dan, buatlah indeks data, urutan data yang mudah dipahami.

Pada saat akhir, membebaskan memori. */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NAMA_LENGTH 11
#define MAX_ALAMAT_LENGTH 65
#define MAX_TANGGAL_LAHIR_LENGTH 11
#define MAX_NOMOR_TELEPON_LENGTH 17

struct Data {
    char Nama[MAX_NAMA_LENGTH];
    char Alamat[MAX_ALAMAT_LENGTH];
    char TanggalLahir[MAX_TANGGAL_LAHIR_LENGTH];
    char NomorTelepon[MAX_NOMOR_TELEPON_LENGTH];
};

bool isValidTanggalLahir(const char* tanggalLahir) {
    int i;
    // Memastikan panjang tanggal lahir adalah 10 karakter
    if (strlen(tanggalLahir) != 10) {
        return false;
    }

    // Memeriksa karakter setiap posisi tanggal lahir
    for (i = 0; i < 10; i++) {
        // Memastikan karakter pertama hingga kesembilan adalah angka atau '/'
        if (i < 9 && (tanggalLahir[i] < '0' || tanggalLahir[i] > '9') && tanggalLahir[i] != '/') {
            return false;
        }

        // Memastikan karakter kesepuluh adalah angka
        if (i == 9 && (tanggalLahir[i] < '0' || tanggalLahir[i] > '9')) {
            return false;
        }
    }

    return true;
}

bool isValidNomorTelepon(char *number) {
    int i;
    int length = strlen(number);
    if (length != 14 || number[4] != '-' || number[9] != '-')
        return false;

    for (i = 0; i < length; i++) {
        if (i != 4 && i != 9 && !isdigit(number[i]))
            return false;
    }

    return true;
}

void input_data(struct Data* data, int i) {

    printf("Data ke-%d:\n", i + 1);

    printf("Masukkan Nama (maksimal 10 karakter Full-width): ");
    scanf("%10s", data[i].Nama);

    printf("Masukkan Alamat (maksimal 64 karakter Full-width): ");
    scanf(" %[^\n]", data[i].Alamat);

    while (1) {
        printf("Masukkan Tanggal Lahir (format: DD/MM/YYYY): ");
        scanf("%10s", data[i].TanggalLahir);

        if (isValidTanggalLahir(data[i].TanggalLahir)) {
            break;
        } else {
            printf("Error: Tanggal Lahir tidak valid. Coba lagi.\n");
        }
    }

    while (1) {
        printf("Masukkan Nomor Telepon (format: XXXX-XXXX-XXXX): ");
        scanf("%16s", data[i].NomorTelepon);

        if (isValidNomorTelepon(data[i].NomorTelepon)) {
            break;
        } else {
            printf("Error: Nomor Telepon tidak valid. Coba lagi.\n");
        }
    }
    
    printf("\n");

}

void output_data(struct Data* data, int i) {
    printf("Data ke-%d:\n", i + 1);
    printf("Nama: %s\n", data[i].Nama);
    printf("Alamat: %s\n", data[i].Alamat);
    printf("Tanggal Lahir: %s\n", data[i].TanggalLahir);
    printf("Nomor Telepon: %s\n", data[i].NomorTelepon);
    printf("\n");
}

int main() {
    int num_data = 0;
    int max_data = 10;
    int i;
    struct Data* data = (struct Data*)malloc(max_data * sizeof(struct Data));
    if (data == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1;
    }

    int choice;
    do {
        printf("Menu:\n");
        printf("1. Tambah Data\n");
        printf("2. Tampilkan Daftar Data\n");
        printf("3. Tampilkan Data Tunggal\n");
        printf("4. Perubahan Data\n");
        printf("5. Penghapusan Data\n");
        printf("6. Selesai\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Tambah Data
                if (num_data >= max_data) {
                    // Memperluas alokasi memori jika sudah mencapai batas
                    max_data += 10;
                    struct Data* temp = (struct Data*)realloc(data, max_data * sizeof(struct Data));
                    if (temp == NULL) {
                        printf("Gagal mengalokasikan memori.\n");
                        break;
                    }
                    data = temp;
                }
                input_data(data, num_data);
                num_data++;
                break;
            case 2:  // Tampilkan Daftar Data
                printf("=== Daftar Data ===\n");
                for (i = 0; i < num_data; i++) {
                    output_data(data, i);
                }
                break;
            case 3:  // Tampilkan Data Tunggal
                if (num_data > 0) {
                    int index;
                    printf("Masukkan indeks data yang ingin ditampilkan: ");
                    scanf("%d", &index);
                    if (index >= 0 && index < num_data) {
                        output_data(data, index);
                    } else {
                        printf("Indeks data tidak valid.\n");
                    }
                } else {
                    printf("Tidak ada data yang tersedia.\n");
                }
                break;
            case 4:  // Perubahan Data
                if (num_data > 0) {
                    int index;
                    printf("Masukkan indeks data yang ingin diubah: ");
                    scanf("%d", &index);
                    if (index >= 0 && index < num_data) {
                        input_data(data, index);
                    } else {
                        printf("Indeks data tidak valid.\n");
                    }
                } else {
                    printf("Tidak ada data yang tersedia.\n");
                }
                break;
            case 5:  // Penghapusan Data
                if (num_data > 0) {
                    int index;
                    printf("Masukkan indeks data yang ingin dihapus: ");
                    scanf("%d", &index);
                    if (index >= 0 && index < num_data) {
                        // Geser data ke kiri untuk menghapus data
                        for (i = index; i < num_data - 1; i++) {
                            memcpy(&data[i], &data[i + 1], sizeof(struct Data));
                        }
                        num_data--;
                        printf("Data berhasil dihapus.\n");
                    } else {
                        printf("Indeks data tidak valid.\n");
                    }
                } else {
                    printf("Tidak ada data yang tersedia.\n");
                }
                break;
            case 6:  // Selesai
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }

        printf("\n");
    } while (choice != 6);

    free(data);

    return 0;
}
