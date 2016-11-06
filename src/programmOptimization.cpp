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
#include "../include/TimeMeasurement.h"


int  main(int arg, char** argc) {
	const std::size_t start_size = 64000;

	std::array<double,start_size> array;
	genrate_array(array);
	std::cout<<"Minimum one loop:" << std::endl;
	std::cout<<" " << std::endl;
	genrate_and_measure<start_size, double>(plain_minimum, array);

	std::cout<<" " << std::endl;
	std::cout<<"Minimum two loops:" << std::endl;
	std::cout<<" " << std::endl;
	genrate_and_measure<start_size, double>(minimum_two_loops, array);


	std::cout<<" " << std::endl;
	std::cout<<"Minimum Prefetch:" << std::endl;
	std::cout<<" " << std::endl;
	genrate_and_measure<start_size, double>(minimum_prefetch, array);

	return 0;
}
