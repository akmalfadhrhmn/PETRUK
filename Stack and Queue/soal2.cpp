#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> s;
    string command;
    int element;

    for (int i = 0; i < N; ++i) {
        cin >> command;
        if (command == "push") {
            cin >> element;
            s.push(element);
        } else if (command == "pop") {
            if (!s.empty()) {
                s.pop();
            }
        }

        stack<int> temp = s;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    return 0;
}