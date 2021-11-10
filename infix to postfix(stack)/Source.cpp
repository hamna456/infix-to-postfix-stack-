#include<iostream>
# include <string>
#include<cmath>
#include <sstream>
#include <queue>
using namespace std;

class Stack_char {    // char stack
	char* stack;
	int top = -1;
	int size;

public:
	bool isEmpty() { // check if the stack is empty
		return(top == -1);
	}

	bool isFull() {  // check if the stack is full
		return(top == size - 1);
	}

	Stack_char(int arr_size) { // constructor
		size = arr_size;
		stack = new char[size];
	}

	void push(char val) {   //insert the value into stack
		if (isFull())
			cout << "----Stack Overflow!----" << endl;
		else {
			stack[++top] = val;
		}
	}

	char pop() {       // delete and return the element from top of stack
		if (isEmpty()) {
			//--Stack Underflow!---" 
			return '-1';
		}
		else {
			//The popped element is stack[top] 
			return stack[top--];
		}
	}

	void clear() { //release the memory allocated by stack
		delete stack;   // delete the array
	}

	char peak() {  //display the contents of the top element of stack

		if (isEmpty()) {
			//--Stack Underflow!--
			return '-1';
		}
		else {
			//The element at peak is stack[top] 
			return stack[top];
		}
	}

};

class Stack_float {   // float stack
	float* stack;
	int top = -1;
	int size;

public:
	bool isEmpty() { // check if the stack is empty
		return(top == -1);
	}

	bool isFull() {  // check if the stack is full
		return(top == size - 1);
	}

	Stack_float(int Size) { // constructor
		size = Size;
		stack = new float[size];
	}

	void push(float val) {   //insert the value into stack
		if (isFull())
			cout << "----Stack Overflow!----" << endl;
		else {
			stack[++top] = val;
		}
	}

	float pop() {       // delete and return the element from top of stack
		if (isEmpty()) {
			cout << "---Stack Underflow!---" << endl;
			return -1;
		}
		else {
			return stack[top--];
		}
	}

	void clear() { //release the memory allocated by stack

		delete stack;   // delete the array
		cout << "---Stack clear successfully---" << endl;
	}

	void peak() {  //display the contents of the top element of stack

		if (isEmpty()) {
			cout << "---Stack Underflow!--" << endl;
		}
		else {
			cout << "The element at peak is " << stack[top] << endl;
		}
	}

};

