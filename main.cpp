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
#include "DE/de.h"
#include "SWARM/swarm.h"

using namespace std;
#define NUM_THREADS     30

int Algoritmo=0;
int iter=100;

int contTerminate = 0;
void detenida(long id){
    contTerminate++;
    cout<<"terminado  id:"<<id<<" contador:"<<contTerminate<<endl;
}

void *EjecutaHilos(void *threadid) {
   long tid;
   tid = (long)threadid;
   cout<< endl << "Hilos iniciado, " << tid << endl;
   if(Algoritmo==0){
        HC* asc = new HC(iter,tid);
        asc->run();
        delete asc;
   }
   if(Algoritmo==1){
        EE* asc = new EE(iter,100,tid);
        asc->run();
        delete asc;
    }
   if(Algoritmo==2){
        DE* asc = new DE(iter,100,tid);
        asc->run();
        delete asc;
    }
   if(Algoritmo==3){
        SWARM* asc = new SWARM(iter,100,tid);
        asc->run();
        delete asc;
    }



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
            
            pthread_create(&threads[tem], NULL, EjecutaHilos, (void*)tem);
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
    
    HCExect();

    Algoritmo++;
    HCExect();


    Algoritmo++;
    HCExect();


    Algoritmo++;
    HCExect();


    /*
    HC* asc = new HC(1000,5);
    asc->run();
    delete asc;/**/

    /*
    EE* asc = new EE(1000,60,5);
    asc->run();
    delete asc;
    /**/

/*
    DE* asc = new DE(1000,60,5);
    asc->run();
    delete asc;
    /**/
    /*
    SWARM* asc = new SWARM(10000,60,5);
    asc->run();
    delete asc;/**/

    return 0;
}

