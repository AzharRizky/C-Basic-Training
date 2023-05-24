/* Menerapkan tugas sebelumnya untuk membuat tugas berikut.

Buatlah agar dapat disortir/diurutkan
Metode Sortir, atur urutan menaik dan urutan menurun dari setiap item struktur.

--------------------------------------------------------------
Sample
--------------------------------------------------------------

*-*-*-*-*- Menu -*-*-*-*-*
1.Daftar
2.Tampilan satu kasus
3.Inputan tambahan
4.Ubah
5.Hapus
6.Sortir
----------
11.Simpan
12.Baca
----------
0.Akhir
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

>6

***Sortir Pilihan Item****
1. A:NamE B.ADDRESS C.Tanggal Lahir D.Nomor Telpon
>A
1:Urutan menaik 2:Urutan menurun 0:Cancel
>1

***Konfirmasi tombol Sortir***
1:NamE Urutan menaik
Apakah Anda Yakin? (��낵���ł����H)y/n

>y */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 11
#define MAX_ADDRESS_LENGTH 65
#define MAX_BIRTHDAY_LENGTH 11
#define MAX_PHONE_LENGTH 17

struct Data {
    char Name[MAX_NAME_LENGTH];
    char Address[MAX_ADDRESS_LENGTH];
    char Birthday[MAX_BIRTHDAY_LENGTH];
    char Phone[MAX_PHONE_LENGTH];
};

bool isValidBirthday(const char* Birthday) {
    int i;
    // Memastikan panjang tanggal lahir adalah 10 karakter
    if (strlen(Birthday) != 10) {
        return false;
    }

    // Memeriksa karakter setiap posisi tanggal lahir
    for (i = 0; i < 10; i++) {
        // Memastikan karakter pertama hingga kesembilan adalah angka atau '/'
        if (i < 9 && (Birthday[i] < '0' || Birthday[i] > '9') && Birthday[i] != '/') {
            return false;
        }

        // Memastikan karakter kesepuluh adalah angka
        if (i == 9 && (Birthday[i] < '0' || Birthday[i] > '9')) {
            return false;
        }
    }

    return true;
}

bool isValidPhone(char *number) {
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
    scanf("%10s", data[i].Name);

    printf("Masukkan Alamat (maksimal 64 karakter Full-width): ");
    scanf(" %[^\n]", data[i].Address);

    while (1) {
        printf("Masukkan Tanggal Lahir (format: DD/MM/YYYY): ");
        scanf("%10s", data[i].Birthday);

        if (isValidBirthday(data[i].Birthday)) {
            break;
        } else {
            printf("Error: Tanggal Lahir tidak valid. Coba lagi.\n");
        }
    }

    while (1) {
        printf("Masukkan Nomor Telepon (format: XXXX-XXXX-XXXX): ");
        scanf("%16s", data[i].Phone);

        if (isValidPhone(data[i].Phone)) {
            break;
        } else {
            printf("Error: Nomor Telepon tidak valid. Coba lagi.\n");
        }
    }
    
    printf("\n");

}

void output_data(struct Data* data, int i) {
    printf("Data ke-%d:\n", i + 1);
    printf("Nama: %s\n", data[i].Name);
    printf("Alamat: %s\n", data[i].Address);
    printf("Tanggal Lahir: %s\n", data[i].Birthday);
    printf("Nomor Telepon: %s\n", data[i].Phone);
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
        fprintf(file, "%s,%s,%s,%s\n", data[i].Name, data[i].Address, data[i].Birthday, data[i].Phone);
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
    char line[MAX_NAME_LENGTH + MAX_ADDRESS_LENGTH + MAX_BIRTHDAY_LENGTH + MAX_PHONE_LENGTH + 4];  // +4 untuk koma dan newline
    int index = 0;
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%[^,],%[^,],%[^,\n]", (*data)[index].Name, (*data)[index].Address, (*data)[index].Birthday, (*data)[index].Phone);
        index++;
    }

    *num_data = count;

    fclose(file);

    printf("Data berhasil dimuat dari file %s.\n", filename);
}

void sort_data(struct Data* data, int num_data, char item, int order) {
    int i, j;
    struct Data temp;

    // Bubble sort
    for (i = 0; i < num_data - 1; i++) {
        for (j = 0; j < num_data - i - 1; j++) {
            int compare;

            if (item == 'A') {
                compare = strcmp(data[j].Name, data[j + 1].Name);
            } else if (item == 'B') {
                compare = strcmp(data[j].Address, data[j + 1].Address);
            } else if (item == 'C') {
                compare = strcmp(data[j].Birthday, data[j + 1].Birthday);
            } else if (item == 'D') {
                compare = strcmp(data[j].Phone, data[j + 1].Phone);
            } else {
                printf("Item tidak valid.\n");
                return;
            }

            if ((compare > 0 && order == 1) || (compare < 0 && order == 2)) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    printf("Data berhasil diurutkan berdasarkan item '%c' dengan urutan %s.\n", item, (order == 1) ? "menaik" : "menurun");
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
        printf("6. Sortir Data\n");
        printf("7. Simpan Data ke File\n");
        printf("8. Muat Data dari File\n");
        printf("9. Selesai\n");
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
            case 6:  // Sortir Data
                if (num_data > 0) {
                    char item;
                    int order;

                    printf("***Sortir Pilihan Item***\n");
                    printf("A: Nama\n");
                    printf("B: Alamat\n");
                    printf("C: Tanggal Lahir\n");
                    printf("D: Nomor Telepon\n");
                    printf("Pilih item: ");
                    scanf(" %c", &item);

                    printf("1: Urutan menaik\n2: Urutan menurun\n0: Cancel\nPilih urutan: ");
                    scanf("%d", &order);

                    if (order != 0) {
                        sort_data(data, num_data, item, order);
                    }
                } else {
                    printf("Tidak ada data yang tersedia.\n");
                }
                break;
            case 7:  // Simpan Data ke File
                if (num_data > 0) {
                    char filename[256];
                    printf("Masukkan nama file untuk menyimpan data: ");
                    scanf("%255s", filename);
                    save_data(data, num_data, filename);
                } else {
                    printf("Tidak ada data yang tersedia.\n");
                }
                break;
            case 8:  // Muat Data dari File
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
            case 9:  // Selesai
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }

        printf("\n");
    } while (choice != 9);

    // Dealokasi memori
    if (data != NULL) {
        free(data);
        data = NULL;
    }

    return 0;
}
