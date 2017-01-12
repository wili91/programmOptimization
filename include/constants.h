/*
 * constants.h
 *
 *  Created on: Nov 6, 2016
 *      Author: lisa
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include <array>
#include <limits>
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <random>
#include <chrono>
#include <memory>
#include "arrayMethods.h"

//constants 64 Bytes Cache Line (16 int)
static const std::size_t  	CACHE_LINE_BYTES = 64;
//4096 Byte Cache Size
static const std::size_t 	L1_CACHE_SIZE_INT = 1024;


//static const std::size_t   SORTING_THRESGHOLD = 25;
static const std::size_t   SORTING_THRESGHOLD = 25;
static const std::size_t   WORST_CASE_QS = 8;

const std::size_t start_size =2048;
const std::size_t end_size =67108864;
//const std::size_t end_size =4096;
const std::size_t SIZE_N2 = 262144;

enum SORTING{
		selection_sort,
		none
	 } ;

enum MINIMUM{
		plain_min,
		twoloops_min,
		prefretch_min,
		no_min} ;

enum ARRAYTYPE{
		random_arr,
		asc_arr,
		desc_arr,
		no_arr
} ;

#endif /* CONSTANTS_H_ */
