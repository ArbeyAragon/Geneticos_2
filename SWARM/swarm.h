#ifndef SWARM_H
#define SWARM_H

#include <vector>
#include <string>

#include "../Individuo/Indiv.h"

using namespace std;

class SWARM
{
    private:
        int iteraciones;
        long id;
        int Pobl;

    public:
        
        SWARM(int iter, int NPobl, long tid);
        void run();

		~SWARM();

};

#endif