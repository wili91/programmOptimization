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


TEST(MergeTest, specialCase) {
    std::shared_ptr<std::array<int, 0>> tmp0(new std::array<int, 0>());
    std::shared_ptr<std::array<int, 1>> tmp1(new std::array<int, 1>());
    std::shared_ptr<std::array<int, 2>> tmp2(new std::array<int, 2>());
    std::shared_ptr<std::array<int, 3>> tmp3(new std::array<int, 3>());

    std::shared_ptr<std::array<int, 0>> array_empty(new std::array<int, 0>);
    bitonic_merge(*array_empty, *tmp0, 0, 0, array_empty->size());
    checkSorted(*array_empty);

    std::shared_ptr<std::array<int, 1>> array_one(new std::array<int, 1>{8});
    bitonic_merge(*array_one, *tmp1, 0, 1, array_one->size());
    checkSorted(*array_one);

    std::shared_ptr<std::array<int, 2>> array_two0(new std::array<int, 2>{4,5});
    bitonic_merge(*array_two0, *tmp2, 0, 2, array_two0->size());
    checkSorted(*array_two0);

    std::shared_ptr<std::array<int, 2>> array_two1(new std::array<int, 2>{9,4});
    bitonic_merge(*array_two1, *tmp2, 0, 2, array_two1->size());
    checkSorted(*array_two1);

    std::shared_ptr<std::array<int, 3>> array_three(new std::array<int, 3>{9,4,6});
    //first run
    bitonic_merge(*array_three, *tmp3, 0, 1, array_three->size());
    bitonic_merge(*array_three, *tmp3, 2, 1, array_three->size());
    //second run
    bitonic_merge(*array_three, *tmp3, 0, 2, array_three->size());
    checkSorted(*array_three);

    std::shared_ptr<std::array<int, 3>> array_three1(new std::array<int, 3>{5,7,10});
    //first run
    bitonic_merge(*array_three1, *tmp3, 0, 1, array_three1->size());
    bitonic_merge(*array_three1, *tmp3, 2, 1, array_three1->size());
    //second run
    bitonic_merge(*array_three1, *tmp3, 0, 2, array_three1->size());
    checkSorted(*array_three1);
}

//TEST(BottomUpMergeSort, integer) {
//	std::array<int, 8> array2 = { 9, 7, 6, 6, 7, 1, 4, 4 };
//
//	for (std::size_t i = 0; i < array2.size(); i++) {
//
//		std::cout << array2[i] << ",";
//
//	}
//	std::cout << std::endl;
//
//
//	bottomUpMergeSort(array2);
//
//	for (std::size_t i = 0; i < array2.size(); i++) {
//
//		std::cout << array2[i] << ",";
//
//	}
//	std::cout << std::endl;
//
//	EXPECT_EQ(1, array2[0]);
//	EXPECT_EQ(4, array2[1]);
//	EXPECT_EQ(4, array2[2]);
//	EXPECT_EQ(6, array2[3]);
//	EXPECT_EQ(6, array2[4]);
//	EXPECT_EQ(7, array2[5]);
//	EXPECT_EQ(7, array2[6]);
//	EXPECT_EQ(9, array2[7]);
//}
//
//TEST(BottomUpMergeSort, double) {
//	//because unique ptr may be buggy in reclaiming ressouces
//	std::shared_ptr<std::array<double, 8>> array(new std::array<double, 8>);
//
//	genrate_array_desc(*array);
//
//	bottomUpMergeSort(*array);
//	for (std::size_t i = 0; i < array->size(); i++) {
//
//		std::cout << (*array)[i] << ",";
//
//	}
//	std::cout << std::endl;
//
//	double compare = 1.0;
//	for (std::size_t i = 0; i < array->size(); i++) {
//		EXPECT_EQ(compare, (*array)[i]);
//		compare++;
//	}
//}
//
//TEST(BottomUpMergeSort, double_no_power2) {
//
//	std::array<int, 10> array2 = { 9, 7, 6, 6, 7, 1, 4, 4, 2, 1 };
//
//
//	for (std::size_t i = 0; i < array2.size(); i++) {
//
//	std::cout<< array2[i]<<",";
//
//	}
//
//	std::cout<<std::endl;
//	bottomUpMergeSort(array2);
//
//	for (std::size_t i = 0; i < array2.size(); i++) {
//
//	std::cout<< array2[i]<<",";
//
//	}
//	std::cout<<std::endl;
//
//	EXPECT_EQ(1, array2[0]);
//	EXPECT_EQ(1, array2[1]);
//	EXPECT_EQ(2, array2[2]);
//	EXPECT_EQ(4, array2[3]);
//	EXPECT_EQ(4, array2[4]);
//	EXPECT_EQ(6, array2[5]);
//	EXPECT_EQ(6, array2[6]);
//	EXPECT_EQ(7, array2[7]);
//	EXPECT_EQ(7, array2[8]);
//	EXPECT_EQ(9, array2[9]);
//
//}



