#include <stdio.h>

int get_sum(int n){
    // Instructions: Find the sum of all integers up to n which are divisible by 3 and not
    // divisible by 5. You may use a while loop for this purpose.
    // Please keep the sum in the declared variable at line 4.
    // At the end, this function returns the sum to the tester, you will not change that line.
    // n is available here, the tester supplies n, do not need to declare n
    // Write your code after this line ------
    int sum = 0;
    int counter = 3;

    while (counter <= n) {
        if (counter % 3 == 0 && counter % 5 != 0)
            sum += counter;

        counter++;
    }

    // --- DO NOT CHANGE TO THE FOLLOWING LINE
    return sum;
}

int main() {
    printf("Program to find the sum of numbers from 1 to n witch are divisible by 3 but not by 5.\n\n");

    printf("The sum of n = %d is: %d\n", 25, get_sum(25));
    printf("The sum of n = %d is: %d\n", 45, get_sum(45));
    printf("The sum of n = %d is: %d\n", 150, get_sum(150));

    return 0;
}