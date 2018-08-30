#include <iostream>
//uri 1862 - casa de Westeros
// MoskRocks- 30.08

using namespace std;

char matrix[100000][100000];

int main (){
    int numberOfCases = 0;
    //char aux;
    
    cin << numberOfCases; 
    for (int i=0;i<numberOfCases;i++){
        for (int j=0;j<numberOfCases;j++){
            cin << matrix[i][j];
        }
    }
       
    
    return 0;
}