using namespace std;
#include <iostream>
#include <stdio.h>
int main(){

 double a, b, c, media;
	cin >> a ;
	cin>> b;
	cin >> c;

 media = (a/10 * 2) + (b/10 * 3) + (c/10 * 5);
 printf("MEDIA = %.1lf\n", media);
 return 0;
}
