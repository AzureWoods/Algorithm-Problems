#include <stdio.h>
#include <math.h>
#define eps 0.00001
#define Pi 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986
// double gcd(double x, double y) {
//     while (fabs(x) > eps && fabs(y) > eps)
//      {
//         if (x > y)
//                 x -= floor(x / y) * y;
//         else
//                 y -= floor(y / x) * x;
//     }
//     return x + y;
// }
double gcd(double x,double y)
{
	if(y<eps)
		return x+y;
	else return gcd(y,fmod(x,y));
}
int main()
{
	double a1,a2,a3;
	double b1,b2,b3;
	double a,b,c;
	double A,B,C;
	double S,R;
	double p;
	double n;
	double Area;
	scanf("%lf%lf",&a1,&b1);
	scanf("%lf%lf",&a2,&b2);
	scanf("%lf%lf",&a3,&b3);
	a=sqrt((a2-a1)*(a2-a1)+(b2-b1)*(b2-b1));
	b=sqrt((a3-a1)*(a3-a1)+(b3-b1)*(b3-b1));
	c=sqrt((a2-a3)*(a2-a3)+(b2-b3)*(b2-b3));
	p=(a+b+c)/2.000000;
	S=sqrt(p*(p-a)*(p-b)*(p-c));
	R=a*b*c/(4.000000*S);
	A=acos(1.000000-(a*a)/(2.000000*R*R));
	B=acos(1.000000-(b*b)/(2.000000*R*R));
	C=acos(1.000000-(c*c)/(2.000000*R*R));
	n=2.000000*Pi/(gcd(gcd(A,B),C));
	Area=n*0.500000*R*R*sin(2.000000*Pi/n);
	printf("%.20lf",Area);
	return 0;
}
