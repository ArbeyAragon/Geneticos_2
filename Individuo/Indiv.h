#ifndef INDIV_H
#define INDIV_H

#include <vector>

using namespace std;

class Indiv
{
    private:
        vector<double> VecW;
		vector<double> VecSigma;

        double fitness;
		double fitnessCalc();
    public:
        static const int len=100; 
		Indiv(vector<double> vec, vector<double> sigma);
		Indiv(vector<double> vec);
		Indiv();
        
        double getFitness();
		

		void setVect(vector<double> vec);
		void setVectSigma(vector<double> sigma);
		void setVectSigmaEE(vector<double> vec, vector<double> sigma);

		vector<double> getVect();
		vector<double> getVectSigma();

		/////SWARM
		double distancia;

   		void guarda();
		~Indiv();

};

#endif