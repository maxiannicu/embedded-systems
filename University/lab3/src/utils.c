/*
 * utils.c
 *
 * Created: 10/5/2016 8:57:45 AM
 *  Author: Maxian Nicu
 */ 

#include "utils.h"

float ConvertValueFromToRange(float val,float minFromRange,float maxFromRange,float minToRange,float maxToRange){
	return (val - minFromRange) * (maxToRange - minToRange) / (maxFromRange - minFromRange) + minToRange;
}