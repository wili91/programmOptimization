#include "constants.h"

template<std::size_t N, typename T>
void simple_Insertionsort(std::array<T, N>& arr) {

	for (std::size_t i = 1; i < arr.size(); i++) {

		for (size_t j = i; j > 0 && arr[j - 1] > arr[j]; j--) {

			std::swap(arr[(j - 1)], arr[j]);

		}
	}
}

template<std::size_t N, typename T>
void prefetch_Insertionsort(std::array<T, N>& arr, std::size_t start, std::size_t end) {

	const std::size_t OUTER_STEP = CACHE_LINE_BYTES / sizeof(T);
	for (std::size_t i = start+1; i < end; i++) {

		std::size_t id = i;
		for (; arr[(id - 1)] > arr[id] && id >start;) {
			__builtin_prefetch(&arr[id - (2 * OUTER_STEP)]);


			for (size_t k = OUTER_STEP;
					arr[(id - 1)] > arr[id] && id > start && k > 0; k--, id--) {
				std::swap(arr[(id - 1)], arr[id]);

			}
		}
	}
}

template<std::size_t N, typename T>
void prefetch_Insertionsort_Wrapper(std::array<T, N>& arr) {
	prefetch_Insertionsort(arr, 0, arr.size());
}
