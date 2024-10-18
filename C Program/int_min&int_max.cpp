// C++ program to print values of INT_MAX
// and INT_MIN
#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    cout << INT_MAX << endl;
    cout << INT_MIN;
    return 0;
}

Output
2147483647
-2147483648
Applications of INT_MAX and INT_MIN
Following are the major applications of INT_MAX and INT_MIN

1. Check for Integer Overflow
We can use the INT_MIN and INT_MAX macros to check for the signed integer overflow. The example below demonstrate how to do it.

Example





// C++ code to check for Integer overflow while
// adding 2 numbers
#include <climits>
#include <iostream>
using namespace std;

// Function to return integer sum after checking overflow
int check_overflow(int num1, int num2)
{
    // Checking if addition will cause overflow
    if (num1 > INT_MAX - num2)
        return -1;

    // No overflow occurred
    else
        return num1 + num2;
}

// Driver code
int main()
{
    // The sum of these numbers will equal INT_MAX
    // If any of them is incremented by 1, overflow
    // will occur
    int num1 = 2147483627;
    int num2 = 20;

    // Result is -1 if overflow occurred
    // Stores the sum, otherwise
    int result = check_overflow(num1, num2);

    // Overflow occurred
    if (result == -1)
        cout << "Integer overflow occurred";

    // No overflow
    else
        cout << result;

    return 0;
}
