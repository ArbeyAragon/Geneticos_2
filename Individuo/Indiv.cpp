#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <cstdlib> 
#include <ctime> 
#include <vector>
#include <stdio.h>  
#include <time.h>  
#include <math.h> 
#include <algorithm>

#include "Indiv.h"
#include "../VectorExtras/VectorExtras.h"


using namespace std;


Indiv::Indiv(vector<double> vec){
    VecW=vec;
    fitness=fitnessCalc();
};
Indiv::Indiv(){
    VecW=VectorExtras::vectorDoubleRand(len ,0, 1);
    fitness=fitnessCalc();
};


double Indiv::getFitness(){
    return fitness;
};

void Indiv::setVec(vector<double> binario){};
vector<double> Indiv::getVect(){return VecW;};


double Indiv::fitnessCalc(){
    double sum=0;
    for(int i=0; i < VecW.size(); i++){
        sum=sum+VecW[i];
    }
    return sum;
};

void Indiv::guarda(){};

Indiv::~Indiv(){
    VecW.clear();
    //ecW.~vector<double>();
};
