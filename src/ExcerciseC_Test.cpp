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

	std::shared_ptr<std::array<double, 5>> a2(
			new std::array<double, 5>);
	genrate_array_desc(*a2);

	prefetch_Insertionsort(*a2);

	compare = 1.0;
	for (std::size_t i = 0; i < a2->size(); i++) {


//		std::cout<<(*a2)[i]<<","<<std::endl;
		EXPECT_EQ(compare , (*a2)[i]);

		compare++;
	}
}

