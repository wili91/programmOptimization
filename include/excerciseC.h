
#include "constants.h"

template<std::size_t N, typename T>
void simple_Insertionsort(std::array<T, N>& arr)
{
	T sortingValue;


	for(std::size_t i = 1; i< arr.size(); i++){
		sortingValue = arr[i];

		for ( size_t j = i; j >0 && arr[j-1] > sortingValue; j--)
		{
			arr[j] = arr[j-1];
			arr[j-1]= sortingValue;

		}
	}
}

template<std::size_t N, typename T>
void prefetch_Insertionsort(std::array<T, N>& arr)
{
	T sortingValue;
	std::size_t outer_step = CACHE_LINE_BYTES / sizeof(T);

	for(std::size_t i = 1; i< arr.size(); i++){
		sortingValue = arr[i];

		for ( size_t j = i; (j-outer_step) >=0 && arr[j-1] > sortingValue; j-=outer_step)
		{
			for ( size_t k = j; k >0 && arr[k-1] > sortingValue; k--){
				arr[k] = arr[k-1];
				arr[k-1]= sortingValue;
			}
		}
	}
}
