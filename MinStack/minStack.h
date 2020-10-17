#include<stack>
template <typename T>
class minStack{

private:
	std::stack <T> s;
	T minimumElement;

public:
	void push(T element)
	{
		// if empty
		if(s.empty()){
			s.push(element);
			minimumElement = element;
		}

		// if greater than
		else if(element > minimumElement){
			s.push(element);
		}

		// else for other cases
		else{
			s.push( (2 * element) - minimumElement );
			minimumElement = element;
		}

	}
	void pop()
	{
		if(s.empty()){return;} // do nothing on underflow

		else if(s.top() < minimumElement)
		{
			minimumElement = ((2*minimumElement)-s.top());
			s.pop();
		}
	}

	T peek(){return s.top();} // directly return topmost element
	T getMinimum(){return minimumElement;} // return minimum element
};
