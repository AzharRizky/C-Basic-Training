/* Implementasikan tugas selama ini bukan dengan menggunakan fungsi scanf, namun dengan fungsi getchar.
Juga, membuatnya fungsional.

Untuk tugas‚P|‚V dan seterusnya,
Selama secara khusus tidak ditentukan, jangan gunakan fungsi scanf. */

/* 1-4 P
#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 100

int main() {
    char string[MAX_LENGTH];

    while (1) {
        printf("Masukkan sebuah string karakter: ");

        int c;
        int i = 0;

        // Membaca karakter-karakter satu per satu dari input
        while ((c = getchar()) != '\n') {
            // Cek apakah ada error atau tidak ada input yang diberikan
            if (c == EOF) {
                printf("Error: Tidak ada input yang diberikan. Program berakhir.\n");
                return 1;
            }

            // Cek apakah panjang string sudah mencapai batas maksimum
            if (i >= MAX_LENGTH - 1) {
                printf("Error: Panjang string melebihi batas maksimum. Program berakhir.\n");
                return 1;
            }

            // Menyimpan karakter ke dalam string
            string[i++] = c;
        }

        // Menambahkan null-terminator pada akhir string
        string[i] = '\0';

        // Menampilkan string
        printf("String yang diinput: %s\n", string);

        // Mengosongkan input buffer
        fflush(stdin);
    }

    return 0;
}
*/

/* 1-4 Q
#include <stdio.h>
#include <stdlib.h>

int main() {
    while (1) {
        printf("Masukkan sebuah angka: ");

        int c = getchar();

        // Mengosongkan input buffer
        while (getchar() != '\n');

        // Cek apakah ada error atau tidak ada input yang diberikan
        if (c == EOF) {
            printf("Error: Tidak ada input yang diberikan. Program berakhir.\n");
            return 1;
        }

        // Cek apakah karakter yang diinput adalah angka half-width
        if (c < '0' || c > '9') {
            printf("Error: Input yang diberikan bukan angka half-width. Coba lagi.\n");
            continue;
        }

        // Mengubah angka ke dalam bentuk biner dan mencetaknya
        printf("Angka biner: ");
        int i;
        for (i = 15; i >= 0; i--) {
            int bit = (c >> i) & 1;
            printf("%d", bit);
        }
        printf("\n");
    }

    return 0;
}
*/

/* 1-5 P
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char strings[10][MAX_LENGTH];
    char largestString[MAX_LENGTH];
    int i;

    while (1) {
        // Meminta input karakter string sebanyak 10 kali
        for (i = 0; i < 10; i++) {
            printf("Masukkan string ke-%d: ", i + 1);

            int c;
            int j = 0;

            // Membaca karakter-karakter satu per satu dari input
            while ((c = getchar()) != '\n') {
                // Cek apakah ada error atau tidak ada input yang diberikan
                if (c == EOF) {
                    printf("Error: Tidak ada input yang diberikan. Program berakhir.\n");
                    return 1;
                }

                // Cek apakah panjang string sudah mencapai batas maksimum
                if (j >= MAX_LENGTH - 1) {
                    printf("Error: Panjang string melebihi batas maksimum. Program berakhir.\n");
                    return 1;
                }

                // Menyimpan karakter ke dalam string
                strings[i][j++] = c;
            }

            // Menambahkan null-terminator pada akhir string
            strings[i][j] = '\0';
        }

        // Mencari string terbesar dengan menggunakan strcmp
        strcpy(largestString, strings[0]);

        for (i = 1; i < 10; i++) {
            if (strcmp(strings[i], largestString) > 0) {
                strcpy(largestString, strings[i]);
            }
        }

        // Menampilkan string terbesar
        printf("String terbesar: %s\n", largestString);

        // Mengosongkan input buffer
        fflush(stdin);
    }

    return 0;
}
*/

/* 1-5 Q
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numbers[10];
    int oddMax = 0;
    int i;

    while (1) {
        // Meminta input angka sebanyak 10 kali
        for (i = 0; i < 10; i++) {
            printf("Masukkan angka ke-%d: ", i + 1);

            int c = getchar();

            // Mengosongkan input buffer
            while (getchar() != '\n');

            // Cek apakah ada error atau tidak ada input yang diberikan
            if (c == EOF) {
                printf("Error: Tidak ada input yang diberikan. Program berakhir.\n");
                return 1;
            }

            // Cek apakah karakter yang diinput adalah angka half-width
            if (c < '0' || c > '9') {
                printf("Error: Input yang diberikan bukan angka half-width. Coba lagi.\n");
                i--;
                continue;
            }

            // Mengubah karakter menjadi angka dan menyimpannya
            numbers[i] = c - '0';
        }

        // Mencari angka ganjil terbesar
        oddMax = 0;
        for (i = 0; i < 10; i++) {
            if (numbers[i] % 2 != 0 && numbers[i] > oddMax) {
                oddMax = numbers[i];
            }
        }

        // Menampilkan angka ganjil terbesar
        if (oddMax == 0) {
            printf("Tidak ada angka ganjil. Coba lagi.\n");
        } else {
            printf("Angka ganjil terbesar: %d\n", oddMax);
            break;
        }
    }

    return 0;
}
*/

/* 1-6 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Mendeklarasikan variabel
    int num1_int, num2_int;
    float num1_float, num2_float;
    double num1_double, num2_double;

    while (1) {
        printf("Masukkan angka pertama: ");

        // Meminta input angka pertama
        int c = getchar();

        // Mengosongkan input buffer
        while (getchar() != '\n');

        // Cek apakah ada error atau tidak ada input yang diberikan
        if (c == EOF) {
            printf("Error: Tidak ada input yang diberikan. Program berakhir.\n");
            return 1;
        }

        // Cek apakah karakter yang diinput adalah angka half-width
        if (c < '0' || c > '9') {
            printf("Error: Input yang diberikan bukan angka half-width. Coba lagi.\n");
            continue;
        }

        // Mengubah karakter menjadi angka dan menyimpannya
        num1_int = c - '0';
        num1_float = (float) num1_int;
        num1_double = (double) num1_int;

        break;
    }

    while (1) {
        printf("Masukkan angka kedua: ");

        // Meminta input angka kedua
        int c = getchar();

        // Mengosongkan input buffer
        while (getchar() != '\n');

        // Cek apakah ada error atau tidak ada input yang diberikan
        if (c == EOF) {
            printf("Error: Tidak ada input yang diberikan. Program berakhir.\n");
            return 1;
        }

        // Cek apakah karakter yang diinput adalah angka half-width
        if (c < '0' || c > '9') {
            printf("Error: Input yang diberikan bukan angka half-width. Coba lagi.\n");
            continue;
        }

        // Mengubah karakter menjadi angka dan menyimpannya
        num2_int = c - '0';
        num2_float = (float) num2_int;
        num2_double = (double) num2_int;

        break;
    }

    // Operasi aritmatika
    int sum_int = num1_int + num2_int;
    int diff_int = num1_int - num2_int;
    int prod_int = num1_int * num2_int;
    int div_int = num1_int / num2_int;

    float sum_float = num1_float + num2_float;
    float diff_float = num1_float - num2_float;
    float prod_float = num1_float * num2_float;
    float div_float = num1_float / num2_float;

    double sum_double = num1_double + num2_double;
    double diff_double = num1_double - num2_double;
    double prod_double = num1_double * num2_double;
    double div_double = num1_double / num2_double;

    // Operasi OR dan AND
    int or_result = num1_int | num2_int;
    int and_result = num1_int & num2_int;

    // Menampilkan hasil operasi
    printf("=== Hasil Operasi ===\n");

    printf("Operasi dengan tipe int:\n");
    printf("Penjumlahan: %d\n", sum_int);
    printf("Pengurangan: %d\n", diff_int);
    printf("Perkalian: %d\n", prod_int);
    printf("Pembagian: %d\n", div_int);
    printf("Operasi OR: %d\n", or_result);
    printf("Operasi AND: %d\n", and_result);

    printf("Operasi dengan tipe float:\n");
    printf("Penjumlahan: %.2f\n", sum_float);
    printf("Pengurangan: %.2f\n", diff_float);
    printf("Perkalian: %.2f\n", prod_float);
    printf("Pembagian: %.2f\n", div_float);

    printf("Operasi dengan tipe double:\n");
    printf("Penjumlahan: %.2lf\n", sum_double);
    printf("Pengurangan: %.2lf\n", diff_double);
    printf("Perkalian: %.2lf\n", prod_double);
    printf("Pembagian: %.2lf\n", div_double);

    return 0;
}
