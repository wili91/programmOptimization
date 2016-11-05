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
void genrate_array(std::array<T, N>& test_arr){
	//generate the array
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<T> dist_int( 0.0,500.0);

	for(std::size_t i = 0; i< test_arr.size() ; i++)
	{
		test_arr[i] = dist_int(mt);
	}
}

template<std::size_t N, typename T>
void genrate_and_measure(T (*pFunc)(std::array<T, N>&, std::size_t), std::array<T,N> test_arr)
{
	std::array<int, L1_CACHE_SIZE_INT > cache_flush_arr;

	//flush the Cache
	for(std::size_t i = 0; i < cache_flush_arr.size(); i++) {
		cache_flush_arr[i] = std::numeric_limits<int>::max();
	}

	std::size_t index = test_arr.size();
	T output;
	while(index > 2)
	{
		//flush
		//flush the Cache
		for(std::size_t i = 0; i < cache_flush_arr.size(); i++) {
			cache_flush_arr[i] = std::numeric_limits<int>::max();
		}

		auto start_time = std::chrono::high_resolution_clock::now();
		output = pFunc(test_arr, index);
		auto end_time = std::chrono::high_resolution_clock::now();

		std::cout << "Minimum: "<< output << "    Time: " <<  std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count()<<std::endl;


		index = index/2;
	}

	//genrate_and_measure<N/2, T>();

}



template<std::size_t N, typename T>
T dumb_minimum(std::array<T,N>& arr, std::size_t index)
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

	for(std::size_t i = start_index; i< end_index; i++){
		if(arr[min_index] > arr[i])
		{
			min_index = i;
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
