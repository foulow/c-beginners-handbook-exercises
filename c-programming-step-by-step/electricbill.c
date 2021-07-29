#include <stdio.h>

int main(){
	int units, units_copy;    // you need to input this
	double bill_amount;  // you need to calculate this

	// prompt user to input unit consumed using printf and then
	// using scanf read the value into the unit variable.
	printf("****** Welcome to the ABC Power Supply Company *******\n");
	printf("Input Unit Consumed: ");
	scanf("%d", &units);
	units_copy = units;

	// Now, use if-elseif to decide about rate
	if (units < 0){
		printf("Unit consumed cannot be negative\n");
		return -1;
	}
	else if(units >= 0 && units <= 100){
		bill_amount = units * 0.2;     // for this range 0.2 is the rate
	}
	else if(units > 100 && units <= 250){  // >100 and <=250
		// please note that the bill must be calculated on slabs (see instructions)
		bill_amount = 100 * 0.2; units_copy -= 100;
		bill_amount += units_copy * 0.5;
	}
	else if(units > 250 && units <= 500){  // >250 and  <=500
		// please note that the bill must be calculated on slabs (see instructions)
		bill_amount = 100 * 0.2; units_copy -= 100;
		bill_amount += 150 * 0.5; units_copy -= 150;
		bill_amount += units_copy * 0.75;
	}
	else{		// for anything >500
		// please note that the bill must be calculated on slabs (see instructions)
		if (units) {
			bill_amount = 100 * 0.2; units_copy -= 100;
			bill_amount += 150 * 0.5; units_copy -= 150;
			bill_amount += 250 * 0.75; units_copy -= 250;
			bill_amount += units_copy * 1.0;
		}
		else bill_amount = 0;
	}

	// ** finally print the bill amount here, please note that if the unit consumed is
	// invalid that is negative then no bill should be printed. **
	printf("Total bill: $%.2lf for %d units\n", bill_amount, units);
	printf("Thank you!\n");

	return 0;
}