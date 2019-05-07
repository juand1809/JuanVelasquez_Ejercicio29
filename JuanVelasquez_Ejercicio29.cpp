#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    ofstream outfile;
    int Nx = 100;
    int Nt = 3;
    float delta_x = 0.001;
    float delta_t = 0.001;
    float ro = 0.001;
    float T = 500.0;
    float c_g = delta_x/delta_t;
    float c = sqrt(T/ro);
    float X[Nx+1][Nt];
    int i,j;
    
    for (j = 0; j < Nt;j++){
        X[0][j] = 0.0;
        X[Nx][j] = 0.0;
    }
    
    for (i = 1; i < Nx+1; i++){
        for (j = 1; j < Nt; j++){
            if(j == 2){
                X[i][j] = X[i][1] + ((c*c)/2*(c_g*c_g))*(X[i+1][1] + X[i-1][1] -2*X[i][1]);
            }
            else{
                X[i][j+1] = 2*X[i][j] - X[i][j-1] + ((c*c)/2*(c_g*c_g))*(X[i+1][1] + X[i-1][1] -2*X[i][1]);
            }
        }
    }
    
    
    
    
}