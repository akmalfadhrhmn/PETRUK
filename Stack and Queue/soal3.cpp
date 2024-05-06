#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> q;
    string command;
    int element;

    for (int i = 0; i < N; ++i) {
        cin >> command;
        if (command == "push") {
            cin >> element;
            q.push(element);
        } else if (command == "pop") {
            if (!q.empty()) {
                q.pop();
            }
        }

        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    return 0;
}
