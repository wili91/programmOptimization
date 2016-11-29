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
void prefetch_Insertionsort(std::array<T, N>& arr) {

	const std::size_t OUTER_STEP = CACHE_LINE_BYTES / sizeof(T);
	for (std::size_t i = 1; i < arr.size(); i++) {
		std::size_t j = (i >= (OUTER_STEP)) ? i : (OUTER_STEP);
		for (; arr[(i - 1)] > arr[i] && j >= (OUTER_STEP); j -= OUTER_STEP) {
			__builtin_prefetch(&arr[j - (2 * OUTER_STEP)]);

			size_t id = i;
			for (size_t k = OUTER_STEP;
					arr[(id - 1)] > arr[id] && k >= 0 && id > 0; k--, id--) {
				std::swap(arr[(id - 1)], arr[id]);

			}
		}
	}
}

