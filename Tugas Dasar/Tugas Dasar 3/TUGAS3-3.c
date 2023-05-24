/* P. Buatlah makro fungsi sqr(n) yang mengkuadratkan angka.

Q. Buatlah makro yang mengimplementasikan fungsi berikut7.

Nama Makro DEBUG(item); item adalah nama variabel. Tidak masalah apabila item terbatas pada tipe variabel integer.
Hasil Eksekusi lineNo xx : item = 10xx adalah nomor baris dalam program, 10 adalah nilai item variabel.

P & Q tidak ada keterkaitan, namun bisa dibuat dengan 1 program atau dibuat dengan program yang berbeda tidak masalah. */

/* 
#include <stdio.h>

#define sqr(n) ((n) * (n))

int main() {
    int x = 10;
    int result = sqr(x);
    printf("Square of %d is %d\n", x, result);
    return 0;
}
*/

#include <stdio.h>

#define DEBUG(item) printf("LineNo %d: " #item " = %d\n", __LINE__, item)

int main() {
    int x = 10;
    DEBUG(x);
    return 0;
}