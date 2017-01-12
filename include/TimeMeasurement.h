#include <iostream>
#include <string>
#include <stdio.h>
#include "constants.h"
#include <algorithm>
#include "excerciseB.h"
#include "exerciseE.h"

template<std::size_t N, typename T>
struct Measurement {

	void measure_time_sorting_all(std::array<T, N>& test_arr) {

		std::cout << std::endl << "######################## Number of Elements "
				<< N << " ###################" << std::endl;
		for (int sort = 0; sort < 8; sort++) {

			std::cout << std::endl << "-------------------------Measurement ";

			auto sFunc = chooseSorting(sort);

			std::cout << "------------------" << std::endl;


			std::cout <<  "N| rand | asc |desc  "<< std::endl;
			std::cout << "------------------" << std::endl;
			std::cout << N << ",";
			for (int type = 0; type < 3; type++) {
				generate_Array_type(type, test_arr);


				//stop quatratic running
				if ((sort < 5 && N < SIZE_N2) // anything bellow merge sort is n^2 so do not run forever
						|| (sort == 6 && type == 0) // do not run in worst Cases, ascending and descending
						|| (sort == 5)
						|| (sort == 7 && type == 2 && N < SIZE_N2)
						|| (sort == 7 && (type == 0 || type == 1)) // do not run in worst case
						|| (sort == 6 && type != 0 && N < SIZE_N2)) {

					flush_cache();

					auto start_time = std::chrono::high_resolution_clock::now();
					sFunc(test_arr);
					auto end_time = std::chrono::high_resolution_clock::now();

					std::cout << std::chrono::duration_cast<
									std::chrono::milliseconds>(
									end_time - start_time).count() << " , ";
				} else {
					std::cout << " nan ," ;
				}
			}
			std::cout <<  std::endl;
		}

		std::shared_ptr<std::array<T, N * 2>> next_array(
				new std::array<T, N * 2>);

		Measurement<N * 2, T> tm;
		tm.measure_time_sorting_all(*next_array);
	}

	auto chooseSorting(int sort) {
		switch (sort) {
		case 0:
			std::cout << "Selection Sort: ";
			return selection_Sort<N, T> ;
			break;
		case 1:
			std::cout << "Selection Sort Two Loops: ";
			return selection_Sort_Two_Loops<N, T> ;
			break;
		case 2:
			std::cout << "Selection Sort Prefetch: ";
			return selection_Sort_Prefetch<N, T> ;
			break;
		case 3:
			std::cout << "Simple InsertionSort: ";
			return simple_Insertionsort<N, T> ;
			break;
		case 4:
			std::cout << "Prefetch Insertion Sort: ";
			return prefetch_Insertionsort_Wrapper<N, T> ;
			break;
		case 5:
			std::cout << "Bottom Up Merge Sort:";
			return bottomUpMergeSort<N, T> ;
			break;
		case 6:
			std::cout << std::endl << "Three Way Partition Quick Sort: ";
			;
			return three_way_partition_sort<N, T> ;
			break;
		case 7:
			std::cout << std::endl << "Hybrid Sort: ";
			return start_hybrid_sort<N, T> ;
			break;
		default:
			std::cout << std::endl << "No such sorting function";
			exit(1);
		}
	}

	void generate_Array_type(int type, std::array<T, N>& test_arr) {
		switch (type) {
		case 0:
//			std::cout << "mit zufälligem Array:" << std::endl;
			genrate_array(test_arr);
			break;
		case 1:
//			std::cout << "mit aufsteigendem Array:" << std::endl;
			genrate_array_asc(test_arr);
			break;
		case 2:
//			std::cout << "mit absteigendem Array:" << std::endl;
			genrate_array_desc(test_arr);
			break;
		default:
			std::cout << std::endl << "No such generation function"
					<< std::endl;
			exit(1);
		}
	}

}
;

template<typename T>
struct Measurement<end_size, T> {
//	void measure_time_sorting(std::array<T, end_size>& test_arr, SORTING sort,
//			MINIMUM min) {
//
//	}

	void measure_time_sorting_all(std::array<T, end_size>& test_arr) {
		std::cout << " ############### Ende Time testing" << test_arr[0]
				<< "####################" << std::endl;
	}

};

