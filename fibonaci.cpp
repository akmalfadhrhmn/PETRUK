#include <iostream>
#include <chrono>
#include <unordered_map>
#include <vector>

using namespace std;


unordered_map<int, int> memo;
int fibonacciRecursiveMemo(int n) {
    if (n <= 1) {
        return n;
    }
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    memo[n] = fibonacciRecursiveMemo(n - 1) + fibonacciRecursiveMemo(n - 2);
    return memo[n];
}


int fibonacciDP(int n) {
    if (n <= 1) {
        return n;
    }
    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

void measureTime(int n) {
    auto start = chrono::high_resolution_clock::now();
    fibonacciRecursiveMemo(n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, micro> duration = end - start;
    cout << "Fibonacci Rekursif dengan Memoization (" << n << ") Time: " << duration.count() << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    fibonacciDP(n);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Fibonacci DP (" << n << ") Time: " << duration.count() << " microseconds" << endl;
}

int main() {
    int testCases[] = {10, 25, 30, 40, 50};
    for (int n : testCases) {
        measureTime(n);
    }
    return 0;
}
