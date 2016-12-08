#include "constants.h"


template<std::size_t N, typename T>
void merge(std::array<T, N>& arr1, std::array<T, N>& help, std::size_t left,
		std::size_t mid, std::size_t right) {

	std::size_t left_Runitr = left;
	std::size_t right_Runitr = mid;
	for (std::size_t iter = left; iter < right; iter++) {
		if (left_Runitr < mid
				&& (right_Runitr >= right  || arr1[right_Runitr] >= arr1[left_Runitr])) {
			help[iter] = arr1[left_Runitr];
			left_Runitr++;
		} else {
			help[iter] = arr1[right_Runitr];
			right_Runitr++;
		}
	}
}
template<std::size_t N, typename T>
void bottomUpMergeSort(std::array<T, N>& arr) {

	//help array
	std::shared_ptr<std::array<T, N> > help_array(new std::array<T, N>);
	//run indexes
	std::size_t left, mid, right;

	for (std::size_t length = 1; length < arr.size(); length = 2 * length) {
		for (std::size_t merge_index = 0; merge_index < arr.size();
				merge_index = merge_index + 2 * length) {

			//define the starting index, middel index and right index of current runs
			left = merge_index;
			mid = std::min(arr.size(), merge_index + length);
			right = std::min(arr.size(), merge_index + 2 * length);

			//Merge the current runs
			merge(arr, (*help_array), left, mid, right);
		}

		//copy the array back
		arr = (*help_array);
	}
}


