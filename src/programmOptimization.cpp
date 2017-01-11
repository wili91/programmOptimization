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

//#include "../include/excerciseA.h"
//#include "../include/excerciseB.h"
#include "../include/TimeMeasurement.h"
#include "gtest/gtest.h"

int main(int arg, char** argc) {

//	//because unique ptr may be buggy in reclaiming ressouces
//	std::shared_ptr<std::array<double, start_size>> array(
//			new std::array<double, start_size>);
//
//	genrate_array(*array);
//	Measurement<start_size, double> measure_double;
//
//	measure_double.measure_time_sorting_all(*array);



	testing::InitGoogleTest(&arg, argc);
	return RUN_ALL_TESTS();
}
