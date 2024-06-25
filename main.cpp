#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int fibonacci_recursive(int n)
{
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int fibonacci_dynamic(int n)
{
    if (n <= 1)
        return n;
    int *fib = new int[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int result = fib[n];
    delete[] fib;
    return result;
}

int main()
{
    int values[] = {50};

    cout << "n\trecursive (ms)\tdynamic (ms)" << endl;
    for (int n : values)
    {
        auto start = high_resolution_clock::now();
        fibonacci_recursive(n);
        auto end = high_resolution_clock::now();
        auto duration_recursive = duration_cast<microseconds>(end - start).count();

        start = high_resolution_clock::now();
        fibonacci_dynamic(n);
        end = high_resolution_clock::now();
        auto duration_dynamic = duration_cast<microseconds>(end - start).count();

        cout << n << "\t" << duration_recursive << "\t\t" << duration_dynamic << endl;
    }

    return 0;
}
