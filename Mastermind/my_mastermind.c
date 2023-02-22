#include "header.h"
// check if the user's guess is misplaced
int misplaced_count(char* secret_num, char* random){
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (random[i] == secret_num[j]) {
                count++;
                break;
            }
        }
    }
    return count;
}

// check if the user's guess is well placed
int wellplaced_count(char* secret_num, char* random) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (random[i] == secret_num[i]) {
            count++;
        }
    }
    return count;
}

// Check if the user's guess is a digit between 0 and 8
int valid_guess(char* guess) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (guess[i] >= '0' && guess[i] <= '8') {
            count++;
        }
    }
    return (count == 4) ? 1 : 0;
}

// to read the user's input
int read_input(char* input) {
    int result = read(0, input, 5);
    input[5] = '\0';
    return result;
}

// generate a secertcode code of 4 digits
int main(int argc, char** argv){
    char secret_code[5];
    if (argc > 2 && argv[1][0] == '-' && argv[1][1] == 'c') {
        for (int i = 0; i < 4; i++) {
        secret_code[i] = argv[2][i];
        }
    } 
    else {
        // Generate a random code
        srand(time(NULL));
        int nums[5];
        bool unique_num = true;
        int random_num;
        for (int i = 0; i < 4; i++) {
            do {
                random_num = (rand() % 8);
                for (int u = 0; u < i; u++) {
                    if (nums[u] == random_num) {
                        unique_num = false;
                    }
                }
            }   
            while(!unique_num);
            secret_code[i] = (random_num + '0');
        }
    }
    secret_code[4] = '\0';
    char guess[6];
    int round = 0;
    printf("Will you find the secret code?\nPlease enter a valid guess\n");

    while (wellplaced_count(secret_code, guess) < 4 && round  < 11) {
        // To read the input of the guess
        if (read_input(guess) == 0) {
            return 0;
        }
        if (valid_guess(guess)) {
            printf("\nRound %d\nWell placed pieces: %d\nMisplaced pieces: %d\n", round, wellplaced_count(secret_code, guess), misplaced_count(secret_code, guess) - wellplaced_count(secret_code, guess));
            round++;
        } else {
            printf("Wrong input!\n");
        }
    }
    printf("Congratz! You did it!");
    return 0;
}