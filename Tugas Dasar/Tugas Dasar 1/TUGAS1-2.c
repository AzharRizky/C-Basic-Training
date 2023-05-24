/* P. Buat sebuah program yang menampilkan karakter 1997 sebagai variabel tipe integer(int).
Q. Buat sebuah program yang menampilkan karakter HELLO C sebagai variabel string(array tipe char). */

#include <stdio.h>

main()
{
    printf("Program P\n");
    int year = 1997;
    printf("%d\n", year);

    printf("Program Q\n");
    char word[20] = "Hello C";
    printf("%s\n", word);
}
