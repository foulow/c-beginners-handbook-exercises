#include <stdio.h>
#include <math.h>
/**

When the program executes it will work in the following way:
You must accomplish all the menu options and validation checkings exactly as asked.

---- MENU ----
1. Find factorial
2. Find a^b
3. Quit

What you want to do? 1
Enter number: -1
Invalid number for factorial

---- MENU ----
1. Find factorial
2. Find a^b
3. Quit
What you want to do? 1
Enter number: 5
Factorial of 5 is 120

---- MENU ----
1. Find factorial
2. Find a^b
3. Quit

What you want to do? 20
This program can find factorials only in the range 0 - 10

---- MENU ----
1. Find factorial
2. Find a^b
3. Quit
What you want to do? 2
Enter a: 2
Enter b: 5
2^5 = 32.0

---- MENU ----
1. Find factorial
2. Find a^b
3. Quit
What you want to do? 5
Invalid menu option

---- MENU ----
1. Find factorial
2. Find a^b
3. Quit
What you want to do? 3

*** Thank you ***

NOTE: You should use library function pow to find a^b, no need to write code 
for finding a^b.

*/
void show_menu();
void find_factorial();
void find_a_power_b();

int main(){
	int quit = 0;
	int n;  // n is the number for which you will find factorial
	int p;  // you are going to keep the factorial of n in p
	double base, exp; // for a^b

	int option; // for keeping the menu option
	while(!quit){
		// print the menu here
		// get the response into option variable.
		// Now. you can use if-else to check the option and do needful
		// When option == 3, you need to do something with the variable quit, think
		// about that.
		// When option == 1, you should read n and first check the validity,
		// if n < 0, a particular message has to be printed, when n > 10, another
		// message has to be printed (see the expected output above), if n is valid
		// write a while loop to calculate the factorial and print it, becareful about
		// the initial value of p.
		// for option == 2, read base and exponant then make a call to the pow function
		// print the return value using printf. You may declare a variable to hold the
		// result.
		show_menu();
		printf("What you want to do? ");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			find_factorial();
			break;
		case 2:
			find_a_power_b();
			break;
		case 3:
			quit = 1;
			break;
		default:
			if (option > 3) printf("Invalid menu option\n");
			else printf("Invalid option entered.\n");
			break;
		}
	}

	return 0;
}

void show_menu() {
	printf("\n---- MENU ----");
	printf("\n1. Find factorial");
	printf("\n2. Find a^b");
	printf("\n3. Quit\n");
}

void find_factorial() {
	int input, input_copy;
	long long int factorial_resutl = 1;

	printf("Enter number: ");
	scanf("%d", &input);
	input_copy = input;

	if (input_copy < 0) {
		printf("Invalid number for factorial\n");
		return;
	} else if (input_copy > 10) {
		printf("This program can find factorials only in the range 0 - 10\n");
		return;
	}

	while (input_copy > 0)
	{
		factorial_resutl = factorial_resutl * input_copy--;
	}

	printf("Factorial of %d is %lli\n", input, factorial_resutl);
}

void find_a_power_b() {
	int a, a_copy, b, b_copy;
	double power_result = 1;

	printf("Enter a: ");
	scanf("%d", &a);
	a_copy = a;
	printf("Enter b: ");
	scanf("%d", &b);
	b_copy = b;

	power_result = pow((double)a, (double)b);

	printf("%d^%d = %.1lf\n", a, b, power_result);
}