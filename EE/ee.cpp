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

#include "ee.h"
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





EE::EE(int iter, int NPobl, long tid){
    iteraciones=iter;
    id=tid;
    Pobl=NPobl;
};


struct less_than_key
{
    inline bool operator() (Indiv i,Indiv j){
        return (i.getFitness()>j.getFitness());
    }
};


void EE::run(){
    string title = "EE_";
    //MyFILE* archivo = new MyFILE(title, id); 

    /* Poblacion Inicial */   
    vector<Indiv> poblacion;
    for(int i = 0 ; i < Pobl ; i++){
        poblacion.push_back(Indiv());
    }

    sort(poblacion.begin(),poblacion.end(), less_than_key());
/*
    for(int i = 0 ; i < Pobl ; i++){
        cout<<poblacion[i].getFitness()<<endl;
    }/**/


    //Indiv SujMejor2;
    /*
    for(int i=0 ; i<iteraciones ; i++){
        
        SujMejor2 = Indiv();
        
        if((SujMejor2).getFitness()>(SujMejor).getFitness()){
            SujMejor.~Indiv();
            SujMejor=SujMejor2;
        }
        //archivo->addLine((SujMejor).getVect(),(SujMejor).getFitness());
    }/**/
    //delete archivo;

};


EE::~EE(){ }; 