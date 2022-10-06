#include <stdio.h>

int main(void)
{
	long a[30000];
	int p = 0;

	p++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	while (a[p]) {
		p--;
		a[p]++;
		a[p]++;
		a[p]++;
		a[p]++;
		a[p]++;
		a[p]++;
		a[p]++;
		a[p]++;
		p++;
		a[p]--;
	}
	p--;
	a[p]++;
	a[p]++;
	a[p]++;
	/* prints 'S' */
	putchar(a[p]);

	p++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	while (a[p]) {
		p--;
		a[p]++;
		a[p]++;
		a[p]++;
		a[p]++;
		p++;
		a[p]--;
	}
	p--;
	/* print 'c' */
	putchar(a[p]);

	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	/* print 'h' */
	putchar(a[p]);

	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	/* print 'oo' */
	putchar(a[p]);
	putchar(a[p]);

	a[p]--;
	a[p]--;
	a[p]--;
	/* print 'l' */
	putchar(a[p]);

	p++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	a[p]++;
	while (a[p]) {
		p--;
		a[p]--;
		a[p]--;
		a[p]--;
		a[p]--;
		a[p]--;
		a[p]--;
		a[p]--;
		a[p]--;
		a[p]--;
		a[p]--;
		p++;
		a[p]--;
	}
	p--;
	a[p]++;
	a[p]++;
	/* prints '\n' */
	putchar(a[p]);
	return (0);
}
