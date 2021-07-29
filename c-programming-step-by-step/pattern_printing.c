#include <stdio.h>
/*
White a program that given a pattern print n number of lines following a set of characters for that pattern.

Examples for n = 3

pattern 1:
***
**
*

pattern 2:
*
**
***
***
**
*

pattern 3:
1
22
333

pattern 4:
1
12
123

pattern 5:
0
10
010
*/

void show_menu();
void show_pattern1();
void show_pattern2();
void show_pattern3();
void show_pattern4();
void show_pattern5();

int lines_number = 0;

int main() {
	int quit = 0;

    int option;
    while (!quit)
    {
        show_menu();
        printf("Witch pattern you choose? ");
        scanf("%d", &option);

        if (option != 6) {
            printf("Enter number of lines to show <negative to cancel>: ");
            scanf("%d", &lines_number);
        }

        if (lines_number < 0) continue;

        switch (option)
		{
		case 1:
			show_pattern1();
			break;
		case 2:
			show_pattern2();
			break;
        case 3:
			show_pattern3();
			break;
        case 4:
			show_pattern4();
			break;
        case 5:
			show_pattern5();
			break;
		case 6:
			quit = 1;
			break;
		default:
			if (option > 6) printf("Invalid menu option\n");
			else printf("Invalid option entered.\n");
			break;
		}
    }

    return 0;
}

void show_menu() {
    printf("\nShow patterns of characters given n numbers of lines\n");
    printf("\n---- MENU ----");
	printf("\n1. Show pattern 1");
	printf("\n2. Show pattern 2");
	printf("\n3. Show pattern 3");
	printf("\n4. Show pattern 4");
	printf("\n5. Show pattern 5");
	printf("\n6. Quit\n");
}

void show_pattern1() {
    printf("\nShowing %d lines using the 1st pattern.\n", lines_number);

    int characters_number = lines_number;
    for (size_t h = 1; h <= lines_number; h++) {
        for (size_t i = characters_number; i > 0; i--)
            printf("*");

        printf("\n");
        characters_number--;
    }
}

void show_pattern2() {
    printf("\nShowing %d lines using the 2nd pattern.\n", lines_number);

    for (size_t h = 1; h <= lines_number; h++) {
        for (size_t i = h; i > 0; i--)
            printf("*");

        printf("\n");
    }
    int characters_number = lines_number;
    for (size_t j = 1; j <= lines_number; j++) {
        for (size_t k = characters_number; k > 0; k--)
            printf("*");

        printf("\n");
        characters_number--;
    }
}

void show_pattern3() {
    printf("\nShowing %d lines using the 3rd pattern.\n", lines_number);

    for (size_t h = 1; h <= lines_number; h++) {
        for (size_t i = h; i > 0; i--)
            printf("%li", h);

        printf("\n");
    }
}

void show_pattern4() {
    printf("\nShowing %d lines using the 4th pattern.\n", lines_number);

    for (size_t h = 1; h <= lines_number; h++) {
        for (size_t i = h; i > 0; i--)
            printf("%li", i);

        printf("\n");
    }
}

void show_pattern5() {
    printf("\nShowing %d lines using the 5th pattern.\n", lines_number);

    for (size_t h = 1; h <= lines_number; h++) {
        for (size_t i = h; i > 0; i--)
            printf("%d", !(i%2)? 1 : 0);

        printf("\n");
    }
}