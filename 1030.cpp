#include<vector>
#include <iostream>
using namespace std;
//1030 uri
// Katiely dos Santos Oliveira Moreira - 21600808
int posic(int n, int k){
	if (n==1){
		return 0;
	}
	else{
		return  (posic(n-1,k)+k)%n;
	}
}
int main (){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		int m,k;
		cin >> m;
		cin>> k;
		cout<<"Case "<<i+1<<": "<<posic(m,k)+1<<endl;
	}

	return 0;
}
