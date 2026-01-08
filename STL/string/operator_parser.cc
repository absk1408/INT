#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int evaluateExpression(string s) {
    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < s.length(); i++) {

        // Ignore spaces
        if (s[i] == ' ') continue;

        // Number
        if (isdigit(s[i])) {
            int val = 0;
            while (i < s.length() && isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            values.push(val);
            i--; // compensate for loop increment
        }

        // Opening bracket
        else if (s[i] == '(') {
            ops.push(s[i]);
        }

        // Closing bracket
        else if (s[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(a, b, op));
            }
            ops.pop(); // remove '('
        }

        // Operator
        else {
            while (!ops.empty() &&
                   precedence(ops.top()) >= precedence(s[i])) {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(a, b, op));
            }
            ops.push(s[i]);
        }
    }

    // Final evaluation
    while (!ops.empty()) {
        int b = values.top(); values.pop();
        int a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(a, b, op));
    }

    return values.top();
}

int main() {
    string expr = " ((3 + 5))";
    cout << evaluateExpression(expr) << endl;
    return 0;
}
