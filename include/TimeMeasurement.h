#include <iostream>
#include <string>
#include <stdio.h>
#include "constants.h"
#include <algorithm>

template<std::size_t N, typename T>
struct Measurement {
	void measure_time_sorting(std::array<T, N>& test_arr, SORTING sort,
			MINIMUM min) {

		auto sFunc = chooseSorting(sort);
		auto mFunc = chooseMinimum(min);

		flush_cache();

		auto start_time = std::chrono::high_resolution_clock::now();
		sFunc(test_arr, mFunc);
		auto end_time = std::chrono::high_resolution_clock::now();

		std::cout
				<< std::chrono::duration_cast<std::chrono::milliseconds>(
						end_time - start_time).count() << "      ";

		std::shared_ptr<std::array<T, N * 2>> next_array(
				new std::array<T, N * 2>);

		Measurement<N * 2, T> tm;
		tm.measure_time_sorting(*next_array, sort, min);
	}

	void measure_time_sorting_all(std::array<T, N>& test_arr, ARRAYTYPE type,
			SORTING sort) {

		//to deep copy the test array
		std::shared_ptr<std::array<T, N>> work_array(
				new std::array<T, N>);
		generate_Array_type(type, test_arr);


		std::cout << N << ",";
		auto sFunc = chooseSorting(sort);

		for (int min = MINIMUM::plain_min; min <= MINIMUM::prefretch_min;
				min++) {
			(*work_array) = test_arr;
			flush_cache();
			auto mFunc = chooseMinimum(min);
			auto start_time = std::chrono::high_resolution_clock::now();
			sFunc(*work_array, mFunc);
			auto end_time = std::chrono::high_resolution_clock::now();

			std::cout
					<< std::chrono::duration_cast<std::chrono::milliseconds>(
							end_time - start_time).count() << ",";
		}
		std::cout << std::endl;

		std::shared_ptr<std::array<T, N * 2>> next_array(
				new std::array<T, N * 2>);

		Measurement<N * 2, T> tm;
		tm.measure_time_sorting_all(*next_array, type, sort);
	}

	auto chooseSorting(int sort) {
		switch (sort) {
		case 0:
			return selection_Sort<N, T> ;
			break;
		default:
			std::cout << std::endl << "No such sorting function" << std::endl;
			exit(1);
		}
	}

	auto chooseMinimum(int min) {
		switch (min) {
		case 0:
			return plain_minimum_index<N, T> ;
			break;
		case 1:
			return minimum_two_loops_index<N, T> ;
			break;
		case 2:
			return prefetch_minimum_index<N, T> ;
			break;
		default:
			std::cout << std::endl << "No such sorting function" << std::endl;
			exit(1);
		}
	}

	void generate_Array_type(int type, std::array<T, N>& test_arr) {
		switch (type) {
		case 0:
			genrate_array(test_arr);
			break;
		case 1:
			genrate_array_asc(test_arr) ;
			break;
		case 2:
			genrate_array_desc(test_arr)  ;
			break;
		default:
			std::cout << std::endl << "No such generation function" << std::endl;
			exit(1);
		}
	}

};

template<typename T>
struct Measurement<end_size, T> {
	void measure_time_sorting(std::array<T, end_size>& test_arr, SORTING sort,
			MINIMUM min) {

	}

	void measure_time_sorting_all(std::array<T, end_size>& test_arr,
			ARRAYTYPE type, SORTING sort) {
		std::cout<< "Ended," << test_arr[0]<<"," << type<<","  <<sort<<","  <<std::endl;
	}

};

