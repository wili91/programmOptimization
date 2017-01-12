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
	selection_Sort(*array);
	double compare = 1.0;
	for (std::size_t i = 0; i < array->size(); i++) {

		EXPECT_EQ(compare , (*array)[i]);

		compare++;
	}


	//because unique ptr may be buggy in reclaiming ressouces
	std::shared_ptr<std::array<double, 10>> array1(
			new std::array<double, 10>);

	genrate_array_desc(*array1);
	selection_Sort_Two_Loops(*array1);
	compare = 1;
	for (std::size_t i = 0; i < array1->size(); i++) {

		EXPECT_EQ(compare , (*array1)[i]);

		compare++;
	}


	//because unique ptr may be buggy in reclaiming ressouces
	std::shared_ptr<std::array<double, 10>> array2(
			new std::array<double, 10>);

	genrate_array_desc(*array2);
	selection_Sort_Prefetch(*array2);
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
	selection_Sort(*array);
	int compare = 1;
	for (std::size_t i = 0; i < array->size(); i++) {

		EXPECT_EQ(compare , (*array)[i]);

		compare++;
	}


	//because unique ptr may be buggy in reclaiming ressouces
	std::shared_ptr<std::array<int, 10>> array1(
			new std::array<int, 10>);

	genrate_array_desc(*array1);
	selection_Sort(*array1);
	compare = 1;
	for (std::size_t i = 0; i < array1->size(); i++) {

		EXPECT_EQ(compare , (*array1)[i]);

		compare++;
	}


	//because unique ptr may be buggy in reclaiming ressouces
	std::shared_ptr<std::array<int, 10>> array2(
			new std::array<int, 10>);

	genrate_array_desc(*array2);
	selection_Sort_Two_Loops(*array2);
	compare = 1;
	for (std::size_t i = 0; i < array2->size(); i++) {

		EXPECT_EQ(compare , (*array2)[i]);

		compare++;
	}
}

TEST(SelectionSort, string){

	std::shared_ptr<std::array<std::string, 7>> array(
			new std::array<std::string, 7>{{"aaa ", "bb ", " a ", "", "cc", "abc", "xyz"}});
	selection_Sort(*array);
	checkSorted(*array);


	std::cout<< std::endl << std::endl;
	std::shared_ptr<std::array<std::string, 7>> array1(
			new std::array<std::string, 7>{{"aaa ", "bb ", " a ", "", "cc", "abc", "xyz"}});
	selection_Sort_Two_Loops(*array1);
	checkSorted(*array1);

	std::shared_ptr<std::array<std::string, 7>> array2(
			new std::array<std::string, 7>{{"aaa ", "bb ", " a ", "", "cc", "abc", "xyz"}});
	selection_Sort_Prefetch(*array2);
	checkSorted(*array2);


}
