/* Definisikan struktur Tugas eebelunya sebagai array, kemudian masukkan 10 buah data dan output masing-masing. */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAMA_LENGTH 11
#define MAX_ALAMAT_LENGTH 65
#define MAX_TANGGAL_LAHIR_LENGTH 11
#define MAX_NOMOR_TELEPON_LENGTH 17
#define MAX_DATA_SIZE 10

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

int main() {
    struct Data data[MAX_DATA_SIZE];
    int i;

    for (i = 0; i < MAX_DATA_SIZE; i++) {
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

    printf("=== Data yang dimasukkan ===\n");
    for (i = 0; i < MAX_DATA_SIZE; i++) {
        printf("Data ke-%d:\n", i + 1);
        printf("Nama: %s\n", data[i].Nama);
        printf("Alamat: %s\n", data[i].Alamat);
        printf("Tanggal Lahir: %s\n", data[i].TanggalLahir);
        printf("Nomor Telepon: %s\n", data[i].NomorTelepon);
        printf("\n");
    }
    
    return 0;
}
