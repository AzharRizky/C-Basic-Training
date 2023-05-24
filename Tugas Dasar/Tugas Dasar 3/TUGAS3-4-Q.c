#include <stdio.h>

void printBits(char c) {
	int i;
    for (i = 7; i >= 0; i--) {
        if (c & (1 << i))
            printf("1");
        else
            printf("0");
    }
}

void compareBits(char c1, char c2) {
	int i;
    printf("Bit string karakter 1: ");
    printBits(c1);
    printf("\n");

    printf("Bit string karakter 2: ");
    printBits(c2);
    printf("\n");

    printf("Bit yang sesuai: ");
    for (i = 7; i >= 0; i--) {
        if ((c1 & (1 << i)) == (c2 & (1 << i)))
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    char input1, input2;
    printf("Masukkan karakter 1: ");
    scanf("%c", &input1);
    getchar();  // Membuang karakter newline

    printf("Masukkan karakter 2: ");
    scanf("%c", &input2);

    compareBits(input1, input2);

    return 0;
}
