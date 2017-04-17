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
#include <bitset>

#include "VectorExtras.h"

using namespace std;

void VectorExtras::initRandom(){srand(time(0));};

void VectorExtras::printVec(vector<double> bin){};

double VectorExtras::randDouble(double min, double max){
   double r = ((double) rand() / (RAND_MAX));
   r = r * (max-min)+min;
   return r;
};

int VectorExtras::randInt(int min, int max)
{
   int r;
   r = (rand()%max)+min;
   return r;
}



double VectorExtras::Sigmoid(double x){
    return 1 / (1 + exp(-x));
};


double VectorExtras::rand_normal(double mean, double stddev, double min, double max )
{//Box muller method
    static double n2 = 0.0;
    static double salida = 0.0;
    static int n2_cached = 0;
    if (!n2_cached)
    {
        double x, y, r;
        do
        {
            x = 2.0*rand()/RAND_MAX - 1;
            y = 2.0*rand()/RAND_MAX - 1;

            r = x*x + y*y;
        }
        while (r == 0.0 || r > 1.0);
        {
            double d = sqrt(-2.0*log(r)/r);
            double n1 = x*d;
            n2 = y*d;
            double result = n1*stddev + mean;
            n2_cached = 1;
            if(result>max){return max;}
            if(result<min){return min;}
            return result;
        }
    }
    else
    {
        n2_cached = 0;
        salida = n2*stddev + mean;
        if(salida>max){return max;}
        if(salida<min){return min;}
        return salida;
    }
}

vector<double> VectorExtras::vectorDoubleRand(int len ,double min, double max){
    vector<double> salida ;
    for(int i = 0 ; i < len ; i++ ){
        salida.push_back(randDouble(min, max));
    }
    return salida; 
};



///////////////////////////////Geneticos EE
void VectorExtras::MUTACION(vector<double> P1,vector<double> Ps1, vector<double> &H1){
    //vector<double> H1;
    double tem;
    for(int i = 0 ; i < P1.size() ; i++ ){
        tem=P1[i]+rand_normal(0, Ps1[i], -1.0, 1.0 );
        if(tem>1){
            tem=1;
        }else if(tem<0){
            tem=0;
        }

        H1.push_back(rand_normal(P1[i], Ps1[i], 0.0, 1.0 ));
    }
    //return H1; 
};

void VectorExtras::CRUCENormal(vector<double> P1,vector<double> P2,vector<double> &H1,vector<double> &H2){
    for(int i = 0 ; i < P1.size() ; i++ ){
        if(randDouble(0, 0.5)<0.5){
            H2.push_back(P2[i]);
            H1.push_back(P1[i]);
        }else{
            H2.push_back(P1[i]);
            H1.push_back(P2[i]);  
        }
    }
    //return hijos; 
};/**/


void VectorExtras::CRUCEMath(vector<double> P1,vector<double> P2, vector<double> &H1){
    //vector<double> H1;
    for(int i = 0 ; i < P1.size() ; i++ ){
        H1.push_back((P1[i]+P2[i])*0.5);
    }
    //return H1; 
};

///////////////////////////////Geneticos DE

bool VectorExtras::MutacionDE(double Cr, double F, vector<double> Pi, vector<double> P0, vector<double> P1, vector<double> P2, vector<double> &H1){
    int jrand = randInt(0, P1.size());
    double tem;
    bool valido=true;
    for(int i = 0 ; i < Pi.size() ; i++ ){
        if((randDouble(0.0, 1.0)<= Cr)||(i==jrand)){
            tem=P0[i]+F*(P1[i]-P2[i]);
            if(tem>1){
                valido=false;
            }else if(tem<0){
                valido=false;
            }
            H1.push_back(tem);
        }else{
            H1.push_back(Pi[i]);
        }
    }/**/
    return valido;
};