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


TEST(SelectionSort, double){
	//because unique ptr may be buggy in reclaiming ressouces
	std::shared_ptr<std::array<double, 10>> array(
			new std::array<double, 10>);

	genrate_array_desc(*array);
	selection_Sort(*array,prefetch_minimum_index);
	double compare = 1.0;
	for (std::size_t i = 0; i < array->size(); i++) {

		EXPECT_EQ(compare , (*array)[i]);

		compare++;
	}


	//because unique ptr may be buggy in reclaiming ressouces
	std::shared_ptr<std::array<double, 10>> array1(
			new std::array<double, 10>);

	genrate_array_desc(*array1);
	selection_Sort(*array1,plain_minimum_index);
	compare = 1;
	for (std::size_t i = 0; i < array1->size(); i++) {

		EXPECT_EQ(compare , (*array1)[i]);

		compare++;
	}


	//because unique ptr may be buggy in reclaiming ressouces
	std::shared_ptr<std::array<double, 10>> array2(
			new std::array<double, 10>);

	genrate_array_desc(*array2);
	selection_Sort(*array2,minimum_two_loops_index);
	compare = 1;
	for (std::size_t i = 0; i < array2->size(); i++) {

		EXPECT_EQ(compare , (*array2)[i]);

		compare++;
	}
}

TEST(SelectionSort, integer){
	//because unique ptr may be buggy in reclaiming ressouces
	std::shared_ptr<std::array<int, 10>> array(
			new std::array<int, 10>);

	genrate_array_desc(*array);
	selection_Sort(*array,prefetch_minimum_index);
	int compare = 1;
	for (std::size_t i = 0; i < array->size(); i++) {

		EXPECT_EQ(compare , (*array)[i]);

		compare++;
	}


	//because unique ptr may be buggy in reclaiming ressouces
	std::shared_ptr<std::array<int, 10>> array1(
			new std::array<int, 10>);

	genrate_array_desc(*array1);
	selection_Sort(*array1,plain_minimum_index);
	compare = 1;
	for (std::size_t i = 0; i < array1->size(); i++) {

		EXPECT_EQ(compare , (*array1)[i]);

		compare++;
	}


	//because unique ptr may be buggy in reclaiming ressouces
	std::shared_ptr<std::array<int, 10>> array2(
			new std::array<int, 10>);

	genrate_array_desc(*array2);
	selection_Sort(*array2,minimum_two_loops_index);
	compare = 1;
	for (std::size_t i = 0; i < array2->size(); i++) {

		EXPECT_EQ(compare , (*array2)[i]);

		compare++;
	}
}

TEST(SelectionSort, string){

	std::shared_ptr<std::array<std::string, 7>> array(
			new std::array<std::string, 7>);

	std::array<std::string, 7> array1 ={"aaa ", "bb ", " a ", "", "cc", "abc", "xyz"};
	for (std::size_t i = 0; i < array->size(); i++) {
			(*array)[i]	= array1[i];
	}
	selection_Sort(*array,prefetch_minimum_index);
	EXPECT_EQ("" , (*array)[0]);


	for (std::size_t i = 0; i < array->size(); i++) {
			(*array)[i]	= array1[i];
	}
	selection_Sort(*array,minimum_two_loops_index);
	EXPECT_EQ("" , (*array)[0]);

	for (std::size_t i = 0; i < array->size(); i++) {
			(*array)[i]	= array1[i];
	}
	selection_Sort(*array,plain_minimum_index);
	EXPECT_EQ("" , (*array)[0]);
}
