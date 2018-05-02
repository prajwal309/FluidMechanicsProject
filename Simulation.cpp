//importing the standard libraries
#include<iostream>
#include<cmath>
#include <fstream>

//importing the user defined functions
#include "Functions.h"
#include "Constant.h"

//The constants in the simulation

#define N 25 //The meshing of the dimension. Simultaneously change to same value in Library.h


using namespace std;

void SaveDataCube(double DataCube[N][N][N], string FileName){
  ofstream Save3Dfile;
  Save3Dfile.open ("Data/"+FileName);

  for(int i=0;i<DIM;i++){
      for(int j=0;j<DIM;j++){
          for(int k=0;k<DIM;k++){
            cout<<i<<","<<j<<","<<k<<"::"<<DataCube[i][j][k]<<endl;

            Save3Dfile<<DataCube[i][j][k];
            if(k<DIM-1){
              Save3Dfile<<",";
            }
            else{
              Save3Dfile<<endl;
            }
          }
          Save3Dfile<<endl;
      }

  }
  Save3Dfile.close();
  cout<<"saving to the file"<<FileName<<endl;
}

void SaveDataMatrix(double DataCube[N][N][N], string FileName){
  /*This shows saves the data file*/

  double Output[N][N];


  ofstream myfile;
  myfile.open ("Data/"+FileName);
  myfile << "Writing this to a file.\n";
  myfile << "Writing this to a file.\n";
  myfile << "Writing this to a file.\n";
  myfile << "Writing this to a file.\n";
  myfile.close();
  cout<<"saving to the file"<<FileName<<endl;
}


int main(){

  //Simulation Specific constants
  double const DiamFrac = 0.70;             //Fraction that the hole covers
  double const Resistance = 1e7;            //Resistance in parallel
  double const Gamma = 0.31;                //Secondary emission coefficient
  double const ActualDIM = 750e-6/(0.7*DIM); //Actual Diameter
  double const CellVolume = ActualDIM*ActualDIM*ActualDIM; //Volume of a cell
  int HeightDIM = (int)(DiamFrac*DIM);

  string SaveFileName;
  cout<<SaveFileName;

  //Initiating data cubes
  double Xenon[N][N][N];
  double Electron[N][N][N];
  double Plasma[N][N][N];

  //Initial condition
  double PressureTorr = 120;                     //Pressure in Torr
  double Pressure= PressureTorr*133.322;         //Convert pressure to pascal
  double Temp = 300.;                            //Room temperature

  //Calculating the mobility of the ions
  //double ElecMobility = 13.0/PressureTorr;
  //double KrMobility = 13.0/(PressureTorr);

  double Density = Pressure*NitroMu*2.*AMU/(Boltzmann*Temp);
  double Variation = Density*0.01;


  //Fill the chamber with XenonMu
  Reset2Constant(Xenon, Density, Variation);
  Reset2Constant(Electron, 0.0, 0.0);

  //PrintMatrixLayer(Xenon, 10);
  //PrintMatrixLayer(Electron,10);


  double TimeNow = 0.0;
  double TimeStop = 1.0;
  double TimeStep = 3e-2;

  cout<<"The Time Start is "<<TimeNow<<endl;
  cout<<"The Time Stop is "<<TimeStop<<endl;

  //Use the relaxation method the find the electric field

  //Calculate the breakdown voltage
  //Try upto breakdown voltage
  //Write a routine to calculate the electric field

  int counter = 0;  //
  double LastSaveTime = TimeNow;
  double SaveInterval = TimeStep*10.;
  while(TimeNow<TimeStop){
    //cout<<TimeStart<<endl;
    //Apply the Boundary conditions

    //Do the calculation until the things work out...
    TimeNow+=TimeStep;



    if(SaveInterval<(TimeNow-LastSaveTime)){
      string TempString = to_string(counter);
      SaveFileName = "DataCube"+TempString+".txt";
      SaveDataCube(Xenon, SaveFileName);
      LastSaveTime = TimeNow;
      counter++;
    }
    //cout<<"Find the paper::"<<SaveFileName;
    //SaveFile(double Plasma, string FileName);

    //Save Data cube
  }









  //Voltage application curve

  //Print the Output and save in a given file



  return 0;
}
