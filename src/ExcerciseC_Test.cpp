/*
 * ExcerciseC_Test.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: lisa
 */

#include "gtest/gtest.h"
#include "../include/excerciseC.h"

class ExcerciseC : public ::testing::Test{



};

TEST(InsertionSort, double){
	//because unique ptr may be buggy in reclaiming ressouces
	std::shared_ptr<std::array<double, 10>> array(
			new std::array<double, 10>);

	genrate_array_desc(*array);
	simple_Insertionsort(*array);
	double compare = 1.0;
	for (std::size_t i = 0; i < array->size(); i++) {

//		std::cout<<(*array)[i]<<","<<std::endl;
		EXPECT_EQ(compare , (*array)[i]);

		compare++;
	}

	std::shared_ptr<std::array<double, 10>> array2(
			new std::array<double, 10>);

	genrate_array_desc(*array2);
	prefetch_Insertionsort(*array2);
	compare = 1.0;
	for (std::size_t i = 0; i < array2->size(); i++) {

		std::cout<<(*array2)[i]<<","<<std::endl;
		//EXPECT_EQ(compare , (*array2)[i]);

		compare++;
	}
}

