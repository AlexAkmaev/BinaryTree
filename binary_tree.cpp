#include "binary_tree.hpp"
#include "profile.h"
using namespace std;

int main(){
	BinaryTree<uint64_t> mytree;
	uint64_t data;
	while(std::cin >> data) {
		mytree.append(data);
	}
	{
		LOG_DURATION("Without threads");
		std::cout << mytree.sum_one_thread(mytree.get_root()) << endl;
	}
	{
		LOG_DURATION("With threads");
		std::cout << mytree.sum_all() << endl;
	}
	
	return 0;
}
