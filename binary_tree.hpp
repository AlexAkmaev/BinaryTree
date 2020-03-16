#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
class BinaryTree{
	struct Node{
    explicit Node() = default;
    explicit Node(const T& data) : value(data), left(nullptr), right(nullptr){}
    
    T value;
    Node* right,* left;
	};
	
	Node* root;
  
	void __inorder_traversal__(Node* node = nullptr, int indent = 0) const;
	void __preorder_traversal__(Node* node = nullptr, int indent = 0) const;
	void __postorder_traversal__(Node* node = nullptr, int indent = 0) const;
	
	Node* __search__(Node* node, T data) const;
	
  Node* __append__(Node* node, T data);
	void __add__(Node* node = nullptr);
	
	Node* __remove__(Node* node, T data);
  
public:
	explicit BinaryTree();
	~BinaryTree();
	
	void inorder_print(int indent = 0) const;
	void preorder_print(int indent = 0) const;
	void postorder_print(int indent = 0) const;

	Node* search(T data) const;

	Node* minimum(Node* node = nullptr) const;
	Node* maximum(Node* node = nullptr) const;

	Node* next(T data) const;
	Node* prev(T data) const;

	
	Node* append(T data);
	Node* remove(T data);

	Node* get_root() const;
	
	BinaryTree<T> operator+(const BinaryTree<T>& lhs);

};

template<typename T>
BinaryTree<T>::BinaryTree() : root(nullptr){}

template<typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::get_root() const{
  return root;
}

template< typename T >
void BinaryTree<T>::__inorder_traversal__(Node* node, int indent) const{
  if(node != nullptr) {
		if(node->right) {
		  __inorder_traversal__(node->right, indent + 4);
		}
		if (indent) {
		  std::cout << std::setw(indent) << ' ';
		}
		if (node->right) std::cout<<" /\n" << std::setw(indent) << ' ';
		  std::cout<< node->value << "\n ";
		if(node->left) {
		  std::cout << std::setw(indent) << ' ' << " \\\n";
		  __inorder_traversal__(node->left, indent + 4);
		}
  }
}

template< typename T >
void BinaryTree<T>::inorder_print(int indent) const{
	if (root == nullptr) {
		std::cout << "Empty tree:(" << endl;
	} else {
	  __inorder_traversal__(root, indent);
	}
}

template< typename T >
void BinaryTree<T>::__postorder_traversal__(Node* node, int indent) const {
  if(node != nullptr) {
		if(node->right) {
		  __postorder_traversal__(node->right, indent + 4);
		}
		if(node->left) {
		  std::cout << std::setw(indent) << ' ' << " \\\n";
		  __postorder_traversal__(node->left, indent + 4);
		}
		if (indent) {
		  std::cout << std::setw(indent) << ' ';
		}
		if (node->right) std::cout<<" /\n" << std::setw(indent) << ' ';
		  std::cout<< node->value << "\n ";
  }
}

template< typename T >
void BinaryTree<T>::postorder_print(int indent) const{
	if (root == nullptr) {
		std::cout << "Empty tree:(" << endl;
	} else {
	  __postorder_traversal__(root, indent);
	}
}

template< typename T >
void BinaryTree<T>::__preorder_traversal__(Node* node, int indent) const {
  if(node != nullptr) {
		if (indent) {
		  std::cout << std::setw(indent) << ' ';
		}
		if (node->right) std::cout<<" /\n" << std::setw(indent) << ' ';
		  std::cout<< node->value << "\n ";
		if(node->right) {
		  __preorder_traversal__(node->right, indent + 4);
		}
		if(node->left) {
		  std::cout << std::setw(indent) << ' ' << " \\\n";
		  __preorder_traversal__(node->left, indent + 4);
		}
  }
}

template< typename T >
void BinaryTree<T>::preorder_print(int indent) const{
	if (root == nullptr) {
		std::cout << "Empty tree:(" << endl;
	} else {
	  __preorder_traversal__(root, indent);
	}
}

template< typename T >
typename BinaryTree<T>::Node* BinaryTree<T>::__search__(Node* node, T data) const{
  if (node == nullptr || data == node->value)
    return node;
  if (data < node->value)
    return __search__(node->left, data);
  else
    return __search__(node->right, data);
}

template< typename T >
typename BinaryTree<T>::Node* BinaryTree<T>::search(T data) const{
  if (root == nullptr) {
  	std::cout << "Nothing to search:(" << endl;
  	return nullptr;
  } else {
  	return __search__(root, data);
  }
}

template< typename T >
typename BinaryTree<T>::Node* BinaryTree<T>::minimum(Node* node) const{
  if (node->left == nullptr)
    return node;
  else
    return minimum(node->left);
}

template< typename T >
typename BinaryTree<T>::Node* BinaryTree<T>::maximum(Node* node) const{
  if (node->right == nullptr)
    return node;
  else
    return maximum(node->right);
}

template< typename T >
typename BinaryTree<T>::Node* BinaryTree<T>::next(T data) const{
  Node* current = root;
  Node* successor = nullptr;
  while(current){
    if (current->value > data){
      current = current.left;
    }
    else
      successor = current;
      current = current.right;
  }
  return successor;
}

template< typename T >
typename BinaryTree<T>::Node* BinaryTree<T>::prev(T data) const{
  Node* current = root;
  Node* successor = nullptr;
  while(current) {
    if (current->value > data){
      successor = current;
      current = current.left;
    }
    else
      current = current.right;
  }
  return successor;
}

template< typename T >
typename BinaryTree<T>::Node* BinaryTree<T>::__append__(Node* node, T data){
	Node* tmp = new Node(data);
	if(root == nullptr) {
		root = tmp;
		return root;
	} else {
  	if(!node) {
      return tmp;
  	}
  	else if(data < node->value)
      node->left = __append__(node->left, data);
  	else if(data > node->value)
      node->right = __append__(node->right, data);
  	delete tmp;
  	return node;
  }
}

template< typename T >
typename BinaryTree<T>::Node* BinaryTree<T>::append(T data){
	__append__(root, data);
}

template< typename T >
void BinaryTree<T>::__add__(Node* node) {
	if (node){
    __add__(node->left);
    append(node->value);
    __add__(node->right);
  }
}

template<typename T>
BinaryTree<T> BinaryTree<T>::operator+(const BinaryTree<T>& lhs) {
	BinaryTree<T> ans = *this;
	ans.__add__(lhs.get_root());
	return ans;
}

template< typename T >
typename BinaryTree<T>::Node* BinaryTree<T>::__remove__(Node* node, T data){
  if(!node)
    return node;
  if (data < node->value)
    node->left = __remove__(node->left, data);
  else if (data > node->value)
    node->right = __remove__(node->right, data);
  else if (node->left && node->right){
    node->value = minimum(node->right)->value;
    node->right = __remove__(node->right, node->value);
  }
  else{
    if (node->left)
      node = node->left;
    else if (node->right)
      node = node->right;
    else
      node = nullptr;
  }
  return node;
}

template< typename T >
typename BinaryTree<T>::Node* BinaryTree<T>::remove(T data){
	__remove__(root, data);
}

template<typename T>
BinaryTree<T>::~BinaryTree(){
	Node* temp = root;
	while(root){
		root = remove(root->value);
	}
}
