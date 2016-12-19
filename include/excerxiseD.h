#include "constants.h"

template<std::size_t N, typename T>
void normal_merge(std::array<T, N>& arr1, std::array<T, N>& help,
		std::size_t length) {
	//run indexes
	std::size_t left, mid, right;

	for (std::size_t merge_index = 0; merge_index < arr1.size();
			merge_index = merge_index + 2 * length) {
		std::cout << "" << std::endl;

		//define the starting index, middel index and right index of current runs
		left = merge_index;
		mid = std::min(arr1.size(), merge_index + length);
		right = std::min(arr1.size(), merge_index + 2 * length);

		std::size_t left_Runitr = left;
		std::size_t right_Runitr = mid;

		for (std::size_t iter = left; iter < right; iter++) {

			if (left_Runitr < mid
					&& (right_Runitr >= right
							|| arr1[right_Runitr] >= arr1[left_Runitr])) {
				help[iter] = arr1[left_Runitr];
				left_Runitr++;
			} else {
				help[iter] = arr1[right_Runitr];
				right_Runitr++;
			}
			std::cout << help[iter] << ",";
		}
		std::cout << "||";
	}
}

template<std::size_t N, typename T>
void bitonic_merge(std::array<T, N>& arr1, std::array<T, N>& help,
		std::size_t length) {
	std::size_t left, mid, right;
	std::size_t left_Runitr, right_Runitr;

	for (std::size_t merge_index = 0; merge_index < arr1.size();
			merge_index = merge_index + 2 * length) {

		//define the starting index, middel index and right index of current runs
		left = merge_index;
		mid = std::min(arr1.size(), merge_index + length);
		right = (std::min(arr1.size(), merge_index + 2 * length))-1;

		//copy right side
		for (std::size_t itr = left; itr < mid; itr++) {
			help[itr] = arr1[itr];

		}

		//copy left side
		right_Runitr = right;
		for (std::size_t itr = mid; right_Runitr >= mid; itr++) {
			help[itr] = arr1[right_Runitr--];
		}

		left_Runitr = left;
		right_Runitr = right;

		size_t i = merge_index;
		while (left_Runitr <= right_Runitr) {

			if (help[left_Runitr] <= help[right_Runitr]) {
				arr1[i]=help[left_Runitr];
				left_Runitr++;
			} else {
				arr1[i]=help[right_Runitr];
				right_Runitr--;
			}
			i++;
		}

	}



}

template<std::size_t N, typename T>
void bottomUpMergeSort(std::array<T, N>& arr) {

	//help array
	std::shared_ptr<std::array<T, N> > help_array(new std::array<T, N>);

	const size_t HALF = arr.size() / 2;
	for (std::size_t length = 1; length <= HALF; length = 2 * length) {

		//Merge the current runs
		bitonic_merge(arr, (*help_array), length);
	}

}

