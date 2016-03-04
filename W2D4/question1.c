#include <stdio.h>

typedef struct {
	int num;
	int denom;
} Fraction;

static int gcd(int a, int b){
	if(b == 0){
		return a;
	} else {
		return gcd(b, a % b);
	}
}

Fraction simplify(Fraction x){
	Fraction y = {x.num, x.denom};
	int g = gcd(x.num, x.denom);
	if( g!= 1){
		y.num /= g;
		y.denom /= g;
	}
	return y;
}

Fraction make_fraction(int n, int d){
	Fraction x = {0, 1};
	if (n == 0){
		return x;
	}
	if (d < 0){
		n = -n;
		d = -d;
	}
	int g = gcd(n,d);
	if (g != 1){
		n /= g;
		d /= g;
	}
	x.num = n;
	x.denom = d;
	return x;
}

void display_fraction(Fraction x){
	printf(" %d/%d ", x.num, x.denom);
}

int equal_fraction(Fraction x, Fraction y){
	return x.num == y.num && x.denom == y.denom;
}

Fraction add_fraction(Fraction x, Fraction y){
	Fraction z;
	if (x.denom == y.denom){
		z = make_fraction((x.num + y.num), x.denom);
	} else {
		z = make_fraction(((x.num*y.denom)+(y.num*x.denom)),(x.denom*y.denom));
	}
	return z;
}

Fraction substract_fraction(Fraction x, Fraction y){
	Fraction z;
	if (x.denom == y.denom){
		z = make_fraction((x.num - y.num), x.denom);
	} else {
		z = make_fraction(((x.num*y.denom)-(y.num*x.denom)),(x.denom*y.denom));
	}
	return z;
}

Fraction multiply_fraction(Fraction x, Fraction y){
	Fraction z = make_fraction((x.num * y.num), (x.denom * y.denom));
	return z;
}

int compare_fraction(Fraction x, Fraction y){
	double f = x.num/x.denom;
	double g = y.num/y.denom;
	if(f==g){
		return 0;
	} else if ( f > g){
		return 1;
	} else {
		return -1;
	}
}

int main(){
	Fraction a = make_fraction(3, 5);
	Fraction b = make_fraction(5, 8);
	Fraction c = add_fraction(a, b);
	display_fraction(c);
	Fraction d = multiply_fraction(a, b);
	display_fraction(d);
}


