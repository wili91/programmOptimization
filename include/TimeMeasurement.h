#include <array>
#include <limits>
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <random>

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
void time_measure(T (*pFunc)(std::array<T, N>&, std::size_t, std::size_t), std::array<T,N> test_arr)
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
		output = pFunc(test_arr, index, test_arr.size());
		auto end_time = std::chrono::high_resolution_clock::now();

		std::cout << "Minimum: "<< output << "    Time: " <<  std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count()<<std::endl;


		index = index/2;
	}

	//genrate_and_measure<N/2, T>();

}
