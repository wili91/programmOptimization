#include "constants.h"
#include "excerciseA.h"
#include "excerciseC.h"
#include "excerxiseD.h"

/**
 * Create 3- Partions
 *
 * 1. Partition: All Elements smaller than the pivot Element [left,       i]
 * 2. Partition: All Elements equal to the pivot Element     [i+1   ,   j-1]
 * 3. Partition: All Elements greater than the pivot Element [  j   , right]
 *
 *  */
template<std::size_t N, typename T>
void partitioning(std::array<T, N>& array, size_t left, size_t right, size_t &i,
		size_t &j) {

	std::size_t itr = left;

	T pivot = array[right - 1];

	//Lomuto partition scheme for three partitions
	while (itr < right) {
		if (array[itr] < pivot) {
			std::swap(array[itr++], array[left++]);
		} else if (array[itr] == pivot) {
			itr++; //no swapping needed is equal
		} else {
			std::swap(array[itr], array[right - 1]);
			right--;
		}
	}

	i = left;
	j = itr;
}

template<std::size_t N, typename T>
void three_way_partition_sort(std::array<T, N>& array, size_t left,
		size_t right) {

	//Check the bounds
	if (left < right && right > 1) {

		size_t i = 0;
		size_t j = 0;

		partitioning(array, left, right, i, j);

		three_way_partition_sort(array, left, i);
		three_way_partition_sort(array, j, right);
	}
}
/**
 * Detects and handles Worst Case an uses Insetion Sort once partitions get to small
 *
 */
template<std::size_t N, typename T>
void hybrid_partition_sort(std::array<T, N>& array, size_t left, size_t right) {
	std::cout <<"run size: " << (right - left)<< std::endl;
	if ((right - left) <= SORTING_THRESGHOLD) { // This works
		//sort via Insersion Sort when smaller than a certain threshhold
		//no more recursion
		prefetch_Insertionsort(array, left, right);
	} else {

		//Do normal Partitioning
		size_t i = 0;
		size_t j = 0;
		partitioning(array, left, right, i, j);

		/**
		 * Detect wort case for Quick sort
		 *
		 * Fist:   largest element  pivot
		 * Second: smalles element  pivot
		 */

		std::size_t mid = (left + right) / 2;
		if ((prefetch_maximum_index(array, left, mid) == array[mid - 1])
				|| (prefetch_maximum_index(array, mid + 1, right)	== array[right - 1])
				|| (prefetch_minimum_index(array, left, mid) 		== array[mid - 1])
				|| (prefetch_minimum_index(array, mid + 1, right) 	== array[right - 1])) {
		//detect worst case by
		//first:  pivot is smaller than 33% of the range
		//second: pivot is greater than 66% of the range
//		if () {
			//devide in half

			three_way_partition_sort(array, left, mid);
			three_way_partition_sort(array, mid + 1, right);
			//do single merge Step
			std::shared_ptr<std::array<T, N> > help_array(new std::array<T, N>);
			bitonic_merge(array, *help_array, (right-left));
		} else {
			//Do normal 3 way Partion
			three_way_partition_sort(array, left, i);
			three_way_partition_sort(array, j, right);
		}
	}
}

