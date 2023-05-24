/* Menerapkan tugas sebelumnya untuk membuat tugas berikut.

Simpan data inputan dalam file dengan nama bebasEsimpan agar dapat dibaca, tambahkan fungsi baca.

Ketika saat baca, semua data pada memori untuk sementara discard, pastikan hanya data yang telah dibaca.
Sebagai file input output dalam format CSV, buat satu baris berisi data untuk satu kasus. */

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


void save_data(struct Data* data, int num_data, const char* filename) {
    int i;
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Gagal membuka file %s.\n", filename);
        return;
    }

    for (i = 0; i < num_data; i++) {
        fprintf(file, "%s,%s,%s,%s\n", data[i].Nama, data[i].Alamat, data[i].TanggalLahir, data[i].NomorTelepon);
    }

    fclose(file);

    printf("Data berhasil disimpan dalam file %s.\n", filename);
}

void load_data(struct Data** data, int* num_data, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file %s.\n", filename);
        return;
    }

    // Hitung jumlah baris/data dalam file
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    // Alokasikan memori untuk data
    *data = (struct Data*)malloc(count * sizeof(struct Data));
    if (*data == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        fclose(file);
        return;
    }

    // Kembali ke awal file
    fseek(file, 0, SEEK_SET);

    // Baca data dari file
    char line[MAX_NAMA_LENGTH + MAX_ALAMAT_LENGTH + MAX_TANGGAL_LAHIR_LENGTH + MAX_NOMOR_TELEPON_LENGTH + 4];  // +4 untuk koma dan newline
    int index = 0;
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%[^,],%[^,],%[^,\n]", (*data)[index].Nama, (*data)[index].Alamat, (*data)[index].TanggalLahir, (*data)[index].NomorTelepon);
        index++;
    }

    *num_data = count;

    fclose(file);

    printf("Data berhasil dimuat dari file %s.\n", filename);
}

int main() {
    struct Data* data = NULL;
    int num_data = 0;
    int i;

    int choice;
    do {
        printf("Menu:\n");
        printf("1. Tambah Data\n");
        printf("2. Tampilkan Semua Data\n");
        printf("3. Tampilkan Data Tunggal\n");
        printf("4. Ubah Data\n");
        printf("5. Hapus Data\n");
        printf("6. Simpan Data ke File\n");
        printf("7. Muat Data dari File\n");
        printf("8. Selesai\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice) {
            case 1:  // Tambah Data
                data = (struct Data*)realloc(data, (num_data + 1) * sizeof(struct Data));
                if (data == NULL) {
                    printf("Gagal mengalokasikan memori.\n");
                    break;
                }
                input_data(data, num_data);
                num_data++;
                break;
            case 2:  // Tampilkan Semua Data
                if (num_data > 0) {
                    for (i = 0; i < num_data; i++) {
                        output_data(data, i);
                    }
                } else {
                    printf("Tidak ada data yang tersedia.\n");
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
            case 4:  // Ubah Data
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
            case 5:  // Hapus Data
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
            case 6:  // Simpan Data ke File
                if (num_data > 0) {
                    char filename[256];
                    printf("Masukkan nama file untuk menyimpan data: ");
                    scanf("%255s", filename);
                    save_data(data, num_data, filename);
                } else {
                    printf("Tidak ada data yang tersedia.\n");
                }
                break;
            case 7:  // Muat Data dari File
                if (num_data > 0) {
                    printf("Data yang ada akan dihapus. Apakah Anda yakin? (y/n): ");
                    char confirm;
                    scanf(" %c", &confirm);
                    if (confirm == 'y' || confirm == 'Y') {
                        free(data);
                        data = NULL;
                        num_data = 0;
                    } else {
                        break;
                    }
                }

                char filename[256];
                printf("Masukkan nama file untuk memuat data: ");
                scanf("%255s", filename);
                load_data(&data, &num_data, filename);
                break;
            case 8:  // Selesai
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }

        printf("\n");
    } while (choice != 8);

    // Dealokasi memori
    if (data != NULL) {
        free(data);
        data = NULL;
    }

    return 0;
}
