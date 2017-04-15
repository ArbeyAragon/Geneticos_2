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
#include <string>
#include <sstream>

#include "hc.h"
#include "../Individuo/Indiv.h"
#include "../VectorExtras/VectorExtras.h"


using namespace std;

class MyFILE
{
public:
    MyFILE(string title, long id){
        ostringstream str1;
        str1 << id;
        string res = "Resultados/";
        string txt = ".txt";
        string fileT = res+title+str1.str()+txt;
        doc = fopen(fileT.c_str(),"w");
    };

    void addLine(vector<double> w,double fitness){
        fprintf(doc,"%5.5f,",fitness);
        for(int i = 0; i< w.size();i++){
            //cout<<w[i]<<endl;
            fprintf(doc,"%5.5f",w[i]);
            if(i==(w.size()-1)){
                fprintf(doc,"\n");
            }else{
                fprintf(doc,",");
            }
        }
        
    
    };

    virtual ~MyFILE(){fclose(doc);};
private:
    FILE * doc;
};/**/




HC::HC(int iter,long tid){
    iteraciones=iter;
    id=tid;
    SujMejor = new Indiv();
    //Indiv SujMejor2 = Indiv();;
    //SujMejor=&SujMejor2;
};

void HC::run(){
    string title = "HC_";
    MyFILE* archivo = new MyFILE(title, id);

    Indiv* SujMejor2;
    for(int i=0 ; i<iteraciones ; i++){
        //cout<<i<<"*****"<<id<<"*****";
        SujMejor2 = new Indiv();
        if(SujMejor2->getFitness()>SujMejor->getFitness()){
            delete SujMejor;
            SujMejor=SujMejor2;
            
        }
        
        //cout<<SujMejor->getFitness()<<endl;
        archivo->addLine(SujMejor->getVect(),SujMejor->getFitness());
    }
    delete archivo;
    //cout<<endl;
};

void HC::save(string id){};

HC::~HC(){  /*delete SujMejor;*/ };