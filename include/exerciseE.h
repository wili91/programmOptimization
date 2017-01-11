#include "constants.h"
#include "excerciseA.h"
#include "excerciseC.h"
#include "excerxiseD.h"

///**
// * Create 3- Partions
// *
// * 1. Partition: All Elements smaller than the pivot Element [left,       i]
// * 2. Partition: All Elements equal to the pivot Element     [i+1   ,   j-1]
// * 3. Partition: All Elements greater than the pivot Element [  j   , right]
// *
// *  */
//template<std::size_t N, typename T>
//void partitioning(std::array<T, N>& array, size_t left, size_t right, size_t &i,
//		size_t &j) {
//
//	if (right <= left) {
//		return;
//	}
//	size_t lt = left;
//	size_t gt = right;
//	T p = array[left];
//	size_t k = left;
//	while (k <= gt) {
//		if (p > array[k]) {
//			std::swap(array[lt++], array[k++]);
//		} else if (p < array[k]) {
//			std::swap(array[k], array[gt--]);
//		} else {
//			k++;
//		}
//	}
//
//	i = (lt == 0) ? 0 : (lt - 1);
//	j = gt + 1;
//}

template<std::size_t N, typename T>
void quick_sort_3way(std::array<T, N>& array, size_t left, size_t right) {

	if (right <= left) {
		return;
	}
	size_t lt = left;
	size_t gt = right;
	T pivot = array[left];
	size_t ctr = left;
	while (ctr <= gt) {
		if (pivot > array[ctr]) {
			std::swap(array[lt++], array[ctr++]);
		} else if (pivot < array[ctr]) {
			std::swap(array[ctr], array[gt--]);
		} else {
			ctr++;
		}
	}

	quick_sort_3way(array, left, (lt == 0) ? 0 : (lt - 1));
	quick_sort_3way(array, gt + 1, right);

}

template<std::size_t N, typename T>
void three_way_partition_sort(std::array<T, N>& array) {
	if (N > 1) {
		quick_sort_3way(array, 0, N-1);
	}
}

template<std::size_t N, typename T>
void hybrid_partition_sort(std::array<T, N>& array, size_t left, size_t right) {

	if (right <= left) {
		return;
	}
	size_t lt = left;
	size_t gt = right;
	T pivot = array[left];
	size_t ctr = left;
	while (ctr <= gt) {
		if (pivot > array[ctr]) {
			std::swap(array[lt++], array[ctr++]);
		} else if (pivot < array[ctr]) {
			std::swap(array[ctr], array[gt--]);
		} else {
			ctr++;
		}
	}

	lt = (lt == 0) ? 0 : lt-1;

	if ((lt - left) < SORTING_THRESGHOLD) {
		prefetch_Insertionsort(array, left, lt+1);
	} else {
		hybrid_partition_sort(array, left, lt);
	}

	if ((right - (gt+1)) < SORTING_THRESGHOLD) {

		prefetch_Insertionsort(array, gt+1, right+1);
	} else {
		hybrid_partition_sort(array, gt+1, right);
	}
}
/**
 * Detects and handles Worst Case an uses Insetion Sort once partitions get to small
 *
 */
template<std::size_t N, typename T>
void hybrid_sort(std::array<T, N>& array, size_t left, size_t right) {
	if (right <= 1 && checkSortedAsc(array)) {
		//already sorted
		return;
	} else if (!checkSortedDesc(array)) {
		//not Worstcase
		hybrid_partition_sort(array, 0, N - 1);

	} else {


		size_t mid = N / 2;
		hybrid_partition_sort(array, 0, mid - 1);
		hybrid_partition_sort(array, mid, right - 1);

		//merge it
		std::shared_ptr<std::array<T, N> > help_array(new std::array<T, N>);
		bitonic_merge(array, *help_array, left, mid, right);
	}
}

template<std::size_t N, typename T>
void start_hybrid_sort(std::array<T, N>& array) {
	hybrid_sort(array, 0, N);
}
