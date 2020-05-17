#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
using namespace std;

const uint64_t amount_of_data = 10000000;
const uint64_t peak_value = 5*amount_of_data;

int main() {
  mt19937_64 random_gen;
  for(int i = 0; i < amount_of_data; ++i) {
  	cout << random_gen() % peak_value << '\n';
  }
	
	return 0;
}
