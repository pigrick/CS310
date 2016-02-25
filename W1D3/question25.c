#include <stdio.h>

int main(){
	int change, quarter, nickel, dime, pennie;
	printf("Type in 1-99 to see the appropriate change : ");
	scanf("%d", &change);

	quarter = change / 25;
	change = change % 25;
	dime = change / 10;
	change = change % 10;
	nickel = change / 5;
	change = change % 5;
	pennie = change;

	printf("Your change is %d quarter, %d dime, %d nickel and %d pennie.\n",
			quarter, dime, nickel, pennie);
}
