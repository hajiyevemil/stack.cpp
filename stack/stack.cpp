#include <iostream>
#include <sstream>
#include <stack>
#include <string>

int main() {
    std::string input;
    std::stack<int> myStack;

    std::cout << "Enter a postfix expression (e.g., '10 4 + 2 * 3 -'): ";
    std::getline(std::cin, input);

    std::stringstream ss(input);
    std::string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {

            int b = myStack.top(); myStack.pop();
            int a = myStack.top(); myStack.pop(); 

            if (token == "+") {
                myStack.push(a + b);
            }
            else if (token == "-") {
                myStack.push(a - b);
            }
            else if (token == "*") {
                myStack.push(a * b);
            }
            else if (token == "/") {
                myStack.push(a / b);
            }
        }
        else {
            myStack.push(std::stoi(token));
        }
    }

    int result = myStack.top();
    std::cout << "The result is: " << result << std::endl;

    return 0;
}
