/*
 * excerciseAandB.h
 *
 *  Created on: Oct 18, 2016
 *      Author: lisa
 */

#ifndef EXCERCISEAANDB_H_
#define EXCERCISEAANDB_H_
#include <array>
#include <limits>
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <random>
#include <chrono>

//constants 64 Bytes Cache Line (16 int)
extern const std::size_t  	CACHE_LINE_BYTES = 64;
//4096 Byte Cache Size
extern const std::size_t 	L1_CACHE_SIZE_INT = 1024;


template<std::size_t N, typename T>
T plain_minimum(std::array<T,N>& arr, std::size_t index)
{
	T min = arr[0];

	for(std::size_t i = 0; i< index ; i++){
		if(min > arr[i])
		{
			min = arr[i];
		}
	}
	return min;
}

template<std::size_t N, typename T>
T minimum_index(std::array<T,N>& arr, std::size_t start_index,std::size_t end_index)
{

	std::size_t min_index = start_index;

	//outer loops step is once the count of what a cache line may contain
	std::size_t outer_step= CACHE_LINE_BYTES/sizeof(T);
	//inner loops step has to be one

	for(std::size_t i = 0; i< end_index; i+=outer_step){
		__builtin_prefetch(&arr[i+outer_step+1]);
		for(std::size_t j = 0; j< outer_step && (i+j) < end_index; j++){
			if(arr[min_index] > arr[i+j])
			{
				min_index = i+j;
			}
		}
	}

	return min_index;
}
template<std::size_t N, typename T>
T minimum_two_loops(std::array<T,N>& arr, std::size_t index)
{
	T min = arr[0];

	//outer loops step is once the count of what a cache line may contain
	std::size_t outer_step= CACHE_LINE_BYTES/sizeof(T);
	//inner loops step has to be one

	for(std::size_t i = 0; i< index; i+=outer_step){
		for(std::size_t j = 0; j< outer_step && (i+j) < index; j++){
			if(min > arr[i+j])
			{
				min = arr[i+j];
			}
		}
	}
	return min;
}

template<std::size_t N, typename T>
T minimum_prefetch(std::array<T,N>& arr, std::size_t index)
{
	T min = arr[0];

	//outer loops step is once the count of what a cache line may contain
	std::size_t outer_step= CACHE_LINE_BYTES/sizeof(T);
	//inner loops step has to be one

	for(std::size_t i = 0; i< index; i+=outer_step){
		__builtin_prefetch(&arr[i+outer_step+1]);
		for(std::size_t j = 0; j< outer_step && (i+j) < index; j++){
			if(min > arr[i+j])
			{
				min = arr[i+j];
			}
		}
	}
	return min;
}




#endif /* EXCERCISEAANDB_H_ */
