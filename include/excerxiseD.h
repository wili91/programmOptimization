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
		std::size_t merge_index, std::size_t length, std::size_t end) {

	//define the starting index, middle index and right index of current runs
	//	 <----length-->
	//	[              |          ]
	//  ^              ^          ^
	//  left          mid        right

	std::size_t left = merge_index;
	std::size_t mid = std::min(end, merge_index + length);
	std::size_t right = (std::min(end, merge_index + 2 * length));

	//copy right side( left -> mid ) to help
	for (std::size_t itr = left; itr < mid; itr++) {
		help[itr] = arr1[itr];

	}

	//copy left  side ( mid -> right) to help
	for (std::size_t itr = mid, r_itr = right; mid < r_itr; itr++) {
		help[itr] = arr1[--r_itr];

	}

	std::size_t left_Runitr = left;
	std::size_t right_Runitr = right;
	std::size_t write_id = merge_index;

	while (left_Runitr < right_Runitr) {

		if (help[left_Runitr] < help[--right_Runitr]) {
			arr1[write_id] = help[left_Runitr];
			left_Runitr++;
			right_Runitr++;
		} else {
			arr1[write_id] = help[right_Runitr];
		}
		//inkrement write index
		write_id++;
	}

}

template<std::size_t N, typename T>
void bottomUpMergeSort(std::array<T, N>& arr) {

	//help array
	std::shared_ptr<std::array<T, N> > help_array(new std::array<T, N>);

	for (std::size_t length = 1; length < arr.size(); length = 2 * length) {
		for (std::size_t merge_index = 0; merge_index < arr.size();
				merge_index += 2 * length) {
			//Merge the current runs
			bitonic_merge(arr, (*help_array), merge_index, length, arr.size());
		}
	}

}

