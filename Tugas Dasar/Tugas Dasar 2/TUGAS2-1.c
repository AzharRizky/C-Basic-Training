/* Definisikan struktur yang memiliki 4 item yaitu Nama, Alamat, Tanggal Lahir, Nomor Telepon,
Inputlah data pada masing-masing item.

Dan, jumlah karakter string maksimal, untuk nama 10 karakter Full-width, untuk alamat 64 karakter Full-width, untuk tanggal lahir 10 karakter half-width, nomor telpon 16 karakter half-width.

Karena tentu saja Nama merupakan item yang diperlukan, maka penting untuk dimasukkan.
Untuk Tanggal Lahir dipisahkan dengan half-width, slash, Karakter angka selain half-width dan slash selain half-width adalah error.
Untuk Tanggal Lahir, keabsahan tanggal tidak dipertimbangkan.
Untuk Nomor Telpon, dipisahkan dengan hyphen, karakter angka dan hyphen selain half-width adalah error. */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

int main() {
    struct Data data;

    printf("Masukkan Nama (maksimal 10 karakter Full-width): ");
    scanf("%10s", data.Nama);

    printf("Masukkan Alamat (maksimal 64 karakter Full-width): ");
    scanf(" %[^\n]", data.Alamat);

    while (1) {
        printf("Masukkan Tanggal Lahir (format: DD/MM/YYYY): ");
        scanf("%10s", data.TanggalLahir);

        if (isValidTanggalLahir(data.TanggalLahir)) {
            break;
        } else {
            printf("Error: Tanggal Lahir tidak valid. Coba lagi.\n");
        }
    }

    while (1) {
        printf("Masukkan Nomor Telepon (format: XXXX-XXXX-XXXX): ");
        scanf("%16s", data.NomorTelepon);

        if (isValidNomorTelepon(data.NomorTelepon)) {
            break;
        } else {
            printf("Error: Nomor Telepon tidak valid. Coba lagi.\n");
        }
    }

    printf("\nData yang dimasukkan:\n");
    printf("Nama: %s\n", data.Nama);
    printf("Alamat: %s\n", data.Alamat);
    printf("Tanggal Lahir: %s\n", data.TanggalLahir);
    printf("Nomor Telepon: %s\n", data.NomorTelepon);

    return 0;
}