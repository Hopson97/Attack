#include "rand.h"

namespace random
{

float
numf ( float low, float high)
{
    low     *= 100;
    high    *= 100;

    int l = low;
    int h = high;   //Because we need integers for operator %

    float n = rand() % (h - l + 1) + l;

    return n / 100.0f;
}

int
num(int low, int high)	//Call this method f
{
    if ( low > high ) low = high - 1;

	return rand() % (high - low + 1) + low;
}

}
