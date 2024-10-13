#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Convert infix to postfix
string infixToPostfix(const string &infix) {
    stack<char> st;
    string post = "";
    for (char c : infix) {
        if (isalnum(c)) post += c;   // Append operands to postfix
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (st.top() != '(') { post += st.top(); st.pop(); }
            st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                post += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) { post += st.top(); st.pop(); }
    return post;
}

// Reverse expression (used in prefix conversion)
string reverseExpr(string expr) {
    reverse(expr.begin(), expr.end());
    for (char &c : expr) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    return expr;
}

// Convert infix to prefix
string infixToPrefix(const string &infix) {
    string revInfix = reverseExpr(infix);
    string post = infixToPostfix(revInfix);
    return reverseExpr(post);
}

// Evaluate postfix expression
int evalPostfix(const string &postfix) {
    stack<int> st;
    for (char c : postfix) {
        if (isdigit(c)) st.push(c - '0');
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') st.push(a / b);
            else if (c == '^') st.push(pow(a, b));
        }
    }
    return st.top();
}

// Main menu-driven function
int main() {
    int choice;
    string infix, expr;

    do {
        cout << "\nMenu:\n";
        cout << "1. Infix to Postfix\n2. Infix to Prefix\n3. Evaluate Postfix\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infix;
                cout << "Postfix: " << infixToPostfix(infix) << endl;
                break;
            case 2:
                cout << "Enter infix expression: ";
                cin >> infix;
                cout << "Prefix: " << infixToPrefix(infix) << endl;
                break;
            case 3:
                cout << "Enter postfix expression: ";
                cin >> expr;
                cout << "Result: " << evalPostfix(expr) << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}