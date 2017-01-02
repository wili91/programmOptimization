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

TEST(BottomUpMergeSort, double) {
	//because unique ptr may be buggy in reclaiming ressouces
	std::shared_ptr<std::array<double, 8>> array(new std::array<double, 8>);

	genrate_array_desc(*array);

	bottomUpMergeSort(*array);

	double compare = 1.0;
	for (std::size_t i = 0; i < array->size(); i++) {
		EXPECT_EQ(compare , (*array)[i]);
		compare++;
	}

	std::array<int, 8> array2 ={9,7,6,6,7,1,4,4,};

	bottomUpMergeSort(array2);

//	for (std::size_t i = 0; i < array2.size(); i++) {
//
//	std::cout<< array2[i]<<",";
//
//	}
//	std::cout<<std::endl;

	EXPECT_EQ(1 , array2[0]);
	EXPECT_EQ(4 , array2[1]);
	EXPECT_EQ(4 , array2[2]);
	EXPECT_EQ(6 , array2[3]);
	EXPECT_EQ(6 , array2[4]);
	EXPECT_EQ(7 , array2[5]);
	EXPECT_EQ(7 , array2[6]);
	EXPECT_EQ(9 , array2[7]);


}

TEST(BottomUpMergeSort, double_no_power2) {

	std::array<int, 10> array2 ={9,7,6,6,7,1,4,4,2,1};

	bottomUpMergeSort(array2);

//	for (std::size_t i = 0; i < array2.size(); i++) {
//
//	std::cout<< array2[i]<<",";
//
//	}
//	std::cout<<std::endl;

	EXPECT_EQ(1 , array2[0]);
	EXPECT_EQ(2 , array2[1]);
	EXPECT_EQ(3 , array2[2]);
	EXPECT_EQ(4 , array2[3]);
	EXPECT_EQ(4 , array2[4]);
	EXPECT_EQ(6 , array2[5]);
	EXPECT_EQ(6 , array2[6]);
	EXPECT_EQ(7 , array2[7]);
	EXPECT_EQ(7 , array2[8]);
	EXPECT_EQ(9 , array2[9]);


}

