#include <stdio.h>

int main(int argc, char *argv[]) {
	int i;
    printf("Jumlah argumen: %d\n", argc);

    if (argc > 0) {
        printf("Argumen:\n");
        for (i = 0; i < argc; i++) {
            printf("%d. %s\n", i + 1, argv[i]);
        }
    } else {
        printf("Tidak ada argumen yang diberikan.\n");
    }

    return 0;
}
