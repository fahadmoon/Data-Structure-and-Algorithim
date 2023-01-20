#include <iostream>
#include <string>
using namespace std;

const int stackSize = 100;

class Stack {
private:
  char stack[stackSize];
  int top;

public:
  Stack() 
  {
    top = -1;
  }

  void push(char value) {
    if (top >= stackSize - 1) {
      cout << "Stack is Full" << endl;
    } else {
      top++;
      stack[top] = value;
    }
  }

  void pop() {
    if (top < 0) {
      cout << "Stack is empty" << endl;
    } else {
      top--;
    }
  }

  bool is_empty() {
    return top < 0;
  }

  char peek() 
  {
    if (top < 0) {
      cout << "Stack is empty" << endl;
      return '\0';
    } else {
      return stack[top];
    }
  }
};

int getPriority(char ch) {
  if (ch == '+' || ch == '-') {
    return 1;
  } else if (ch == '*' || ch == '/') {
    return 2;
  } else if (ch == '^') {
    return 3;
  }
  return 0;
}

string infixToPostfix(string infix) 
{
  string postfix = "";
  Stack stack;

  for (int i = 0; i < infix.length(); i++) {
    char ch = infix[i];
    if (isdigit(ch)) {
      postfix+= ch;
    } 
	else if (ch == '(') {
      stack.push(ch);
    } 
	else if (ch == ')') {
      while (!stack.is_empty() && stack.peek() != '(')
	  {
        postfix += stack.peek();
        stack.pop();
      }
      stack.pop();
    }
	 else {
      while (!stack.is_empty() && getPriority(ch) <= getPriority(stack.peek())) {
        postfix += stack.peek();
        stack.pop();
      }
      stack.push(ch);
    }
  }

  while (!stack.is_empty()) {
    postfix += stack.peek();
    stack.pop();
  }

  return postfix;
}

int main() {
  string infix = "(5+2)*7";
  string postfix = infixToPostfix(infix);
  cout << "Infix expression: " << infix <<endl;
  cout << "Postfix expression: " << postfix <<endl;

  return 0;
}

