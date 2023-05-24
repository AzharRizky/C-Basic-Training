/* Tampilkan 2 nilai numerik dalam bentuk di bawah ini.

Tampilkan masing-masing dengan 16bit (biner)

Tampilkan masing-masing dengan 32 bit sign extension.

Perluas masing-masing ke nol dan tampilkan dengan 32 bit.

Nilai negatif, tampilkan dengan pelengkap 2. */

#include <stdio.h>

void printBinary16(int value) {
    int i;
    printf("%d: ", value);
    for (i = 15; i >= 0; i--) {
        if (value & (1 << i))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

void printBinary32(int value) {
    int i;
    printf("%d: ", value);
    for (i = 31; i >= 0; i--) {
        if (value & (1 << i))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main() {
    int value1, value2;

    printf("Masukkan nilai pertama: ");
    scanf("%d", &value1);
    printf("Masukkan nilai kedua: ");
    scanf("%d", &value2);

    printf("Nilai pertama (16 bit):\n");
    printBinary16(value1);
    printf("Nilai pertama (32 bit sign extension):\n");
    printBinary32(value1);
    printf("Nilai pertama (32 bit zero extension):\n");
    printBinary32((unsigned int)value1);

    printf("Nilai kedua (16 bit):\n");
    printBinary16(value2);
    printf("Nilai kedua (32 bit sign extension):\n");
    printBinary32(value2);
    printf("Nilai kedua (32 bit zero extension):\n");
    printBinary32((unsigned int)value2);

    return 0;
}
