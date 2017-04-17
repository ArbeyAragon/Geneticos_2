#ifndef VE_H
#define VE_H

#include <vector>

using namespace std;

class VectorExtras
{
    public:
        static void initRandom();
        static void printVec(vector<double> bin);
        static double randDouble(double min, double max);
        static vector<double> vectorDoubleRand(int len ,double min, double max);
        static double Sigmoid(double x);
        static double rand_normal(double mean, double stddev, double min, double max );
        static int randInt(int min, int max);

        ///////Geneticos
        static void MUTACION(vector<double> P1,vector<double> Ps1, vector<double> &H1);
        static void CRUCENormal(vector<double> P1,vector<double> P2,vector<double> &H1,vector<double> &H2);
        static void CRUCEMath(vector<double> P1,vector<double> P2,vector<double> &H1);

        ///////Geneticos DE
        static bool MutacionDE(double Cr, double F, vector<double> Pi, vector<double> P0, vector<double> P1, vector<double> P2, vector<double> &H1);

        ///////SWARM
        static void SWARMInercia(double a1, double a2, double a3, vector<double> suj, vector<double> v, vector<double> best, vector<double> localBest, vector<double> &sujN, vector<double> &vN);
        static double SWARMDistancia(vector<double> suj1, vector<double> suj2);
};
#endif