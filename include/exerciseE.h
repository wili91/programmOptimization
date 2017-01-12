#include "constants.h"
#include "excerciseA.h"
#include "excerciseC.h"
#include "excerxiseD.h"

template<std::size_t N, typename T>
void quick_sort_3way(std::array<T, N>& array, size_t left, size_t right) {

	if (right < 1 && right <= left) {
		return;
	}
	size_t i = left - 1, j = right;
	size_t p = left, q = right - 1;

	// get the pivot element to the right side
	std::swap(array[(left + right) / 2], array[right]);
	T pivot = array[right];

	if (right <= left)
		return;
	for (;;) {
		//until value of i is equal or greater to pivot
		while (array[++i] < pivot)
			;
		//until value of j is greater or equal to pivot or j is at the size of left
		while (pivot < array[--j]) {
			if (j == left) {
				break;
			}
		}
		//break  endless loop if i and j cross
		if (i >= j)
			break;
		// swap so lesser and greater values are at the correct position
		std::swap(array[i], array[j]);

		//  move if volue of i equal to pivot
		if (array[i] == pivot) {
			std::swap(array[p], array[i]);
			p++;
		}
		//  move if volue of j equal to pivot
		if (pivot == array[j]) {
			std::swap(array[j], array[q]);
			q--;
		}
	}

	// bring the pivot from right to middle of array
	std::swap(array[i], array[right]);

	//fix runners
	j = (i == 0) ? 0 : (i - 1);
	i = i + 1;

	// swap equals to pivot to center
	for (size_t k = left; k < p; k++) {
		std::swap(array[k], array[j]);
		if (j > 0)
			j--;
	}

	for (size_t k = right - 1; k > q; i++, k--) {
		std::swap(array[i], array[k]);
	}

	quick_sort_3way(array, left, j);
	quick_sort_3way(array, i, right);

}

template<std::size_t N, typename T>
void three_way_partition_sort(std::array<T, N>& array) {
	if (N > 1) {
		quick_sort_3way(array, 0, N - 1);
	}
}

template<std::size_t N, typename T>
void hybrid_partition_sort(std::array<T, N>& array, size_t left, size_t right) {

	if (right < 1 && right <= left) {
		return;
	}

	if ((right - left) <= SORTING_THRESGHOLD) {
		std::cout<<"insertion Sort"<< std::endl;
		prefetch_Insertionsort(array, left, right+1);
	} else {
		std::cout<<"partitioning"<< std::endl;
		size_t i = left - 1, j = right;
		size_t p = left, q = right - 1;

		// get the pivot element to the right side
		std::swap(array[(left + right) / 2], array[right]);
		T pivot = array[right];

		if (right <= left)
			return;
		for (;;) {
			//until value of i is equal or greater to pivot
			while (array[++i] < pivot)
				;
			//until value of j is greater or equal to pivot or j is at the size of left
			while (pivot < array[--j]) {
				if (j == left) {
					break;
				}
			}
			//break  endless loop if i and j cross
			if (i >= j)
				break;
			// swap so lesser and greater values are at the correct position
			std::swap(array[i], array[j]);

			//  move if volue of i equal to pivot
			if (array[i] == pivot) {
				std::swap(array[p], array[i]);
				p++;
			}
			//  move if volue of j equal to pivot
			if (pivot == array[j]) {
				std::swap(array[j], array[q]);
				q--;
			}
		}

		// bring the pivot from right to middle of array
		std::swap(array[i], array[right]);

		//fix runners
		j = (i == 0) ? 0 : (i - 1);
		i = i + 1;

		// swap equals to pivot to center
		for (size_t k = left; k < p; k++) {
			std::swap(array[k], array[j]);
			if (j > 0)
				j--;
		}

		for (size_t k = right - 1; k > q; i++, k--) {
			std::swap(array[i], array[k]);
		}

		if(((j - left) < (WORST_CASE_QS * (right - i))) || (((j - left) * WORST_CASE_QS < (right -i)))) {
			std::cout<<"worst: right-left "<<(right -left) << " mid " << (left + right) / 2<< std::endl;
			std::cout<<"NOT merged: ++";
			for(size_t l = left; l < right; l++ ) {
				std::cout<<array[l] <<",";
			}
			std::cout<<"++"<<std::endl;

			size_t mid = (left + right) / 2;
			hybrid_partition_sort(array, left, mid);
			std::cout<<"first half: |";
			for(size_t l = left; l <= mid; l++ ) {
				std::cout<<array[l]<<",";
			}
			std::cout<<"|"<<std::endl;

			hybrid_partition_sort(array, mid+1, right);
			std::cout<<"second half: |";
			for(size_t l = mid+1; l < right; l++ ) {
				std::cout<<array[l]<<",";
			}
			std::cout<<"|"<<std::endl;
//			bitonic_merge(arr, (*help_array), merge_index, length, arr.size());

			std::cout<<"last element mid: "<< array[mid]<< " mid " << mid<<std::endl;
			std::cout<<"BEFORE merged: --";
			for(size_t l = left; l < right; l++ ) {
				std::cout<<array[l]<<",";
			}
			std::cout<<"--"<<std::endl;
			std::shared_ptr<std::array<T, N> > help_array(new std::array<T, N>);
			bitonic_merge(array, *help_array, left, mid+1, right+1);

			std::cout<<"merged: ||";
			for(size_t l = left; l < right; l++ ) {
				std::cout<<array[l]<<",";
			}
			std::cout<<"||"<<std::endl;

		} else {
			hybrid_partition_sort(array, left, j);
			hybrid_partition_sort(array, i, right);
		}
	}

}

template<std::size_t N, typename T>
void start_hybrid_sort(std::array<T, N>& array) {
	if (N > 1) {
		hybrid_partition_sort(array, 0, N - 1);
	}
}
