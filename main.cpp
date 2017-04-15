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
#define NUM_THREADS     10

/*
void *sim(void *){
    HC* asc = new HC(100);
    asc->run();
    delete asc;

    return NULL
}/**/

void *PrintHello(void *threadid) {
   long tid;
   tid = (long)threadid;
   cout<< endl << "Hello World! Thread ID, " << tid << endl;

    HC* asc = new HC(100,tid);
    asc->run();
    delete asc;
   pthread_exit(NULL);
}/**/

int main()
{	
    VectorExtras::initRandom();

    //pthread_t threads[NUM_THREADS];
    HC* asc ;
    //for(long i = 0; i<NUM_THREADS; i++){
        asc = new HC(100,5);
        asc->run();
        //asc.~HC();/**/
        delete asc;
        //pthread_t thread;
        //pthread_create(&threads[i], NULL, PrintHello, (void*)i);
    //}


    //char result[100];   // array to hold the result.
    string one = "Hello ";
    string two = "World";
    long number = 123;
    //sprintf(one, "hola %d .txt",f4);
    

    ostringstream str1;
 
    // Sending a number as a stream into output
    // string
    str1 << number;
 
    // the str() coverts number into string
    string geek = str1.str();

    cout <<endl<< one+two+geek<<endl;
    //long f4 = 123;
    //string f_str4 = to_string(f4);
    
    //cout << f_str4;

    //string::strcat(one,two); // copy string one into the result.
    //cout<<one;

    return 0;
}

