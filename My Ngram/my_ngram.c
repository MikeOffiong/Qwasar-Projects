#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 128

void count_letter_frequency(int *array, char* string) {

    for(int i = 0; string[i] != '\0'; i++) {
        if(string[i] != '"') {
            array[(int)string[i]] += 1;
        }
    }
}

void array_prnt(int* array, int size_array) {

    for(int i = 0; i < size_array; i++) {
        if(array[i] > 0) {
            printf("%c:%d\n", i, array[i]);
        }
    }
}

int main(int ac, char **av) {
    int array[MAX_ARRAY_SIZE] = {0};

    for(int i = 1; i < ac; i++) {
        count_letter_frequency(&array[0], av[i]);
    }
    array_prnt(&array[0], MAX_ARRAY_SIZE);
    return 0;
}
