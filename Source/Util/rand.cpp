#include "rand.h"

int random::num(int low, int high)	//Call this method f
{
    if ( low > high ) low = high - 1;

	return rand() % (high - low + 1) + low;
}
