///////*
////// * ExcerciseE_Test.cpp
////// *
////// *  Created on: Dec 21, 2016
////// *      Author: lisa
////// */
//////
//////
#include "gtest/gtest.h"
#include "../include/exerciseE.h"

template<typename T, size_t N>
void checkSortedQuickSort(std::array<T, N>& array) {

	if (array.size() >= 1) {
		for (size_t i = 1; i < N; i++) {
			EXPECT_TRUE(array[i - 1] <= array[i]);
		}
	}
}
class ExcerciseE: public ::testing::Test {

};

TEST(QuickSort_3Partition, integer) {
	std::array<int, 0> array0;
	three_way_partition_sort(array0);
	checkSorted(array0);

	std::array<int, 1> array = { 1 };
	three_way_partition_sort(array);
	checkSorted(array);

	std::array<int, 10> array1 = { 9, 7, 6, 6, 7, 1, 4, 4, 2, 1 };
	three_way_partition_sort(array1);
	checkSorted(array1);

	std::array<int, 8> array2 = { 9, 7, 6, 6, 7, 1, 4, 4 };
	three_way_partition_sort(array2);
	checkSorted(array2);
}

TEST(QuickSort_3Partition, double) {
	//because unique ptr may be buggy in reclaiming ressouces
	std::shared_ptr<std::array<double, 8>> array(new std::array<double, 8>);

	genrate_array_desc(*array);

	three_way_partition_sort((*array));
	checkSorted(*array);
}

TEST(QuickSort_3Partition, double_no_power2) {

	std::array<double, 0> array0;
	three_way_partition_sort(array0);
	checkSorted(array0);

	std::array<double, 1> array = { 1.9 };
	three_way_partition_sort(array);
	checkSorted(array);

	std::array<double, 8> array1 = { 9.5, 7.1, 6.9, 6.4, 7.9, 1., 4., 4. };
	three_way_partition_sort(array1);
	;
	checkSorted(array1);

	std::array<double, 10> array2 = { 9.5, 7.1, 6.9, 6.4, 7.9, 1., 4., 4., 2.6,
			1.1 };
	three_way_partition_sort(array2);
	checkSorted(array2);

}

TEST(QuickSort_3Partition, String) {

	std::shared_ptr<std::array<std::string, 1>> arr1(
			new std::array<std::string, 1> { { "" } });
	three_way_partition_sort((*arr1));
	checkSorted(*arr1);

	std::shared_ptr<std::array<std::string, 2>> arr2(
			new std::array<std::string, 2> { { "", "a" } });
	three_way_partition_sort((*arr2));
	checkSorted(*arr2);

	std::shared_ptr<std::array<std::string, 7>> arr3(
			new std::array<std::string, 7> { { "Äpfel ", "und ", " Birnen ",
					"und", " Bananen ", "sind ", "gesund." } });
	three_way_partition_sort((*arr3));
	checkSorted(*arr3);

	std::shared_ptr<std::array<std::string, 7>> arr4(
			new std::array<std::string, 7> { { "aaa ", "bb ", " a ", "", "cc",
					"abc", "xyz" } });
	three_way_partition_sort((*arr4));
	checkSorted(*arr4);

	std::shared_ptr<std::array<std::string, 3>> arr5(
			new std::array<std::string, 3> { { "Hallo ", "Welt ", "!" } });
	three_way_partition_sort((*arr5));
	checkSorted(*arr5);

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST(Hyprid_QuickSort_3Partition, integer) {
	std::array<int, 0> array0;
	hybrid_sort(array0, 0, array0.size());
	checkSorted(array0);

	std::array<int, 1> array = { 1 };
	hybrid_sort(array, 0, array.size());
	checkSortedQuickSort(array);

	std::array<int, 10> array1 = { 9, 7, 6, 6, 7, 1, 4, 4, 2, 1 };
	hybrid_sort(array1, 0, array1.size());
	checkSortedQuickSort(array1);

	std::array<int, 8> array2 = { 9, 7, 6, 6, 7, 1, 4, 4 };
	hybrid_sort(array2, 0, array2.size());
	checkSortedQuickSort(array2);
}

TEST(Hyprid_QuickSort_3Partition, double) {
	//because unique ptr may be buggy in reclaiming ressouces
	std::shared_ptr<std::array<double, 8>> array(new std::array<double, 8>);

	genrate_array_desc(*array);
	hybrid_sort((*array), 0, array->size());
	checkSorted(*array);
}

TEST(Hyprid_QuickSort_3Partition, double_no_power2) {

	std::array<double, 0> array0;
	hybrid_sort(array0, 0, array0.size());
	checkSorted(array0);

	std::array<double, 1> array = { 1.9 };
	hybrid_sort(array, 0, array.size());
	checkSorted(array);

	std::array<double, 8> array1 = { 9.5, 7.1, 6.9, 6.4, 7.9, 1., 4., 4. };
	hybrid_sort(array1, 0, array1.size());;
	checkSorted(array1);

	std::array<double, 10> array2 = { 9.5, 7.1, 6.9, 6.4, 7.9, 1., 4., 4., 2.6,
			1.1 };
	hybrid_sort(array2, 0, array2.size());
	checkSorted(array2);

}

TEST(Hyprid_QuickSort_3Partition, String) {

	std::shared_ptr<std::array<std::string, 1>> arr(
			new std::array<std::string, 1> { { "aaa" } });
	hybrid_sort((*arr), 0, arr->size());
	checkSorted(*arr);

	std::shared_ptr<std::array<std::string, 1>> arr1(
			new std::array<std::string, 1> { { "" } });
	hybrid_sort((*arr1), 0, arr1->size());
	checkSorted(*arr1);

	std::shared_ptr<std::array<std::string, 2>> arr2(
			new std::array<std::string, 2> { { "", "a" } });
	hybrid_sort((*arr2), 0, arr2->size());
	checkSorted(*arr2);

	std::shared_ptr<std::array<std::string, 7>> arr3(
			new std::array<std::string, 7> { { "Äpfel ", "und ", " Birnen ",
					"und", " Bananen ", "sind ", "gesund." } });
	hybrid_sort((*arr3), 0, arr3->size());
	checkSorted(*arr3);

	std::shared_ptr<std::array<std::string, 7>> arr4(
			new std::array<std::string, 7> { { "aaa ", "bb ", " a ", "", "cc",
					"abc", "xyz" } });
	hybrid_sort((*arr4), 0, arr4->size());
	checkSorted(*arr4);

	std::shared_ptr<std::array<std::string, 3>> arr5(
			new std::array<std::string, 3> { { "Hallo ", "Welt ", "!" } });
	hybrid_sort((*arr5), 0, arr5->size());
	checkSorted(*arr5);

}

