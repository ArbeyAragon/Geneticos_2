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

#include "de.h"
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





DE::DE(int iter, int NPobl, long tid){
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


void DE::run(){
    string title = "DE_";
    MyFILE* archivo = new MyFILE(title, id); 

    /* Poblacion Inicial */   
    vector<Indiv> poblacion;
    for(int i = 0 ; i < Pobl ; i++){
        poblacion.push_back(Indiv());
    }

    sort(poblacion.begin(),poblacion.end(), less_than_key());
    
    for(int i = 0 ; i < Pobl ; i++){
        cout<<poblacion[i].getFitness()<<endl;
    }

    cout<<"DE *******************"<<endl;
    int pi0=0;
    int pi1=0;
    int pi2=0;
    bool valido=true;
    int lenGen=poblacion.size();
    //vector<Indiv> poblacionNew;
    for(int j = 0 ; j < iteraciones ; j++){
        vector<Indiv> poblacionNew;


        for(int i = 0 ; i < Pobl ; i++){
            valido=true;
            do{ pi0=VectorExtras::randInt(0,lenGen); }while( pi0==i );
            do{ pi1=VectorExtras::randInt(0,lenGen); }while( (pi0==i) || (pi0==pi1) );
            do{ pi2=VectorExtras::randInt(0,lenGen); }while( (pi0==i) || (pi0==pi1) || (pi1==pi2) );/**/

            vector<double> VecW_H1;
            valido=VectorExtras::MutacionDE(Cr, F, poblacion[i].getVect(), poblacion[pi0].getVect(), poblacion[pi1].getVect(), poblacion[pi2].getVect(), VecW_H1);
            Indiv H1 = Indiv(VecW_H1);
            if((poblacion[i].getFitness()<=H1.getFitness()) && valido){
                poblacionNew.push_back(H1);
            }else{
                poblacionNew.push_back(poblacion[i]);
            }/**/
        }
        poblacion.clear();
        sort(poblacionNew.begin(),poblacionNew.end(), less_than_key());
        for(int i = 0 ; i < Pobl ; i++){
            poblacion.push_back(poblacionNew[i]);
        }
        poblacionNew.clear();
        cout<<poblacion[0].getFitness()<<endl;/**/
        archivo->addLine((poblacion[0]).getVect(),(poblacion[0]).getFitness());
    }
    delete archivo;

};


DE::~DE(){ }; 