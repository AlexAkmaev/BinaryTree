#include "binary_tree.hpp"
using namespace std;

int main(){
	BinaryTree<int> mytree;
	mytree.append(100);
	mytree.append(50);
	mytree.append(200);
	mytree.append(30);
	mytree.append(10);
	mytree.append(40);
	mytree.append(80);
	mytree.append(70);
	mytree.append(90);
	mytree.append(170);
	mytree.append(180);
	mytree.append(300);
	mytree.append(250);
	
	BinaryTree<int> histree;
	histree.append(20);
	histree.append(45);
	histree.append(120);
	histree.append(33);
	histree.append(71);
	histree.append(94);
	histree.append(8);
	histree.append(7);

	cout << "\n***inorder_print  mytree***\n";
	mytree.inorder_print();
	cout << "\n***inorder_print  histree***\n";
	histree.inorder_print();
	
	BinaryTree<int> ourtree;
	ourtree = mytree + histree;
	cout << "\n***inorder_print  ourtree***\n";
	ourtree.inorder_print();
	
  ourtree.remove(50);
	cout << "\n***after remove  ourtree***\n";
	ourtree.inorder_print();
	
	return 0;
}
