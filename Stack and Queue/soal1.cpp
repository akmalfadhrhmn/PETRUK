#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int array[N];
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
   for (int i = 0; i < N; i++) {
        if (i % 2 == 1) {
            cout << array[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
