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

    for(int j = 0 ; j < iteraciones ; j++){
        vector<Indiv> poblacionNew;
        ///////////////////Cruce1
        for(int i = 1 ; i < Pobl ; i++){
            
            vector<double> VecW_H1;
            vector<double> VecW_H2;

            vector<double> VecSigma_H1;
            vector<double> VecSigma_H2;


            VectorExtras::CRUCENormal(poblacion[i].getVect(),poblacion[i-1].getVect(),VecW_H1,VecW_H2);
            VectorExtras::CRUCENormal(poblacion[i].getVectSigma(),poblacion[i-1].getVectSigma(),VecSigma_H1,VecSigma_H2);

            Indiv H1 = Indiv(VecW_H1,VecSigma_H1);
            Indiv H2 = Indiv(VecW_H1,VecSigma_H1);
            
            poblacionNew.push_back(H1);
            poblacionNew.push_back(H2);
        }
        ///////////////////Cruce2
        for(int i = 1 ; i < Pobl ; i++){
            vector<double> VecW_H1;
            vector<double> VecSigma_H1;

            VectorExtras::CRUCEMath(poblacion[i].getVect(),poblacion[i-1].getVect(),VecW_H1);
            VectorExtras::CRUCEMath(poblacion[i].getVectSigma(),poblacion[i-1].getVectSigma(),VecSigma_H1);

            Indiv H1 = Indiv(VecW_H1,VecSigma_H1);
            poblacionNew.push_back(H1);
        }

            ///////////////////Mutacion
        for(int i = 0 ; i < Pobl ; i++){
            vector<double> VecW_H1;
            VectorExtras::MUTACION(poblacion[i].getVect() , poblacion[i].getVectSigma(), VecW_H1);
            Indiv H1 = Indiv(VecW_H1,poblacion[i].getVectSigma());
            poblacionNew.push_back(H1);
        }
        
        poblacionNew.swap(poblacion);
        poblacion.clear();

        sort(poblacionNew.begin(),poblacionNew.end(), less_than_key());

        for(int i = 0 ; i < Pobl ; i++){
            poblacion.push_back(poblacionNew[i]);
            //cout<<poblacionNew[i].getFitness()<<endl;
        }
        cout<<poblacion[0].getFitness()<<endl;
        poblacionNew.clear();
    }
    cout<<"*******************"<<endl;
    for(int i = 0 ; i < Pobl ; i++){
        cout<<poblacion[i].getFitness()<<endl;
    }

/*

    ///////////////////Mutacion
    for(int i = 0 ; i < Pobl ; i++){
        poblacionNew.push_back(Indiv());
    }

/**/
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