#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
using namespace std;

int main(){
    ofstream outfile;
    int Nx = 101;
    int Nt = 601;
    float delta_x = 0.01;
    float delta_t = 0.01;
    float c_g = delta_x/delta_t;
    float c = 0.5;
    float prop = (c*c)/(c_g*c_g);
    float X[3][Nx];
    int i,j;
    
    X[0][0] = 0.0;
    X[0][Nx-1] = 0.0;
    X[1][0] = 0.0;
    X[1][Nx-1] = 0.0;
    
    for (j = 0; j < Nx; j++){
        X[0][j] = sin(M_PI*i/100);
        X[1][j] = X[0][j] + 0.5*prop*(X[0][j+1] + X[0][j-1] - 2*X[0][j]);
    }
    
    outfile.open("data.dat");
      
    for (i = 2 ; i < Nt; i++){
        for (j = 1; j < Nx; j++){
            X[2][j] = 2*X[1][j] - X[0][j] + prop*(X[1][j+1] + X[1][j-1] - 2*X[1][j]);            
        }
        for (i = 0; i < Nx; i++){
            X[0][i] = X[1][i];
            X[1][i] = X[2][i];
        }
        for (j = 0; j < Nx; j++){
            outfile << X[1][j] << " ";
        } 
        outfile << "\n";
    }
    
    return 0;
    
}
