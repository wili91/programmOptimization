/*
 * excerciseB.h
 *
 *  Created on: Nov 6, 2016
 *      Author: lisa
 */

#ifndef EXCERCISEB_H_
#define EXCERCISEB_H_

#include "constants.h"
#include <utility>

template<std::size_t N, typename T>
void selection_Sort(std::array<T,N>& arr,
					T (*pFunc)(std::array<T, N>&, std::size_t, std::size_t))
{
	for(std::size_t index =0; index < arr.size(); index++)
	{
		std::swap(arr[index], arr[pFunc(arr, index, arr.size())]);
	}
}



#endif /* EXCERCISEB_H_ */
