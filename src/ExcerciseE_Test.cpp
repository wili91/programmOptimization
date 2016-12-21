/*
 * ExcerciseE_Test.cpp
 *
 *  Created on: Dec 21, 2016
 *      Author: lisa
 */


#include "gtest/gtest.h"
#include "../include/exerciseE.h"

class ExcerciseE: public ::testing::Test {

};

TEST(QuickSort_3Partition, int) {
	//because unique ptr may be buggy in reclaiming ressouces
	std::array<int, 8> array ={9,7,6,6,7,1,4,5};

	three_way_partition_sort(array, 0, array.size());

	EXPECT_EQ(1 , array[0]);
	EXPECT_EQ(4 , array[1]);
	EXPECT_EQ(5 , array[2]);
	EXPECT_EQ(6 , array[3]);
	EXPECT_EQ(6 , array[4]);
	EXPECT_EQ(7 , array[5]);
	EXPECT_EQ(7 , array[6]);
	EXPECT_EQ(9 , array[7]);
}

TEST(QuickSort_3Partition, int_desc) {
	std::shared_ptr<std::array<double, 800>> array(new std::array<double, 800>);

	genrate_array_desc(*array);

	three_way_partition_sort(*array, 0, array->size());

	double compare = 1.0;
	for (std::size_t i = 0; i < array->size(); i++) {
		EXPECT_EQ(compare , (*array)[i]);
		compare++;
	}
}
