#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int a, b, c, maiorAb, maior;
    cin >> a ;
	cin>> b;
	cin >> c;
    maiorAb = (a+b+abs(a-b))/2;
    maior = (maiorAb+c+abs(maiorAb-c))/2;
    cout << maior << " eh o maior" << endl;
    return 0;
}
