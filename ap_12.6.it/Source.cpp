#include <iostream>
#include <queue>

using namespace std;

void printNumbersWithPrimeFactors(int n) {
    queue<int> q2, q3, q5;
    q2.push(2);
    q3.push(3);
    q5.push(5);

    int nextNumber = 1;

    for (int i = 0; i < n; ++i) {
        nextNumber = min(q2.front(), min(q3.front(), q5.front()));
        cout << nextNumber << " ";

        if (nextNumber == q2.front()) {
            q2.pop();
            q2.push(nextNumber * 2);
            q3.push(nextNumber * 3);
        }
        else if (nextNumber == q3.front()) {
            q3.pop();
            q3.push(nextNumber * 3);
        }
        else {
            q5.pop();
            q2.push(nextNumber * 2);
            q3.push(nextNumber * 3);
            q5.push(nextNumber * 5);
        }
    }
}

    int main()
    {
        int n;
        cout << "Enter the value of n: ";
        cin >> n;

        cout << "The first " << n << " numbers with prime factors 2, 3, 5 are:" << endl;
        printNumbersWithPrimeFactors(n);
        cout << endl;

        return 0;
    }
