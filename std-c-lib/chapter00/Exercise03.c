/*
 * Exercise 0.3
 *
 */
#include<stdio.h>

double sqr(x) {return (x * x);}
//#define sqr(x) x * x
//#define sqr(x) ((x) * (x))

main()
{
	double a[] = {1.0, 2.0};
	double *p = a;

	printf("sqr(3.0)=%lf\n", (sqr(3.0)));
	printf("sqr(3)=%lf\n", sqr(3));
	printf("sqr(3 + 3)=%lf\n", sqr(3 + 3));
	printf("!sqr(3)=%lf\n", !sqr(3));
	printf("sqr(*p++)=%lf\n", sqr(*p++));
//	printf("(sqr)(3 + 3)=%e\n", (sqr)(3 + 3));
}

/*
[angelo@centos chapter00]$ ./a.out 
sqr(3.0)=9.000000e+00
sqr(3)=9
sqr(3 + 3)=15
!sqr(3)=0
sqr(*p++)=2.000000e+00
(sqr)(3 + 3)=3.600000e+01
[angelo@centos chapter00]$ 
 */

/*
 Exercise 0.4:1,3.4.5
 */

/*
 Exercise 0.5: 
 can:
 cannot: 6
 */
