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
//	mytree.append(100);
//	mytree.append(50);
//	mytree.append(200);
//	mytree.append(30);
//	mytree.append(10);
//	mytree.append(40);
//	mytree.append(80);
//	mytree.append(70);
//	mytree.append(90);
//	mytree.append(170);
//	mytree.append(180);
//	mytree.append(300);
//	mytree.append(250);
//	
//	BinaryTree<int> histree;
//	histree.append(20);
//	histree.append(45);
//	histree.append(120);
//	histree.append(33);
//	histree.append(71);
//	histree.append(94);
//	histree.append(8);
//	histree.append(7);
//
//	cout << "\n***inorder_print  mytree***\n" << mytree.sum_all();  //1570
//	//mytree.inorder_print();
//	cout << "\n***inorder_print  histree***\n" << histree.sum_all(); //398
//	//histree.inorder_print();
//	
//	BinaryTree<int> ourtree;
//	ourtree = mytree + histree;
//	cout << "\n***inorder_print  ourtree***\n" << ourtree.sum_all(); //1968
//	ourtree.inorder_print();
//	
//  ourtree.remove(50);
//	cout << "\n***after remove  ourtree***\n" << ourtree.sum_all();  //1918
//	//ourtree.inorder_print();
	
	return 0;
}
