#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    // input.c & output.c in the same directory where project is
    ifstream in("input.c");
    ofstream out("output.c");

    if (!in.is_open()) {
        cerr << "Error while opening input file" << endl;
        return 1;
    }

    if (!out.is_open()) {
        cerr << "Error while opening output file" << endl;
        in.close();
        return 1;
    }

    char prevChar, currentChar;
    prevChar = in.get();
    currentChar = in.get();

    while (in.good()) {
        if (prevChar == '/' && currentChar == '*') {
            cout << prevChar << currentChar;
            while (!(prevChar == '*' && currentChar == '/')) {
                prevChar = currentChar;
                currentChar = in.get();
                cout << currentChar;
            }
            prevChar = in.get();
            currentChar = in.get();
            cout<< endl << endl;
        } else {
            out.put(prevChar);
            prevChar = currentChar;
            currentChar = in.get();
        }
    }

    if (in.good())
        out.put(prevChar);

    in.close();
    out.close();

    return 0;
}
