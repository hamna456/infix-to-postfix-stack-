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

class postfix {

public:

	int Precedence(char c) {     //for precedence of operators
		if (c == '+' || c == '-')
			return 1;
		else if (c == '/' || c == '*')
			return 2;
		else if (c == '^')
			return 3;
		else
			return -1;
	}

	bool valid_brackets(string exp) {
		int opening_Bracket_no = 0;
		int closing_Bracket_no = 0;

		for (int i = 0; i < exp.length(); i++) { // traverse he string
			if ((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{')) {
				opening_Bracket_no++;
			}
			else if ((exp[i] == ')') || (exp[i] == ']') || (exp[i] == '}')) {
				closing_Bracket_no++;
			}
		}

		Stack_char s1(opening_Bracket_no); // stack of size =no.of opening bracket

		for (int i = 0; i < exp.length(); i++) {
			if ((exp[i] == '(') || (exp[i] == '{') || (exp[i] == '[')) {
				// if opening bracket then push into stack
				s1.push(exp[i]);
			}
			else if ((exp[i] == ')') || (exp[i] == '}') || (exp[i] == ']')) {
				// if closing bracket then check if it match to bracket at top then pop it

				if (s1.peak() != '- 1') {
					if ((s1.peak() == '(') && (exp[i] == ')')) {
						s1.pop();
					}
					if ((s1.peak() == '{') && (exp[i] == '}')) {
						s1.pop();
					}
					if ((s1.peak() == '[') && (exp[i] == ']')) {
						s1.pop();
					}
				}
			}
		}


		return (s1.isEmpty() && (opening_Bracket_no == closing_Bracket_no)) ;

	}

	bool is_opening_bracket(char c) {
		return ( (c == '(') || (c == '{') || (c == '[') );
	}

	bool is_closing_bracket(char c) {
		return ((c == ')') || (c == '}') || (c == ']'));
	}

	bool is_operator(char c) {
		return ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^'));
	}


	bool valid_operator(string exp) { // check if valid operator,brackets are placed
		bool valid = false;
		for (int i = 0; i < exp.length(); i++) {
			if (isdigit(exp[i]))
				valid = true;
			else if (isspace(exp[i]))
				valid = true;
			else if (is_closing_bracket(exp[i]))
				valid = true;
			else if (is_opening_bracket(exp[i]))
				valid = true;
			else if (is_operator(exp[i]))
				valid = true;
	
		}

		return(valid);
	}


	string InfixToPostfix(string s) { //convert infix expression to postfix expression

		Stack_char st(s.length());
		string output;
		string multi_digit;

		for (int i = 0; i < s.length(); i++) {
			char c = s[i];

			 if (isdigit(c)) { // if space move it to output
				 output += c;
			}

			 else if (!isspace(c)) { // if bracket or operator occur
				 output += " ";

			 // If the character is opening bracket, push it to the stack.
				 if (c == '(' || c == '{' || c == '[')
					 st.push(c);

				 /* If the character is an closing bracket then pop all the char to output string
				 from the stack until a closin bracket is encountered.*/
				 else if (c == ')') {
					 while (st.peak() != '(')
					 {
						 output += st.peak();
						 st.pop();
					 }
					 st.pop();
				 }

				 else if (c == '}') {
					 while (st.peak() != '{')
					 {
						 output += st.peak();
						 st.pop();
					 }
					 st.pop();
				 }

				 else if (c == ']') {
					 while (st.peak() != '[')
					 {
						 output += st.peak();
						 st.pop();
					 }
					 st.pop();
				 }
				 //If char is operator 
				 else {
					 while (!st.isEmpty() && Precedence(s[i]) <= Precedence(st.peak())) {
						 output += st.peak();
						 output += " ";
						 st.pop();
					 }
					 st.push(c);
				 }
			 }
		}

		// Pop all the remaining elements from the stack
		while (!st.isEmpty()) {
			output +=" "; // to add space after the last digit
			output += st.peak();
			st.pop();
		}

		string postfix=remove_extra_spaces(output); // remove extra spaces

		cout << postfix << endl;
		return postfix; 
	}

	// function splits the expression on spaces and returns a queue of operators and operands
	queue<string> splitOnSpaces(string exp)
	{
		queue<string> terms; // queue for terms
		int currIndex = 0, i = 0, startIndex = 0, endIndex = 0;

		while (i <= (exp.length()))
		{
			if (isspace(exp[i]) || i == exp.length()) // if spaces is found
			{
				endIndex = i;
				string subStr = "";
				subStr.append(exp, startIndex, endIndex - startIndex); // spliting

				if (subStr != "")
					terms.push(subStr); // pushing to queue

				currIndex += 1;
				startIndex = endIndex + 1;
			}
			i++;
		}
		return terms;
	}

	string remove_extra_spaces(string exp) { // remove extra spaces
		string without_space = "";
		without_space+=(exp[0]);

		for (int i = 1; i < exp.length()+1 ; i++) {
			if (!(without_space[i-1] == ' ' && exp[i] == ' ')) { 
				without_space+=(exp[i]);
			}
		}

		return without_space;

}


float evalPostfix(string exp)
{
	queue<string> terms = splitOnSpaces(exp); //spliting the postfix exp on spaces
	Stack_float stack(exp.length() / 2);          //stack for numbers

	while (!terms.empty()) //loop runs till last token
	{
		char* tokenChar = &terms.front()[0]; //converting term to char*

		// push the digits to the stack till operator is found
		if (isdigit(*tokenChar))
			stack.push(stof(terms.front())); //converting to float

		else
		{
			// remove the top two elements from the stack
			float a = stack.pop();
			float b = stack.pop();

			// apply operation on a and b then push result to stack
			if (*tokenChar == '+') {
				stack.push(b + a);
			}
			else if (*tokenChar == '-') {
				stack.push(b - a);
			}
			else if (*tokenChar == '*') {
				stack.push(b * a);
			}
			else if (*tokenChar == '/') {
				stack.push(b / a);

			}
			else if (*tokenChar == '^') {
				stack.push(pow(b, a)); //find b^a
			}
		}
		terms.pop();
	}

	// final result
	float result;
	result=stack.pop();
	return result;
}
		
}; // class end


//test above functions
int main() {

	string exp,postfix_result;
	cout << "Enter the expression: " << endl;
	getline(cin, exp); // we can add spaces and spaces will be treated as a char

	postfix p;
    // check validity
	
	if(p.valid_brackets(exp) && p.valid_operator(exp)){
		//cout << "---The expression is valid----" << endl;

		cout << "----------------" << endl;
		cout << "Postfix is: ";
		postfix_result = p.InfixToPostfix(exp);
		cout << "----------------" << endl;

		cout << "Postfix evaluation result is: ";
		cout << p.evalPostfix(postfix_result) << endl;
		cout << "----------------" << endl;
		
    }

	else {
		cout << "---The expression is invalid!----" << endl;
		
	}
    
	return 0;


}