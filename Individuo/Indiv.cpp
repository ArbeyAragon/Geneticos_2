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

Indiv::Indiv(vector<double> vec, vector<double> sigma){
    VecW=vec;
    VecSigma=sigma;
    fitness=fitnessCalc();
};

Indiv::Indiv(vector<double> vec){
    VecW=vec;
    fitness=fitnessCalc();
};

Indiv::Indiv(){
    VecW=VectorExtras::vectorDoubleRand(len ,0, 1);
    VecSigma=VectorExtras::vectorDoubleRand(len ,0, 0.1);
    fitness=fitnessCalc();
};


double Indiv::getFitness(){
    return fitness;
};

void Indiv::setVect(vector<double> vec){ VecW=vec; };
void Indiv::setVectSigma(vector<double> sigma){ VecSigma=sigma; };
void Indiv::setVectSigmaEE(vector<double> vec, vector<double> sigma){
    VecW=vec;
    VecSigma=sigma;
};

vector<double> Indiv::getVect(){ return VecW; };
vector<double> Indiv::getVectSigma(){ return VecSigma; };



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
    VecSigma.clear();

    vector<double>().swap(VecW);
    vector<double>().swap(VecSigma);
};
