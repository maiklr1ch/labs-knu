#include <iostream>

using namespace std;

int fact(int i)
{
    if(i<2) return 1;
    return i * fact(i-1);
}

int main()
{
    // 1/0! - 2/1! + 3/2! - 4/3! + 5/4! - ...
    // 1 - 2 + 1.5 - 0.66 + 5/24 - 6/120 + 7/720 + ...

    float sum = 0;
    for(int i = 0; i<20;i++){
        int k = 1;
        if(i%2) k=-1;
        sum += k*(i+1)/fact(i);
    }
    cout << sum;
    return 0;
}
