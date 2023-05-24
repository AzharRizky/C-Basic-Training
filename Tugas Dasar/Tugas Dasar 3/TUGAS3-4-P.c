/* P. Membaca karakter inputan (byte), dan menampilkan bit string karakter (bit).
Dan tampilkan juga bit yang diganti dengan turunkan 4 bit dan naikan 4 bit.

Q. Membaca 2 karakter inputan (masing-masing byte),
tampilkan string bit(bit) dari masing-masing karakter,
bandingkan bit yang sesuai dan tampilkan nomor bit yang sesuai.

Contoh, saat membandingkan string bit berikutnya,
1001 0110
1110 1010

Melaporkan bahwa bit ke bit ke P dan bit ke Q sesuai.
Gunakan operator bitwise untuk masalah ini */

#include <stdio.h>

void printBits(char c) {
	int i;
    for (i = 7; i >= 0; i--) {
        if (c & (1 << i))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main() {
    char input;
    printf("Masukkan karakter: ");
    scanf("%c", &input);

    printf("Bit string karakter: ");
    printBits(input);

    char shiftedDown = input >> 4;
    char shiftedUp = input << 4;

    printf("Bit string setelah shift down 4 bit: ");
    printBits(shiftedDown);

    printf("Bit string setelah shift up 4 bit: ");
    printBits(shiftedUp);

    return 0;
}
