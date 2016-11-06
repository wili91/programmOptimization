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

//constants 64 Bytes Cache Line (16 int)
extern const std::size_t  	CACHE_LINE_BYTES = 64;
//4096 Byte Cache Size
extern const std::size_t 	L1_CACHE_SIZE_INT = 1024;




#endif /* CONSTANTS_H_ */
