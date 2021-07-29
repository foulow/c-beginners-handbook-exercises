/*
    Game to guess the sum of two randomly generated numbers from 1-6.
    (simulating the role of two dice)

    The player must enter a number from 0-12 to play.
    (0 or lower to finish)
    (1-12 player guess)

    If the player guesses right then the score gets up by 10 points. (+10)
    otherwise, it gest down by 5 points. (-5)
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RIGHT_GUEST_PTS 10
#define WRONG_GUEST_PTS 5

int main() {
    int guest                           = 13;
    int score                           = 0;
    unsigned long correct_guest_count   = 0;
    unsigned long incorrect_guest_count = 0;

    while (guest > 0)
    {
        long seed = time(NULL);
        srand(seed);

        int dice1_val = 1 + (rand() % 5);
        int dice2_val = 1 + (rand() % 5);
        int sum = dice1_val + dice2_val;

        printf("\nComputer rolled two dice...Guess the sum\n");
        printf("Enter any <=0 value to terminate.\n");
        do
        {
            printf("Enter your guess <1-12>: ");
            scanf("%d", &guest);
        } while (guest > 12);


        if (guest == sum) {
            printf("Bravo!!! You were correct +%d", RIGHT_GUEST_PTS);

            score += RIGHT_GUEST_PTS;
            correct_guest_count += 1;
        }
        else if (guest > 0) {
            printf("Darn!!! Bad attempt, -%d\n", WRONG_GUEST_PTS);
            printf("Sum was: %d\n", sum);

            score -= WRONG_GUEST_PTS;
            incorrect_guest_count += 1;
            guest = 13; // reset guest to incorrect value.
        }

        printf("\nTotal Correct:   %li", correct_guest_count);
        printf("\nTotal Incorrect: %li", incorrect_guest_count);
        printf("\nScore:           %d\n", score);
    }

    printf("\nThank you for playing...\n\n");

    return 0;
}