#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// struct for the score
struct Result {
    int won;
    int score;
};

int main() {
    char word[10];
    char words[][10] = {"APPLE", "ENUMERATION", "ENIGMATIC", "PEANUT", "CRINGE", "MORTAL", "PROCREATE", "AESTHETICS", "POPE", "TRAM", "SMASH"};
    char letter;
    int wrong = 0;
    char unknown[80];
    int maxAttempts = 4;
    struct Result *winner = malloc(sizeof(struct Result));

    // choosing a word randomly
    srand(time(NULL));
    int n = rand() % 10;
    strcpy(word, words[n]);

    // creating the blanks
    setupWord(word, unknown);

    // opening messages
    printf("\n\nWelcome to the word guessing game!!");
    printf("\nYou have %d tries.", maxAttempts);

    // make guesses
    while (wrong < maxAttempts) {
        printf("\n\n%s", unknown);
        printf("\n\nGuess a letter: ");
        scanf("%c", &letter);
        letter = toupper(letter);
        fflush(stdin);

        // replace blank with letter if guess is correct, otherwise increment wrong guesses variable
        if (fill(letter, word, unknown) == 0)
        {
            printf("\nThis letter is not in the word!\n");
            wrong++;
        }
        else {
            printf("\nYayy! You found a letter!\n");
        }

        // Telling the user how many guesses remain
        printf("You have %d", maxAttempts - wrong);
        printf(" guesses left.\n");

        // Checking if the word has been matched
        if (strcmp(word, unknown) == 0) {
            printf("\n%s\n", word);
            printf("Yeah! You got it!");
            break;
        }
    }
    if (wrong == maxAttempts) {
        printf("\nYou lose!\n");
        printf("The word was : %s\n", word);
    }
    getch();
    return 0;
}
