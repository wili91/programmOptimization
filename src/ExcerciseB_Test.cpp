/*
 * ExcerciseB_Test.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: lisa
 */


#include "gtest/gtest.h"
#include "../include/excerciseA.h"
#include "../include/excerciseB.h"

class ExcerciseB : public ::testing::Test{

};


TEST(SelectionSort, plain_minimum_double){
	//because unique ptr may be buggy in reclaiming ressouces
	std::shared_ptr<std::array<double, 10>> array(
			new std::array<double, 10>);

	genrate_array_desc(*array);
	for (std::size_t i = 0; i < array->size(); i++) {
		std::cout << (*array)[i] << std::endl;
	}
	selection_Sort(*array,prefetch_minimum_index);
	for (std::size_t i = 0; i < array->size(); i++) {
		std::cout << (*array)[i] << std::endl;
	}
	const double min = plain_minimum(*array, 0, array->size());
	EXPECT_EQ(min , (*array)[0]);
}

