/*
Assignment created by Shibaji Paul for Udemy C programming course.

The amazing creature 'Pupeta' lives in a funny world where is could be surrounded by at most 8 neighbours. The behaviour of our hero 'Pupeta' depends on how many neighbours he has at any moment. You need to lookup for his present behaviour before you could go and deliver his favorite Pizza that he would often order to your famous Pizza shop.

Here are the rules:
number of neighbours    Behaviour of 'Pupeta'
--------------------    ----------------------
0                       Sad and will force you to listen to his story,
                        will make you late.

1                       He will ask you to deliver half of the pizza to his
                        only neighbor, you may be late.

>=2 and <=5             Will have great mood and will be singing song. May crack
                        joke as well. You will get good tips, definitely.

7                       He will be making great drink for his neighbors and
                        will invite you to taste. But will not give you tip.

6 or 8                  Too angry and furious, deliver the pizza and leave ASAP.

Write a C Program that will ask for number of neighbour from the user and will print the mood of 'Pupeta' accordingly. Please note that if the input is invalid, that is < 0 or > 8, then your program must display error message "Invalid number of neighbours".
*/
#include <stdio.h>

int main() {
    int neirhbours_count = 0;
    printf("Program to determing how Pupeta will act depending on # of neighbours arrown.\n");
    printf("Input number of neighbours next to Pupeta: ");
    scanf("%d", &neirhbours_count);

    if (neirhbours_count == 0) {
        printf("\nSad and will force you to listen to his story, will make you late.\n");
    }
    else if (neirhbours_count == 1) {
        printf("\nHe will ask you to deliver half of the pizza to his only neighbor, you may be late.\n");
    }
    else if (neirhbours_count >= 2 && neirhbours_count <= 5) {
        printf("\nWill have great mood and will be singing song. May crack joke as well. You will get good tips, definitely.\n");
    }
    else if (neirhbours_count == 7) {
        printf("\nHe will be making great drink for his neighbors and will invite you to taste. But will not give you tip.\n");
    }
    else if (neirhbours_count == 6 || neirhbours_count == 8) {
        printf("\nToo angry and furious, deliver the pizza and leave ASAP.\n");
    }
    else {
        printf("\nInvalid number of neighbours\n");
    }

    return 0;
}