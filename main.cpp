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
//#include <pthread.h>
//#include <sstream>

#include "Individuo/Indiv.h"
#include "VectorExtras/VectorExtras.h"

#include "HC/hc.h"

using namespace std;
#define NUM_THREADS     30

pthread_t threads[NUM_THREADS];

int contTerminate = 0;
void detenida(long id){
    contTerminate++;
    cout<<"terminado  "<<id<<" "<<contTerminate<<endl;
}

void *EjecutaHilos(void *threadid) {
   long tid;
   tid = (long)threadid;
   cout<< endl << "Hilos iniciado, " << tid << endl;

    HC* asc = new HC(10000,tid);
    asc->run();
    delete asc;
    detenida(tid);
   pthread_exit(NULL);
}

int main()
{	
    VectorExtras::initRandom();
    int rc;
    
    //HC* asc ;
    for(long i = 0; i<NUM_THREADS; i++){
        cout<<i<<endl;
        //asc = new HC(1000,5);
        //asc->run();
        //delete asc;
        //pthread_t thread;
        pthread_create(&threads[i], NULL, EjecutaHilos, (void*)i);
    }
    for(long i = 0; i<NUM_THREADS; i++){ pthread_join(threads[i], NULL);  }
    
    return 0;
}

