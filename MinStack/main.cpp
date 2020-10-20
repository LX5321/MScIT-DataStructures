#include <iostream>
#include "minStack.h"

int main(){
	minStack<int> stackInterface;
	int element, elementCount;

	std::cin >> elementCount;

	for(short index=0;index< elementCount;index++){
		std::cin >> element;
		stackInterface.push(element);
		
		// for logging purposes.
		std::cout << element << " appended to stack."<<std::endl;

	}

	std::cout<<"Minimum: " << stackInterface.getMinimum();

	return 0;
}
