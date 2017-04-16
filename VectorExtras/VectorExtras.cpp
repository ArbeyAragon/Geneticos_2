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