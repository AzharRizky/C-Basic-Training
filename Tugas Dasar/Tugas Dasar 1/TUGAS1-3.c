
/* P. Tampilkan array variabel karakter HELLO C dari tugas 2, masing-masing 1 karakter baris demi baris. untuk mengulanginya, gunakan statement while
Q. Buat program yang menampilkan dari 1 sampai 10. untuk mengulanginya gunakan statement for
R. Modifikasi statement for pada program‚ Q dengan menggunakan increment
Dan, gunakan j++ dan ++k pada increment, kemudian konfirmasikan seperti apa perbedaan yang ada.
Kumpulkan perbedaan pre-increment dan post-increment pada file teks(.txt), kemudian persentasikan pada saat review */

#include <stdio.h>
main()
{
	printf("Program P\n");
    char word[20] = "Hello C";
    int i = 0;
    while (word[i] != '\0')
    {
        printf("%c\n", word[i]);
        i++;
    }
    
    printf("Program Q\n");
    int j;
    for (j = 1; j <= 10; ++j) // pre-increment j = 1 + j
    {
        printf("%d\n", j);
    }

    printf("Program R\n");
    int k;
    for (k = 1; k <= 10; k++) // post-increment k = k + 1
    {
        printf("%d\n", k);
    }
}



