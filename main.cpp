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
#include <sstream>
#include <string>
#include <pthread.h>

#include "Individuo/Indiv.h"
#include "VectorExtras/VectorExtras.h"

#include "HC/hc.h"
#include "EE/ee.h"

using namespace std;
#define NUM_THREADS     30



int contTerminate = 0;
void detenida(long id){
    contTerminate++;
    cout<<"terminado  id:"<<id<<" contador:"<<contTerminate<<endl;
}

void *EjecutaHilosHC(void *threadid) {
   long tid;
   tid = (long)threadid;
   cout<< endl << "Hilos iniciado, " << tid << endl;

    HC* asc = new HC(100000,tid);
    asc->run();
    delete asc;
    detenida(tid);
   pthread_exit(NULL);
}



void HCExect(){
    pthread_t threads[NUM_THREADS];
    long tem=0;
    long tem1=0;
    for(int j = 0;j<3;j++){
        for(int i = 0; i<10; i++){
            cout<<tem<<endl;
            
            pthread_create(&threads[tem], NULL, EjecutaHilosHC, (void*)tem);
            tem++;
        }
        for(long i = 0; i<10; i++){ 
            
            pthread_join(threads[tem1], NULL); 
            tem1++; 
        }
    }
}



int main()
{	
    VectorExtras::initRandom();
    
    //HCExect();
    /*
    HC* asc ;
    asc = new HC(1000,5);
    asc->run();
    delete asc;/**/

    
    EE* asc ;
    asc = new EE(1000,10,5);
    asc->run();
    delete asc;
    /**/


    return 0;
}

