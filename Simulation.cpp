#include<iostream>
#include<cmath>
#include<vector>
#include "Library.h"

#define N 2 //The meshing of the dimension

using namespace std;

int main(){
  //Initiating a rectangular matrix

  double ElectricField[N][N][N];


  Reset2Zero(ElectricField);
  PrintMatrix(ElectricField);

  AddMatrix(ElectricField, ElectricField);
  return 0;
}
