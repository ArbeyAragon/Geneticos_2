#ifndef HC_H
#define HC_H

#include <vector>
#include <string>

#include "../Individuo/Indiv.h"

using namespace std;

class HC
{
    private:
        int iteraciones;
        long id;
        Indiv* SujMejor;

    public:
        
        HC(int iter, long tid);
        void run();

   		void save(string id);
		~HC();

};

#endif