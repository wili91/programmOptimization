/*
 * arrayMethods.cpp
 *
 *  Created on: Nov 15, 2016
 *      Author: lisa
 */
#include "../include/arrayMethods.h"

void flush_cache() {
	std::shared_ptr<std::array<double, 1000000u>> flush_array(new std::array<double, 1000000u>);
	genrate_array(*flush_array);

	for(std::size_t i = 0 ; i < flush_array->size(); i++)
	{
		(*flush_array)[i]=(*flush_array)[i]+1;
	}
}


