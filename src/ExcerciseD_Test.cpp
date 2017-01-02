/*
 * ExcerciseD_Test.cpp
 *
 *  Created on: Dec 8, 2016
 *      Author: lisa
 */

/*
 * ExcerciseC_Test.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: lisa
 */

#include "gtest/gtest.h"
#include "../include/excerxiseD.h"

class ExcerciseD: public ::testing::Test {

};

TEST(MergeTest, specialCases) {
	std::shared_ptr<std::array<int, 0>> tmp0(new std::array<int, 0>());
	std::shared_ptr<std::array<int, 1>> tmp1(new std::array<int, 1>());
	std::shared_ptr<std::array<int, 2>> tmp2(new std::array<int, 2>());
	std::shared_ptr<std::array<int, 3>> tmp3(new std::array<int, 3>());

	std::shared_ptr<std::array<int, 0>> array_empty(new std::array<int, 0>);
	bitonic_merge(*array_empty, *tmp0, 0, 0, array_empty->size());
	checkSorted(*array_empty);

	std::shared_ptr<std::array<int, 1>> array_one(new std::array<int, 1> { 8 });
	bitonic_merge(*array_one, *tmp1, 0, 1, array_one->size());
	checkSorted(*array_one);

	std::shared_ptr<std::array<int, 2>> array_two0(
			new std::array<int, 2> { 4, 5 });
	bitonic_merge(*array_two0, *tmp2, 0, 2, array_two0->size());
	checkSorted(*array_two0);

	std::shared_ptr<std::array<int, 2>> array_two1(
			new std::array<int, 2> { 9, 4 });
	bitonic_merge(*array_two1, *tmp2, 0, 2, array_two1->size());
	checkSorted(*array_two1);

	std::shared_ptr<std::array<int, 3>> array_three(new std::array<int, 3> { 9,
			4, 6 });
	//first run
	bitonic_merge(*array_three, *tmp3, 0, 1, array_three->size());
	bitonic_merge(*array_three, *tmp3, 2, 1, array_three->size());
	//second run
	bitonic_merge(*array_three, *tmp3, 0, 2, array_three->size());
	checkSorted(*array_three);

	std::shared_ptr<std::array<int, 3>> array_three1(new std::array<int, 3> { 5,
			7, 10 });
	//first run
	bitonic_merge(*array_three1, *tmp3, 0, 1, array_three1->size());
	bitonic_merge(*array_three1, *tmp3, 2, 1, array_three1->size());
	//second run
	bitonic_merge(*array_three1, *tmp3, 0, 2, array_three1->size());
	checkSorted(*array_three1);
}

TEST(MergeTest, oddCases) {
	std::shared_ptr<std::array<int, 10>> tmp0(new std::array<int, 10>());

	std::shared_ptr<std::array<int, 10>> array(new std::array<int, 10> { 1, 2,
			3, 4, 5, 6, 7, 8, 1, 2 });
	bitonic_merge(*array, *tmp0, 0, 8, array->size());
	checkSorted(*array);
}

TEST(MergeTest, String) {
	std::shared_ptr<std::array<std::string, 0>> tmp0(
			new std::array<std::string, 0>());
	std::shared_ptr<std::array<std::string, 1>> tmp1(
			new std::array<std::string, 1>());
	std::shared_ptr<std::array<std::string, 2>> tmp2(
			new std::array<std::string, 2>());
	std::shared_ptr<std::array<std::string, 3>> tmp3(
			new std::array<std::string, 3>());

	std::shared_ptr<std::array<std::string, 0>> array_empty(
			new std::array<std::string, 0>);
	bitonic_merge(*array_empty, *tmp0, 0, 0, array_empty->size());
	checkSorted(*array_empty);

	std::shared_ptr<std::array<std::string, 1>> array_one(
			new std::array<std::string, 1> { { "aaa" } });
	bitonic_merge(*array_one, *tmp1, 0, 1, array_one->size());
	checkSorted(*array_one);

	std::shared_ptr<std::array<std::string, 1>> array_empty_string(
			new std::array<std::string, 1> { { "" } });
	bitonic_merge(*array_empty_string, *tmp1, 0, 1, array_empty_string->size());
	checkSorted(*array_empty_string);

	std::shared_ptr<std::array<std::string, 2>> array_two0(
			new std::array<std::string, 2> { { "", "a" } });
	bitonic_merge(*array_two0, *tmp2, 0, 2, array_two0->size());
	checkSorted(*array_two0);

	std::shared_ptr<std::array<std::string, 2>> array_two1(
			new std::array<std::string, 2> { { "b", "a" } });
	bitonic_merge(*array_two1, *tmp2, 0, 2, array_two1->size());
	checkSorted(*array_two1);

	std::shared_ptr<std::array<std::string, 2>> array_two3(
			new std::array<std::string, 2> { { "abb", "ax3" } });
	bitonic_merge(*array_two3, *tmp2, 0, 2, array_two3->size());
	checkSorted(*array_two3);

	std::shared_ptr<std::array<std::string, 3>> array_three1(
			new std::array<std::string, 3> { { "abab", "ax3", "42" } });
	//first run
	bitonic_merge(*array_three1, *tmp3, 0, 1, array_three1->size());
	bitonic_merge(*array_three1, *tmp3, 2, 1, array_three1->size());
	//second run
	bitonic_merge(*array_three1, *tmp3, 0, 2, array_three1->size());
	checkSorted(*array_three1);
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

TEST(BottomUpMergeSort, integer) {
	std::array<int, 0> array0;
	bottomUpMergeSort(array0);
	checkSorted(array0);

	std::array<int, 1> array = { 1 };
	bottomUpMergeSort(array);
	checkSorted(array);

	std::array<int, 10> array1 = { 9, 7, 6, 6, 7, 1, 4, 4, 2, 1 };
	bottomUpMergeSort(array1);
	checkSorted(array1);

	std::array<int, 8> array2 = { 9, 7, 6, 6, 7, 1, 4, 4 };
	bottomUpMergeSort(array2);
	checkSorted(array2);
}

TEST(BottomUpMergeSort, double) {
	//because unique ptr may be buggy in reclaiming ressouces
	std::shared_ptr<std::array<double, 8>> array(new std::array<double, 8>);

	genrate_array_desc(*array);

	bottomUpMergeSort(*array);
	checkSorted(*array);
}

TEST(BottomUpMergeSort, double_no_power2) {

	std::array<double, 0> array0;
	bottomUpMergeSort(array0);
	checkSorted(array0);

	std::array<double, 1> array = { 1.9 };
	bottomUpMergeSort(array);
	checkSorted(array);

	std::array<double, 8> array1 = { 9.5, 7.1, 6.9, 6.4, 7.9, 1., 4., 4. };
	bottomUpMergeSort(array1);
	checkSorted(array1);
	std::array<double, 10> array2 = { 9.5, 7.1, 6.9, 6.4, 7.9, 1., 4., 4., 2.6,
			1.1 };
	bottomUpMergeSort(array2);
	checkSorted(array2);

}

TEST(BottomUpMergeSort, String) {

	std::shared_ptr<std::array<std::string, 1>> arr(
			new std::array<std::string, 1> { { "aaa" } });
	bottomUpMergeSort(*arr);
	checkSorted(*arr);

	std::shared_ptr<std::array<std::string, 1>> arr1(
			new std::array<std::string, 1> { { "" } });
	bottomUpMergeSort(*arr1);
	checkSorted(*arr1);

	std::shared_ptr<std::array<std::string, 2>> arr2(
			new std::array<std::string, 2> { { "", "a" } });
	bottomUpMergeSort(*arr2);
	checkSorted(*arr2);

	std::shared_ptr<std::array<std::string, 7>> arr3(
			new std::array<std::string, 7> { { "Äpfel ", "und ", " Birnen ",
					"und", " Bananen ", "sind ", "gesund." } });
	bottomUpMergeSort(*arr3);
	checkSorted(*arr3);

	std::shared_ptr<std::array<std::string, 7>> arr4(
			new std::array<std::string, 7> { { "aaa ", "bb ", " a ", "", "cc",
					"abc", "xyz" } });
	bottomUpMergeSort(*arr4);
	checkSorted(*arr4);

	std::shared_ptr<std::array<std::string, 3>> arr5(
			new std::array<std::string, 3> { { "Hallo ", "Welt ", "!" } });
	bottomUpMergeSort(*arr5);
	checkSorted(*arr5);

}
