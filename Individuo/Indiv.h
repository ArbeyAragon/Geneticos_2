#ifndef INDIV_H
#define INDIV_H

#include <vector>

using namespace std;

class Indiv
{
    private:
        vector<double> VecW;
        double fitness;
		double fitnessCalc();
    public:
        static const int len=100; 
		Indiv(vector<double> vec);
		Indiv();
        
        double getFitness();
		void setVec(vector<double> vec);
		vector<double> getVect();

   		void guarda();
		~Indiv();

};

#endif