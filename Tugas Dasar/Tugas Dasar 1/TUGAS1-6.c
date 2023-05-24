/*
Gunakan fungsi scanf, masukkan 2 angka, kemudian hitunglah empat operasi aritmatika, OR, AND dan output masing-masing.
Konfirmasikan perbedaan hasil operasi saat masing-masing variabel di set ke tipe int, tipe float, tipe double.
Coding untuk dapat memverifikasi semua pola dengan satu program

Memungkinkan dapat menginput di bawah titik desimal.
Mengatasi mengenai error jumlah digit inputan.
Saat tidak ada inputan dan inputan selain nilai numerik half-width, buatlah sebagai error.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;
    float fnum1, fnum2;
    double dnum1, dnum2;

    // Input untuk tipe int
    printf("Masukkan dua angka (int): ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Error: Input tidak valid. Program berakhir.\n");
        return 1;
    }

    // Operasi aritmatika dan bitwise untuk tipe int
    int intSum = num1 + num2;
    int intDiff = num1 - num2;
    int intProd = num1 * num2;
    int intDiv = num1 / num2;
    int intOr = num1 | num2;
    int intAnd = num1 & num2;

    // Input untuk tipe float
    printf("Masukkan dua angka (float): ");
    if (scanf("%f %f", &fnum1, &fnum2) != 2) {
        printf("Error: Input tidak valid. Program berakhir.\n");
        return 1;
    }

    // Operasi aritmatika untuk tipe float
    float floatSum = fnum1 + fnum2;
    float floatDiff = fnum1 - fnum2;
    float floatProd = fnum1 * fnum2;
    float floatDiv = fnum1 / fnum2;

    // Input untuk tipe double
    printf("Masukkan dua angka (double): ");
    if (scanf("%lf %lf", &dnum1, &dnum2) != 2) {
        printf("Error: Input tidak valid. Program berakhir.\n");
        return 1;
    }

    // Operasi aritmatika untuk tipe double
    double doubleSum = dnum1 + dnum2;
    double doubleDiff = dnum1 - dnum2;
    double doubleProd = dnum1 * dnum2;
    double doubleDiv = dnum1 / dnum2;

    // Output hasil operasi
    printf("\n=== Hasil Operasi (Tipe int) ===\n");
    printf("Penjumlahan: %d\n", intSum);
    printf("Pengurangan: %d\n", intDiff);
    printf("Perkalian: %d\n", intProd);
    printf("Pembagian: %d\n", intDiv);
    printf("OR: %d\n", intOr);
    printf("AND: %d\n", intAnd);

    printf("\n=== Hasil Operasi (Tipe float) ===\n");
    printf("Penjumlahan: %.2f\n", floatSum);
    printf("Pengurangan: %.2f\n", floatDiff);
    printf("Perkalian: %.2f\n", floatProd);
    printf("Pembagian: %.2f\n", floatDiv);

    printf("\n=== Hasil Operasi (Tipe double) ===\n");
    printf("Penjumlahan: %.2lf\n", doubleSum);
    printf("Pengurangan: %.2lf\n", doubleDiff);
    printf("Perkalian: %.2lf\n", doubleProd);
    printf("Pembagian: %.2lf\n", doubleDiv);

    return 0;
}
