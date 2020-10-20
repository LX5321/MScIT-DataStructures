#include "binarySearchTree.hpp"

int main(){

	BinaryTree<int> tree;
	short val, choice;

	for(;;){
		std::cout<< "\n1. add node.";
		std::cout<< "\n2. delete node.";
		std::cout<< "\n3. prefix\n4. postfix\n5. inorder";
		std::cout<< "\n6. height of node.";
		std::cout<< "\n-1. exit\n>\t";
		std::cin >> choice;
		switch(choice){
			case -1:
				exit(0);
			case 1:
				std::cout << "Enter Element: ";
				std::cin >>val;
				tree.add(val);
				break;
			case 2:
				std::cout << "Enter Element: ";
				std::cin >>val;

				tree.Delete(val);
				break;
			case 3:
				tree.printPreOrder();
				break;
			case 4:
				tree.printPostOrder();
				break;
			case 5:
				tree.printInOrder();
				break;
			case 6:

				std::cout << "Enter Element: ";
				std::cin >>val;
				std::cout<< "Height of " << val << " is " << tree.getHeightOfNode(val);
				break;
			default:
				std::cout << "Invalid.\n";
		}
	}

	return 0;
}
