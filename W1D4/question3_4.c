#include <stdio.h>

int gcd(int a, int b){
	if(b == 0){
		return a;
	} else {
		return gcd(b, a % b);
	}
}

int lcm(int c, int d){
	int m = (c*d);
	int o;
	if(c > d){
		o = (c-d);
	} else {
		o = (d-c);
	}

	return (m/o);

}

int main(){
	int k = gcd(2970, 1265);
	printf("%d\n", k);
	printf("%d\n", lcm(30, 25));
}

