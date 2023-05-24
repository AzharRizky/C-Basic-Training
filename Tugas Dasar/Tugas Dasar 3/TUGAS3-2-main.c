/* P. Split source program yang dibuat pada program sebelumnya dan simpan, hubungkan mereka untuk membuat file eksekusi(.exe).

Q. Buat makefile untuk mengcompile source yang telah displit pada P buat sampai file eksekusi(.exe) dengan hanya menjalankan make. */

#include <stdio.h>
#include "TUGAS3-2-functions.h"

int main() {
    printf("Hello, World!\n");
    int result = add(3, 4);
    printf("3 + 4 = %d\n", result);
    return 0;
}