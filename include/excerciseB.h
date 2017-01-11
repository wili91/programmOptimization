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
#include "excerciseA.h"

template<std::size_t N, typename T>
void selection_Sort(std::array<T, N>& arr) {

	for (std::size_t index = 0; index < arr.size(); index++) {
		std::size_t min = plain_minimum_index(arr, index, arr.size());
		std::swap(arr[index], arr[min]);
	}
}

template<std::size_t N, typename T>
void selection_Sort_Two_Loops(std::array<T, N>& arr) {

	for (std::size_t index = 0; index < arr.size(); index++) {
		std::size_t min = minimum_two_loops_index(arr, index, arr.size());
		std::swap(arr[index], arr[min]);
	}
}

template<std::size_t N, typename T>
void selection_Sort_Prefetch(std::array<T, N>& arr) {

	for (std::size_t index = 0; index < arr.size(); index++) {
		std::size_t min = prefetch_minimum_index(arr, index, arr.size());
		std::swap(arr[index], arr[min]);
	}
}

#endif /* EXCERCISEB_H_ */
