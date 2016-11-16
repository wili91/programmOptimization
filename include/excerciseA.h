/*
 * excerciseAandB.h
 *
 *  Created on: Oct 18, 2016
 *      Author: lisa
 */

#ifndef EXCERCISEAANDB_H_
#define EXCERCISEAANDB_H_

#include "constants.h"

/**
 *  This method returns the minimum of any array, it has not optimization
 *
 */
template<std::size_t N, typename T>
T plain_minimum(std::array<T, N>& arr, std::size_t start_index,
		std::size_t end_index) {
	T min = arr[start_index];

	for (std::size_t i = start_index + 1; i < end_index; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	return min;
}

/**
 *  This method returns the index of the minimum of any array,
 *   it has not optimization
 */
template<std::size_t N, typename T>
T plain_minimum_index(std::array<T, N>& arr, std::size_t start_index,
		std::size_t end_index) {

	std::size_t min_index = start_index;

	for (std::size_t i = start_index; i < end_index; i++) {
		if (arr[min_index] > arr[i]) {
			min_index = i;
		}
	}
	return min_index;
}

/**
 *  This method returns the minimum of any array, it has no optimization but two loops
 *  fitting a cacheline.
 */
template<std::size_t N, typename T>
T minimum_two_loops(std::array<T, N>& arr, std::size_t start_index,
		std::size_t end_index) {
	T min = arr[start_index];

	//outer loops step is once the count of what a cache line may contain
	std::size_t outer_step = CACHE_LINE_BYTES / sizeof(T);
	//inner loops step has to be one

	for (std::size_t i = start_index; i < end_index; i += outer_step) {
		for (std::size_t j = 0; j < outer_step && (i + j) < end_index; j++) {
			if (min > arr[i + j]) {
				min = arr[i + j];
			}
		}
	}
	return min;
}

/**
 *  This method returns the index of the minimum of any array,
 *   it has two loops but is not really optimized
 */
template<std::size_t N, typename T>
T minimum_two_loops_index(std::array<T, N>& arr, std::size_t start_index,
		std::size_t end_index) {
	std::size_t min_index = start_index;

	//outer loops step is once the count of what a cache line may contain
	std::size_t outer_step = CACHE_LINE_BYTES / sizeof(T);
	//inner loops step has to be one

	for (std::size_t i = start_index; i < end_index; i += outer_step) {
		for (std::size_t j = 0; j < outer_step && (i + j) < end_index; j++) {
			if (arr[min_index] > arr[i + j]) {
				min_index = i + j;
			}
		}
	}
	return min_index;
}

/**
 *  This method returns the minimum of any array,
 *   it has two loops and does prefetching
 */
template<std::size_t N, typename T>
T minimum_prefetch(std::array<T, N>& arr, std::size_t start_index,
		std::size_t end_index) {
	T min = arr[start_index];

	//outer loops step is once the count of what a cache line may contain
	std::size_t outer_step = CACHE_LINE_BYTES / sizeof(T);
	//inner loops step has to be one

	for (std::size_t i = start_index; i < end_index; i += outer_step) {
		__builtin_prefetch(&arr[i + outer_step + 1]);
		for (std::size_t j = 0; j < outer_step && (i + j) < end_index; j++) {
			if (min > arr[i + j]) {
				min = arr[i + j];
			}
		}
	}
	return min;
}

/**
 *  This method returns the index of the minimum of any array,
 *   it has two loops and does prefetching
 */
template<std::size_t N, typename T>
T prefetch_minimum_index(std::array<T, N>& arr, std::size_t start_index,
		std::size_t end_index) {

	std::size_t min_index = start_index;

	//outer loops step is once the count of what a cache line may contain
	std::size_t outer_step = CACHE_LINE_BYTES / sizeof(T);
	//inner loops step has to be one

	for (std::size_t i = start_index; i < end_index; i += outer_step) {

		__builtin_prefetch(&arr[i + outer_step + 1]);

		for (std::size_t j = 0; j < outer_step && (i + j) < end_index; j++) {
			if (arr[min_index] > arr[i + j]) {
				min_index = i + j;
			}
		}
	}

	return min_index;
}

#endif /* EXCERCISEAANDB_H_ */
