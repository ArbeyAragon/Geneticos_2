#ifndef DE_H
#define DE_H

#include <vector>
#include <string>

#include "../Individuo/Indiv.h"

using namespace std;

class DE
{
    private:
        int iteraciones;
        long id;
        int Pobl;
        static const double Cr=0.5;
        static const double F=0.5;


    public:
        
        DE(int iter, int NPobl, long tid);
        void run();

		~DE();

};

#endif