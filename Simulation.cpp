#include<iostream>
#include<cmath>
#include "Functions.h"
#include "Constant.h"

//The constants in the simulation

#define N 25 //The meshing of the dimension. Simultaneously change to same value in Library.h


using namespace std;

int main(){

  //Simulation Specific constants
  double const DiamFrac = 0.70;             //Fraction that the hole covers
  double const Resistance = 1e7;            //Resistance in parallel
  double const Gamma = 0.31;                //Secondary emission coefficient
  double const ActualDIM = 750e-6/(0.7*DIM); //Actual Diameter
  double const CellVolume = ActualDIM*ActualDIM*ActualDIM; //Volume of a cell
  int HeightDIM = (int)(DiamFrac*DIM);


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
  PrintMatrixLayer(Electron,10);


  double TimeStart = 0.0;
  double TimeStop = 10.0;
  double TimeStep = 1e-3;

  while(TimeStart<TimeStop){
    cout<<TimeStart<<endl;
    TimeStart+=TimeStep;
  }


  //Calculate the breakdown voltage

  //Write a routine to calculate the electric field


  //Apply the Boundary conditions


  //Voltage application curve

  //Print the Output and save in a given file



  return 0;
}
