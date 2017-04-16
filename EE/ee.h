#ifndef EE_H
#define EE_H

#include <vector>
#include <string>

#include "../Individuo/Indiv.h"

using namespace std;

class EE
{
    private:
        int iteraciones;
        long id;
        int Pobl;

    public:
        
        EE(int iter, int NPobl, long tid);
        void run();

		~EE();

};

#endif