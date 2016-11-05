//============================================================================
// Name        : programmOptimization.cpp
// Author      : lisa
// Version     :
// Copyright   : Alles MEINS!!!
// Description : This is the main class of the project for the lecture "programm
//				opimization".
//
// size of short  		2 Byte
// size of int  		4 Byte
// size of double  		8 Byte
// size of long    		8 Byte
// size of long long    8 Byte
//============================================================================




#include "../include/excerciseAandB.h"



int  main(int arg, char** argc) {
	const std::size_t start_size = 64000;

	std::array<double,start_size> array;
	genrate_array(array);
	std::cout<<"Minimum one loop:" << std::endl;
	std::cout<<" " << std::endl;
	genrate_and_measure<start_size, double>(dumb_minimum, array);

	std::cout<<" " << std::endl;
	std::cout<<"Minimum two loops:" << std::endl;
	std::cout<<" " << std::endl;
	genrate_and_measure<start_size, double>(minimum_two_loops, array);


	std::cout<<" " << std::endl;
	std::cout<<"Minimum Prefetch:" << std::endl;
	std::cout<<" " << std::endl;
	genrate_and_measure<start_size, double>(minimum_prefetch, array);


	::testing::InitGoogleTest(&arg, argc);
	return RUN_ALL_TESTS();


	return 0;
}

int doppelt(int a){
	return a*2;
}


TEST(Minimum, dumb_minimum){
	std::array<int, 6> arr ={9,7,6,6,7,1};
	EXPECT_EQ(1, dumb_minimum(arr, 6));

	std::array<int, 6> arr1 ={1,9,7,0,6,7};
	EXPECT_EQ(0, dumb_minimum(arr1, arr1.size()));
}


TEST(MinimumIndex, minimum_index){
	std::array<int, 6> arr ={9,7,6,6,7,1};
	EXPECT_EQ(5, minimum_index(arr, 3 ,arr.size()));
	std::cout<<"Minimum is "<< arr[minimum_index(arr, 3,arr.size())]<< std::endl;

	std::array<int, 6> arr1 ={1,9,7,0,6,7};
	EXPECT_EQ(3, minimum_index(arr1, 0,4));
	std::cout<<"Minimum is "<< arr1[minimum_index(arr1, 0,4)]<< std::endl;

	EXPECT_EQ(0, minimum_index(arr1, 0,3));
	std::cout<<"Minimum is "<< arr1[minimum_index(arr1, 0,3)]<< std::endl;

	EXPECT_EQ(3, minimum_index(arr1, 0,arr1.size()));
	std::cout<<"Minimum is "<< arr1[minimum_index(arr1, 0,arr1.size())]<< std::endl;

	EXPECT_EQ(4, minimum_index(arr1, 4,arr1.size()));
	std::cout<<"Minimum is "<< arr1[minimum_index(arr1, 4,arr1.size())]<< std::endl;
}

