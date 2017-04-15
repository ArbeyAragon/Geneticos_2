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
};
#endif