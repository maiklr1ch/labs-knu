#include <iostream>

using namespace std;

int main()
{
    float x, y, a, b, k, m;

    cout << "A(X,y) enter x: ";
    cin >> x;

    cout << "A(x,Y) enter y: ";
    cin >> y;

    cout << "enter a: ";
    cin >> a;

    cout << "enter b: ";
    cin >> b;

    if(!a)
    {
        k = 1/x;
        m = 0;
    }
    else if(!b)
    {
        k = 0;
        m = 1/y;
    }
    else
    {
        float c;
        c = y-b*x/a;
        k = -b/(a*c);
        m = 1/c;
    }

    if(!k) cout << m << "y = 1" << endl;
    else if(m < 0) cout << k << "x - " << -m << "y = 1" << endl;
    else if(!m) cout << k << "x = 1" << endl;
    else cout << k << "x + " << m << "y = 1" << endl;

    return 0;
}
