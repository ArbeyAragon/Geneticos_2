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

#include "swarm.h"
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





SWARM::SWARM(int iter, int NPobl, long tid){
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
struct distanciaCr
{
    inline bool operator() (Indiv i,Indiv j){
        return (i.distancia<j.distancia);
    }
};

void SWARM::run(){
    string title = "SWARM_";
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

    int pi0=0;
    int pi1=0;
    int pi2=0;
    int lenGen=poblacion.size();


    int posTem; 

    double distT=0;

    cout<<"*******************"<<endl;
    vector<double> bestLocal;
    vector<double> best;
    for(int j = 0 ; j < iteraciones ; j++){
        //vector<Indiv> poblacionNew;
        ///////////////////Cruce1
        
        sort(poblacion.begin(),poblacion.end(), less_than_key());
        best = poblacion[0].getVect();
        cout<<poblacion[0].getFitness()<<endl;/**/
        archivo->addLine((poblacion[0]).getVect(),(poblacion[0]).getFitness());
        
        for(int i = 0 ; i < Pobl ; i++){
            for(int k = 3 ; k < Pobl ; k++){
                if(i!=k){
                    distT=VectorExtras::SWARMDistancia(poblacion[i].getVect(),poblacion[k].getVect());
                    poblacion[i].distancia=distT;
                }else{
                    poblacion[i].distancia=0;
                }
            }
            sort(poblacion.begin(),poblacion.end(), distanciaCr());
            if((poblacion[1].getFitness()>=poblacion[2].getFitness())&&(poblacion[1].getFitness()>=poblacion[3].getFitness())){
                bestLocal=poblacion[1].getVect();
            }else if((poblacion[2].getFitness()>=poblacion[1].getFitness())&&(poblacion[2].getFitness()>=poblacion[3].getFitness())){
                bestLocal=poblacion[2].getVect();
            }else{
                bestLocal=poblacion[3].getVect();
            }
            vector<double> x;
            vector<double> v;
            VectorExtras::SWARMInercia(0.1, 0.2, 0.1, poblacion[i].getVect(), poblacion[i].getVectSigma(), best, bestLocal, x, v);
            poblacion[i].setVectSigmaEE(x, v);
        }

        




    }
    cout<<"*******************"<<endl;
    delete archivo;

};


SWARM::~SWARM(){ }; 