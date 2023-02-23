#include<unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
    FILE *cd;
    int j;
    
    for(int index=1; index < argc; index ++) {
        cd = fopen(argv[index], "r");
        while ((j = getc(cd)) != EOF) {
            printf("%c", j);
        }
    }
   fclose(cd);
   return 0;
}