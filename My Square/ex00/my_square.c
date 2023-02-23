#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av) {
    if (av[1] == NULL || av[2] == NULL)
        return 0;

    int x = atoi(av[1]);
    int y = atoi(av[2]);
    
    int row, col;
    for(row = 0; row < x; row++) {
        for (col = 0; col < y; col++) {
            if (row == 0 && col == 0) {
                putchar('o');
            }
            else if (row == 0 && col == (y - 1)) {
                putchar('o');
            }
            else if (row == (x - 1) && col == (y - 1)) {
                putchar('o');
            }
            else if (row == (x - 1) && col == 0) {
                putchar('o');
            }
            else if (row == 0 && ((col > 0) || (col < y - 1))) {
                putchar('-');
            }
            else if (row == (x - 1) && ((col > 0) || (col < y - 1))) {
                putchar('-');
            }
            else if (row > 0 && ((col == 0) || (col == (y - 1)))) {
                putchar('|');
            }
            else {
                putchar(' ');
            }
        }
        putchar(10);
    }
}