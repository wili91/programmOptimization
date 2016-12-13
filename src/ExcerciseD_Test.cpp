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
	std::shared_ptr<std::array<double, 400000000>> array(new std::array<double, 400000000>);

	genrate_array_desc(*array);
//	for (std::size_t i = 0; i < array->size(); i++) {
//
//		std::cout << (*array)[i] << "," << std::endl;
//
//	}

	bottomUpMergeSort(*array);
	double compare = 1.0;
	for (std::size_t i = 0; i < array->size(); i++) {

//		std::cout << (*array)[i] << "," << std::endl;
		EXPECT_EQ(compare , (*array)[i]);

		compare++;
	}

}

