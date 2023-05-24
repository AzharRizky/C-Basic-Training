/* Buatlah program yang memiliki fungsi di bawah ini.

Fungsi
Pertama-tama masukkan karakter string referensi.
Setelah itu, masukkan karakter string dan periksa apakah sesuai dengan karakter string referensi atau tidak.
Saat sesuai, hitung berapa kali,dan tampilkan.
Saat tidak sesuai, tampilkan error.
Apabila karakter string selesai end dimasukkan, akan mengakhiri program.

Perhatian
Untuk membandingkan string, pertama-tama gunakan fungsi strlen, selanjutnya gunakan fungsi strcmp.
Pertimbangkan huruf kapital huruf kecil dari karakter inputan.
Mengenai tidak ada masukkan, keluarkan error.

Contoh eksekusi referensi

>Inputlah karakter string referensi call

Saat akan mengakhiri inputlah [end].

>call
Sesuai. 1 kali
>call
sesuai. 2 kali
>ccccccccccc
error inputan
>call
sesuai. 3 kali
>end
Selesai */

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char reference[MAX_LENGTH];

    printf("Inputlah karakter string referensi: ");
    scanf("%s", reference);

    char input[MAX_LENGTH];
    int count = 0;

    while (1) {
        printf("Masukkan karakter string: ");
        scanf("%s", input);

        if (strcmp(input, "end") == 0) {
            break;
        }

        if (strcmp(input, reference) == 0) {
            count++;
            printf("Sesuai. %d kali\n", count);
        } else {
            printf("Error inputan\n");
        }
    }

    printf("Selesai\n");

    return 0;
}
