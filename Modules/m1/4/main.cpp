#include <iostream>

using namespace std;

int main()
{
    char in[200];
    cout << "enter string: ";
    cin >> in;

    for(int i = 200; i > -1; i--)
    {
        bool isPalindrome = false;
        if(in[0] == in[i])
            for(int j = 1; j <= i/2; j++)
            {
                isPalindrome = true;
                if(in[j] != in[i-j]) {
                    isPalindrome = false;
                    break;
                }
            }

        if(isPalindrome) break;
        else in[i] = ' ';
    }

    cout << in;
    return 0;
}
