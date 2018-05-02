#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
//grids in the simulation
#define DIM 25
#include <random>
using namespace std;

//Functions available
void Reset2Zero(double MatrixField[DIM][DIM][DIM]);
void PrintMatrix(double MatrixField[DIM][DIM][DIM]);

void PrintMatrixLayer(double MatrixField[DIM][DIM][DIM], int Z );
void AddMatrix(double MatrixField1[DIM][DIM][DIM], double MatrixField2[DIM][DIM][DIM], double Result[DIM][DIM][DIM]);
void MultiplyMatrix(double MatrixField1[DIM][DIM][DIM], double MatrixField2[DIM][DIM][DIM], double Result[DIM][DIM][DIM]);
void Laplacian(double MatrixField[DIM][DIM][DIM], double Result[DIM][DIM][DIM]);


/*Different boundary condition*/
void SquareBC1(double ElectricField[DIM][DIM][DIM],double Laplacian[DIM][DIM][DIM]);
void DiskBC1(double ElectricField[DIM][DIM][DIM],double Laplacian[DIM][DIM][DIM]);
void DiskBC2(double ElectricField[DIM][DIM][DIM],double Laplacian[DIM][DIM][DIM]);


void Reset2Constant(double MatrixField[DIM][DIM][DIM], double Value, double Variation){
  /*  This functions sets everyvalue in the matrix to a constant
  The Value is the value set up, and variation is the variation set up
  */

  std::default_random_engine generator;
  std::normal_distribution<double> distribution(Value,Variation);
  for(int i=0;i<DIM;i++){
     for(int j=0;j<DIM;j++){
        for(int k=0;k<DIM;k++){
            *(&MatrixField[i][j][k]) = distribution(generator);
        }
     }
  }
}


void AddMatrix(double MatrixField1[DIM][DIM][DIM], double MatrixField2[DIM][DIM][DIM], double Result[DIM][DIM][DIM]){
   /*This method will add two matrices elementwise*/

   for(int i=0;i<DIM;i++){
       for(int j=0;j<DIM;j++){
           for(int k=0;k<DIM;k++){
             Result[i][j][k] = MatrixField1[i][j][k] + MatrixField2[i][j][k];
           }
       }
   }
}


void SaveFile(){
  cout<<"Need to write this before the ";
}

void MultiplyMatrix(double MatrixField1[DIM][DIM][DIM], double MatrixField2[DIM][DIM][DIM], double Result[DIM][DIM][DIM]){
   /*This method will multiply two matrices element wise*/

   for(int i=0;i<DIM;i++){
       for(int j=0;j<DIM;j++){
           for(int k=0;k<DIM;k++){
             Result[i][j][k] = MatrixField1[i][j][k]*MatrixField2[i][j][k];
           }
       }
    }
}


void PrintMatrixLayer(double MatrixField[DIM][DIM][DIM], int Z){
  /* prints a specific layer in Z direction */

  for(int i=0;i<DIM;i++){
      for(int j=0;j<DIM;j++){
            cout<<MatrixField[i][j][Z];
            if(j<DIM-1){
               cout<<",";
            }
          }
      cout<<endl;
      }
}


void PrintMatrix(double MatrixField[DIM][DIM][DIM]){
  /*This function should print all the elements in a matrix*/
  for(int i=0;i<DIM;i++){
      for(int j=0;j<DIM;j++){
          for(int k=0;k<DIM;k++){
            cout<<MatrixField[i][j][k];
            if(k<DIM-1){
              cout<<",";
            }
          }
          cout<<endl;
      }
      cout<<endl;
  }
}


void SetValue(double Matrix1[DIM][DIM][DIM], double Matrix2[DIM][DIM][DIM]){
    /* This function sets the first matrix with the value from the second Matrix */

    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            for(int k=0;k<DIM;k++){
              Matrix1[i][j][k] = Matrix2[i][j][k];
            }
        }
     }
}


void SquareBC1(double ElectricField[DIM][DIM][DIM],double Result[DIM][DIM][DIM]){
  /*This is the implementation of the first boundary condition*/
  int RadCircle = (int)(DIM*0.7); //Radius of the circle

  //Set all the values
}


void DiskBC1(double ElectricField[DIM][DIM][DIM],double Laplacian[DIM][DIM][DIM]){
  /*This is the implementation of the first boundary condition*/
  cout<<"I will be implementing the first boundary condition";
}

void DiskBC2(double ElectricField[DIM][DIM][DIM],double Laplacian[DIM][DIM][DIM]){
  /*This is the implementation of the first boundary condition*/
  cout<<"I will be implementing the first boundary condition";
}

void Visualize(double Matrix[DIM][DIM][DIM], double Tau){
  /*This is the implementation of the first boundary condition*/

  double OutputMatrix[DIM][DIM];

  for(int k=DIM-1;k>-1;k--){
      for(int i=0;i<DIM;i++){
          for(int j=0;j<DIM;j++){
            OutputMatrix[i][j] = Tau*Matrix[i][j][k];
          }
      }
      Tau*=Tau;
   }

   //print the output matrix
}



void Laplacian(double MatrixField[DIM][DIM][DIM], double Result[DIM][DIM][DIM]){
  /*This method will calculate laplacian*/
  double Temp;
  for(int i=1;i<DIM-1;i++){
      for(int j=1;j<DIM-1;j++){
          for(int k=1;k<DIM-1;k++){
            Temp = MatrixField[i+1][j][k] + MatrixField[i-1][j][k] \
            + MatrixField[i][j+1][k] + MatrixField[i][j-1][k]\
             +MatrixField[i][j][k+1] + MatrixField[i][j][k-1];
            Result[i][j][k] = Temp-6.*MatrixField[i][j][k];
          }
      }
  }
}




#endif
