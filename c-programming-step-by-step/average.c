/**
Instructions: 
Write a program that will input 3 integer values from user and then will 
display the average of them. You would require to declare 3 integer variables 
for holding the integers given by the users from keyboard and then you need 
another variable for holding the average. Decide by yourself about the datatype 
of the average variable.

Finally print the average into console using printf.
*/
#include <stdio.h>

int main()
{
	int n1, n2, n3 = 0;
	double average;

	printf("Program to calculate the average of three numbers.\n");
	printf("Enter first number: ");
	scanf("%d", &n1);
	printf("Enter second number: ");
	scanf("%d", &n2);
	printf("Enter third number: ");
	scanf("%d", &n3);

	average = ( (double)(n1 + n2 + n3) / (double)3 );
	printf("The average for %d, %d y %d is: %lf\n", n1, n2, n3, average);

	return 0;
}