#include <array>
#include <memory>
#include <limits>
#include <string>
#include <random>

template<std::size_t N>
void genrate_array(std::array<double, N>& test_arr) {
	//generate the array
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist_int(0.0, 500.0);

	for (std::size_t i = 0; i < test_arr.size(); i++) {
		test_arr[i] = dist_int(mt);
	}
}

template<std::size_t N>
void genrate_array(std::array<int, N>& test_arr) {
	//generate the array
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist_int(0.0, 500.0);

	for (std::size_t i = 0; i < test_arr.size(); i++) {
		test_arr[i] = dist_int(mt);
	}
}

template<std::size_t N, typename T>
void genrate_array_asc(std::array<T, N>& test_arr) {
	for (std::size_t i = 0; i < test_arr.size(); i++) {
		//better than c stile
		test_arr[i] = dynamic_cast<T> (i);
	}
}

template<std::size_t N, typename T>
void genrate_array_desc(std::array<T, N>& test_arr) {
	for (std::size_t i = 0; i < test_arr.size(); i++) {
		//better than c stile
		test_arr[i] = dynamic_cast<T> (test_arr.size()-i);
	}
}

void flush_cache();
