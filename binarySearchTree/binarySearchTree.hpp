#include <iostream>

struct node{
	int value;
	struct node* right;
	struct node* left;
};

template <typename T>
class BinaryTree
{

public:

	BinaryTree();
	~BinaryTree();
	void add(T val);
	void printPreOrder();
	void printInOrder();
	void printPostOrder();
	int size();
	bool lookup(T val);
	bool hasLeftChild(T val);
	bool hasRightChild(T val);
	node* Delete(T val);
	node* FindMin(struct node* node);
	short getHeightOfNode(T val);
private:
	struct node* root;
	int treeSize;
	void add(struct node** node, T val);
	bool lookup(struct node* node, T val);
	void printPreOrder(struct node* node);
	void printInOrder(struct node* node);
	void printPostOrder(struct node* node);
	void deleteTree(struct node* node);
	bool hasLeftChild(struct node* node, T val);
	bool hasRightChild(struct node* node, T val);
	node* Delete(struct node* node, T val);
	short getHeightOfNode(struct node* node, struct node* toSearch, short height);

};

template <typename T>
short BinaryTree<T>::getHeightOfNode(T val){
	short height = 0;
	struct node* tmp = new struct node;
	tmp->value = val;
	getHeightOfNode(this->root, tmp, height);
}

template <typename T>
short BinaryTree<T>::getHeightOfNode(struct node* node, struct node* toSearch, short height){
	if(node == NULL){
		return 0;
	}
	if(node->value == toSearch->value){
		return height;
	}
	
	short level = getHeightOfNode(node->left, toSearch, height+1);
	
	if(level!=0){
		return level;
	}

	return getHeightOfNode(node->right, toSearch, height+1);

	

}

template <typename T>
node* BinaryTree<T>::Delete(T val){
	Delete(this->root, val);
}

template <typename T>
BinaryTree<T>::BinaryTree(){
	this->root = NULL;
	this->treeSize = 0;
}

template <typename T>
BinaryTree<T>::~BinaryTree(){
	deleteTree(this->root);
}

template <typename T>
int BinaryTree<T>::size(){
	return this->treeSize;
}

template <typename T>
void BinaryTree<T>::add(T val){
	add(&(this->root), val);
}

template <typename T>
void BinaryTree<T>::add(struct node** node, T val){

	if(*node == NULL)	{
		struct node* tmp = new struct node;
		tmp->value = val;
		tmp->left = NULL;
		tmp->right = NULL;
		*node = tmp;
		this->treeSize++;
	}

	else
	{
		if(val > (*node)->value){
			// std::cout << val << " > " << (*node)->value << " @ " << &(*node) << "\n";
			add(&(*node)->right, val);
		}
		else{
			// std::cout << val << " < " << (*node)->value << " @ " << &(*node) << "\n";
			add(&(*node)->left, val);
		}
	}
}

template <typename T>
void BinaryTree<T>::printInOrder(){
	printInOrder(this->root);
	std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::printInOrder(struct node* node){
	if(node != NULL){
		printInOrder(node->left);
		std::cout  << node->value << " @ " << &(*node) << " -> ";
		printInOrder(node->right);
	}
}

template <typename T>
void BinaryTree<T>::printPreOrder(){
	printPreOrder(this->root);
	std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::printPreOrder(struct node* node){
	if(node != NULL)	{
		std::cout  << node->value << " @ " << &(*node) << " -> ";
		printInOrder(node->left);
		printInOrder(node->right);
	}
}

template <typename T>
void BinaryTree<T>::printPostOrder(){
	printPostOrder(this->root);
	std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::printPostOrder(struct node* node){
	if(node != NULL){
		printInOrder(node->left);
		printInOrder(node->right);
		std::cout  << node->value << " @ " << &(*node) << " -> ";
	}
}


template <typename T>
void BinaryTree<T>::deleteTree(struct node* node){
	if(node != NULL){
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

template <typename T>
bool BinaryTree<T>::lookup(T val){
	return lookup(this->root, val);
}

template <typename T>
bool BinaryTree<T>::lookup(struct node* node, T val){
	if(node == NULL)
	{
		return false;
	}
	else
	{
		if(val == node->value){
			return true;
		}

		if(val > node->value){
			return lookup(node->right, val);
		}
		else
		{
			return lookup(node->left, val);
		}
	}
}

template <typename T>
bool BinaryTree<T>::hasLeftChild(T val){
	return hasLeftChild(this->root, val);
}


template <typename T>
bool BinaryTree<T>::hasLeftChild(struct node* node, T val){
	if(node == NULL){
		return false;
	}
	else{
		if(val == node->value){
			if(node->left == NULL){
				return false;
			}
			else{
				return true;
			}
		}
	}

	if(val > node->value){
		hasLeftChild(node->right, val);
	}
	else{
		hasLeftChild(node->left, val);
	}
}



template <typename T>
bool BinaryTree<T>::hasRightChild(T val){
	return hasRightChild(this->root, val);
}


template <typename T>
bool BinaryTree<T>::hasRightChild(struct node* node, T val){
	if(node == NULL){
		return false;
	}
	else{
		if(val == node->value){
			if(node->left == NULL){
				return false;
			}
			else{
				return true;
			}
		}
	}
	
	if(val > node->value){
		hasRightChild(node->right, val);
	}
	else{
		hasRightChild(node->left, val);
	}
}

// template <typename T>
// node* BinaryTree<T>::FindMin(){
// 	return FindMin(this->root);
// }

template <typename T>
node* BinaryTree<T>::FindMin(node* node)
{
	while(node->left != NULL){
		node = node->left;
	}
	return node;
}

template <typename T>
node* BinaryTree<T>::Delete(struct node* node, T val) 
{
	if(node == NULL) 
	{
		return node; 
	}
	else if(val < node->value)
	{
		node->left = Delete(node->left,val);
	}
	else if (val > node->value) 
	{
		node->right = Delete(node->right,val);
	}
	// node found. delete it
	else {
		// Case 1:  No child
		if(node->left == NULL && node->right == NULL) { 
			delete node;
			node = NULL;
		}
		//Case 2: One child 
		else if(node->left == NULL) {
			struct node *temp = node;
			node = node->right;
			delete temp;
		}
		else if(node->right == NULL) {
			struct node *temp = node;
			node = node->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			struct node *temp = FindMin(node->right);
			node->value = temp->value;
			node->right = Delete(node->right,temp->value);
		}
	}
	return node;
}
