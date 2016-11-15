/*
 * ExcerciseA_Test.cpp
 *
 *  Created on: Nov 5, 2016
 *      Author: lisa
 */

#include "gtest/gtest.h"
#include "../include/excerciseA.h"


class ExcerciseA : public ::testing::Test{

};

//Plain Minimum Tests
TEST(PlainMinimumTest, plain_minimum_int)
{
	std::array<int, 6> arr ={9,7,6,6,7,1};
	EXPECT_EQ(1, plain_minimum(arr,0 , 6));

	std::array<int, 6> arr1 ={1,9,7,0,6,7};
	EXPECT_EQ(0, plain_minimum(arr1, 0 , arr1.size()));
}

TEST(PlainMinimumTest, plain_minimum_double){
	std::array<double, 10> arr2 ={0.4,0.9,0.09,6.09,5.9,1.25,0.39,0.9,6.09,0.09};
	EXPECT_EQ(0.09, plain_minimum(arr2,0 ,  10));

	std::array<double, 20> arr3 ={0.4,0.9,0.09,6.09,5.9,1.25,0.39,0.9,6.09,0.09,
								-0.4,0.9,0.09,6.09,-5.9,1.25,0.39,0.9,6.09,0.09};
	EXPECT_EQ(-5.9, plain_minimum(arr3, 0 , arr3.size()));
}

TEST(PlainMinimumTest, plain_minimum_string){
	std::array<std::string, 3> arr ={"Hallo ", "Welt ", "!"};
	EXPECT_EQ("!", plain_minimum(arr,0 ,  arr.size()));

	std::array<std::string, 7> arr3 ={"Äpfel ", "und ", " Birnen ", "und", " Bananen ", "sind ", "gesund."};
	EXPECT_EQ(" Bananen ", plain_minimum(arr3,0 ,  arr3.size()));
}

//Test Minimum Two Loops
TEST(Two_loops_MinimumTest, two_loops_minimum_int)
{
	std::array<int, 6> arr ={9,7,6,6,7,1};
	EXPECT_EQ(1, minimum_two_loops(arr,0 ,  6));

	std::array<int, 6> arr1 ={1,9,7,0,6,7};
	EXPECT_EQ(0, minimum_two_loops(arr1,0, arr1.size()));
}

TEST(Two_loops_MinimumTest, two_loops_minimum_double){
	std::array<double, 10> arr2 ={0.4,0.9,0.09,6.09,5.9,1.25,0.39,0.9,6.09,0.09};
	EXPECT_EQ(0.09, minimum_two_loops(arr2,0 ,  10));

	std::array<double, 20> arr3 ={0.4,0.9,0.09,6.09,5.9,1.25,0.39,0.9,6.09,0.09,
								-0.4,0.9,0.09,6.09,-5.9,1.25,0.39,0.9,6.09,0.09};
	EXPECT_EQ(-5.9, minimum_two_loops(arr3, 0 , arr3.size()));
}

TEST(Two_loops_MinimumTest, two_loops_minimum_string){
	std::array<std::string, 3> arr ={"Hallo ", "Welt ", "!"};
	EXPECT_EQ("!", minimum_two_loops(arr,0 ,  arr.size()));

	std::array<std::string, 7> arr3 ={"Äpfel ", "und ", " Birnen ", "und", " Bananen ", "sind ", "gesund."};
	EXPECT_EQ(" Bananen ", minimum_two_loops(arr3, 0 , arr3.size()));
}


//Prefetch Two Loops
TEST(Prefetch_MinimumTest, minimum_prefetch_int)
{
	std::array<int, 6> arr ={9,7,6,6,7,1};
	EXPECT_EQ(1, minimum_two_loops(arr, 0 , 6));

	std::array<int, 6> arr1 ={1,9,7,0,6,7};
	EXPECT_EQ(0, minimum_two_loops(arr1, 0 , arr1.size()));
}

TEST(Prefetch_MinimumTest, minimum_prefetch_double){
	std::array<double, 10> arr2 ={0.4,0.9,0.09,6.09,5.9,1.25,0.39,0.9,6.09,0.09};
	EXPECT_EQ(0.09, minimum_two_loops(arr2, 0 , 10));

	std::array<double, 20> arr3 ={0.4,0.9,0.09,6.09,5.9,1.25,0.39,0.9,6.09,0.09,
								-0.4,0.9,0.09,6.09,-5.9,1.25,0.39,0.9,6.09,0.09};
	EXPECT_EQ(-5.9, minimum_two_loops(arr3,0 ,  arr3.size()));
}

TEST(Prefetch_MinimumTest, minimum_prefetch_string){
	std::array<std::string, 3> arr ={"Hallo ", "Welt ", "!"};
	EXPECT_EQ("!", minimum_two_loops(arr, 0 ,arr.size()));

	std::array<std::string, 7> arr3 ={"Äpfel ", "und ", " Birnen ", "und", " Bananen ", "sind ", "gesund."};
	EXPECT_EQ(" Bananen ", minimum_two_loops(arr3, 0 , arr3.size()));
}

//Index Minimum Tests
TEST(IndexMinimumTest, minimum_index){
	std::array<int, 6> arr ={9,7,6,6,7,1};
	EXPECT_EQ(5, plain_minimum_index(arr, 3 ,arr.size()));
	//std::cout<<"Minimum is "<< arr[minimum_index(arr,0 ,  3,arr.size())]<< std::endl;

	std::array<int, 6> arr1 ={1,9,7,0,6,7};
	EXPECT_EQ(3, plain_minimum_index(arr1, 0,4));
	//std::cout<<"Minimum is "<< arr1[plain_minimum_index(arr1, 0,4)]<< std::endl;

	EXPECT_EQ(0, plain_minimum_index(arr1, 0,3));
	//std::cout<<"Minimum is "<< arr1[plain_minimum_index(arr1, 0,3)]<< std::endl;

	EXPECT_EQ(3, plain_minimum_index(arr1, 0,arr1.size()));
	//std::cout<<"Minimum is "<< arr1[plain_minimum_index(arr1, 0,arr1.size())]<< std::endl;

	EXPECT_EQ(4, plain_minimum_index(arr1, 4,arr1.size()));
	//std::cout<<"Minimum is "<< arr1[plain_minimum_index(arr1, 4,arr1.size())]<< std::endl;
}




