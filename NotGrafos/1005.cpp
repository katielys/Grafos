#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    float x,y,media;
	cin >>x ;
	cin>> y;
	media =(x/11 * 3.5) + (y/11 * 7.5);
    printf("MEDIA = %.5f\n", media);
    return 0;
}
