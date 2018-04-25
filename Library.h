#ifndef MATHFUNC_H_INCLUDED
#define MATHFUNC_H_INCLUDED
#define DIM 2 //Change this later

using namespace std;

//Functions available
void Reset2Zero(double MatrixField[DIM][DIM][DIM]);
void PrintMatrix(double MatrixField[DIM][DIM][DIM]);
void AddMatrix(double MatrixField1[DIM][DIM][DIM], double MatrixField2[DIM][DIM][DIM], double Result[DIM][DIM][DIM]);
void MultiplyMatrix(double MatrixField1[DIM][DIM][DIM], double MatrixField2[DIM][DIM][DIM], double Result[DIM][DIM][DIM]);
void BoundaryCondition1(double MatrixField[DIM][DIM][DIM]);
void BoundaryCondition2(double MatrixField[DIM][DIM][DIM]);





void Reset2Zero(double MatrixField[DIM][DIM][DIM]){
  /*
  This functions sets everything to zero
  N is dimenstion of the matrix
  */
  for(int i=0;i<DIM;i++){
     for(int j=0;j<DIM;j++){
        for(int k=0;k<DIM;k++){
            MatrixField[i][j][k] = 0.0;
        }
     }
  }
}




void PrintMatrix(double MatrixField[DIM][DIM][DIM]){
  /*This function should print all the elements
  in a matrix*/
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





void AddMatrix(double MatrixField1[DIM][DIM][DIM], double MatrixField2[DIM][DIM][DIM], double Result[DIM][DIM][DIM]){
   /*This method will add two matrices elementwise*/
   for(int i=0;i<DIM;i++){
       for(int j=0;j<DIM;j++){
           for(int k=0;k<DIM;k++){
             Result[i][j][k] = MatrixField1[i][j][k] + MatrixField2[i][j][k]
           }
       }
}



void MultiplyMatrix(double MatrixField1[DIM][DIM][DIM], double MatrixField2[DIM][DIM][DIM], double Result[DIM][DIM][DIM]){
   /*This method will multiply two matrices element wise*/
   for(int i=0;i<DIM;i++){
       for(int j=0;j<DIM;j++){
           for(int k=0;k<DIM;k++){
             Result[i][j][k] = MatrixField1[i][j][k]*MatrixField2[i][j][k]
           }
       }
    }
}

void BoundaryCondition1(double MatrixField[DIM][DIM][DIM]){
  /*This is the implementation of the first boundary condition*/
  cout<<"I will be implementing the first boundary condition";
}



void BoundaryCondition2(double MatrixField[DIM][DIM][DIM]){
  /*This is the implementation of the first boundary condition*/
  cout<<"I will have to implement the second boundary condition";
}


#endif
