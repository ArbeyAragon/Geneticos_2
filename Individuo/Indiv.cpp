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
/*
void initRandom(){srand(time(0));};

double randDouble(double min, double max){
   double r = ((double) rand() / (RAND_MAX));
   r = r * (max-min)+min;
   return r;
};

vector<double> vectorDoubleRand(int len ,double min, double max){
    vector<double> salida ;
    for(int i = 0 ; i < len ; i++ ){
        salida.push_back(randDouble(min, max));
    }
    return salida; 
};/**/


Indiv::Indiv(vector<double> vec){
    //initRandom();
    VecW=vec;
    fitness=fitnessCalc();
};/**/
Indiv::Indiv(){
    //initRandom();
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
    vector<double>().swap(VecW);
    //ecW.~vector<double>();
};
