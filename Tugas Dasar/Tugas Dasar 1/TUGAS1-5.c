/* P. Gunakan fungsi scanf, input karakter string 10 kali, dan tampilkan string paling besar.
Untuk perbandingan karakter string gunakan strcmp
Saat tidak ada inputan, buatlah sebagai error dan memungkinkan dapat diinput sekali lagi. 

Q. Dengan menggunakan fungsi scanf, masukkan angka 10 kali, dan tampilkan angka ganjil terbesar.
Saat tidak ada inputan dan inputan selain nilai numerik half-width, buatlah sebagai error dan memungkinkan dapat diinput sekali lagi. */

/* Program P
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char strings[10][MAX_LENGTH];
    char max_string[MAX_LENGTH];
    int i;

    for (i = 0; i < 10; i++) {
        printf("Masukkan string ke-%d: ", i + 1);
        int result = scanf("%s", strings[i]);

        if (result != 1) {
            printf("Error: Tidak ada input yang diberikan.\n");

            // Mengosongkan input buffer
            while (getchar() != '\n');

            printf("Coba lagi.\n");
            i--;
            continue;
        }
    }

    strcpy(max_string, strings[0]);

    for (i = 1; i < 10; i++) {
        if (strcmp(strings[i], max_string) > 0) {
            strcpy(max_string, strings[i]);
        }
    }

    printf("String terbesar: %s\n", max_string);

    return 0;
}
*/

/* Program Q */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numbers[10];
    int max_odd = -1;
    int i;

    for (i = 0; i < 10; i++) {
        printf("Masukkan angka ke-%d: ", i + 1);
        int result = scanf("%d", &numbers[i]);

        if (result != 1) {
            printf("Error: Tidak ada input yang diberikan atau input bukan angka.\n");

            // Mengosongkan input buffer
            while (getchar() != '\n');

            printf("Coba lagi.\n");
            i--;
            continue;
        }

        if (numbers[i] % 2 != 0 && numbers[i] > max_odd) {
            max_odd = numbers[i];
        }
    }

    if (max_odd != -1) {
        printf("Angka ganjil terbesar: %d\n", max_odd);
    } else {
        printf("Tidak ada angka ganjil yang dimasukkan.\n");
    }

    return 0;
}
