#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "enter n: ";
    cin >> n;

    for(int i = 20; i < n; i++)
        for(int k = 1; 13*k<i; k++)
            if((i-13*k)%7 == 0)
                cout << i << " ";
    return 0;
}
