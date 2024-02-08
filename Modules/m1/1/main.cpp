#include <iostream>
#include <cmath>

using namespace std;

int getDividersSum(int n)
{
    int sum = 0;
    for(int i = 2; i <= n; i++)
        if(n%i == 0 && ((int)sqrt(i)) == sqrt(i))
            sum += i;
    return sum;
}

int main()
{
    int n;
    cout << "enter n: ";
    cin >> n;

    cout << "sum is: " << getDividersSum(n) << endl;
    return 0;
}
