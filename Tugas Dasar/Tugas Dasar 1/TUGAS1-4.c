
/* P. Gunakan fungsi scanf, untuk menampilkan string karakter yang diinput.
Saat tidak ada inputan, buatlah sebagai error dan memungkinkan dapat diinput sekali lagi. 

Q. Gunakan fungsi scanf, masukkan 1 half-width angka dan munculkan dalam nomor biner.
Saat tidak ada inputan, buatlah sebagai error dan memungkinkan dapat diinput sekali lagi. */

/*  Program P
#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];

    printf("Masukkan string karakter: ");
    int result = scanf("%s", input);

    if (result != 1) {
        printf("Error: Tidak ada input yang diberikan.\n");

        // Mengosongkan input buffer
        while (getchar() != '\n');

        printf("Coba lagi: ");
        result = scanf("%s", input);

        if (result != 1) {
            printf("Error: Tidak ada input yang diberikan lagi. Program berakhir.\n");
            return 1;
        }
    }

    printf("Input Anda: %s\n", input);

    return 0;
}
*/

/* Program Q */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int input, i;

    printf("Masukkan angka half-width: ");
    int result = scanf("%d", &input);

    if (result != 1) {
        printf("Error: Tidak ada input yang diberikan.\n");

        // Mengosongkan input buffer
        while (getchar() != '\n');

        printf("Coba lagi: ");
        result = scanf("%d", &input);

        if (result != 1) {
            printf("Error: Tidak ada input yang diberikan lagi. Program berakhir.\n");
            return 1;
        }
    }

    printf("Angka biner: ");
    for (i = 15; i >= 0; i--) {
        int bit = (input >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");

    return 0;
}
