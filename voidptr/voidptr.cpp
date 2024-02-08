
#include <iostream>

using namespace std;

enum class Type {
    INT,
    FLOAT,
    CSTRING,
    STRING
};

void printValue(void* ptr, Type t) {
    switch (t)
    {
    case Type::INT:
        cout << *static_cast<int*>(ptr) << endl;
        break;
    case Type::FLOAT:
        cout << *static_cast<float*>(ptr) << endl;
        break;
    case Type::CSTRING: // we don't open c-style string because char* is already interpreted as string; if we open it, then only first element will be printed
        cout << static_cast<char*>(ptr) << endl; 
        break;
    case Type::STRING:
        cout << *static_cast<string*>(ptr) << endl;
        break;
    }
}

int main()
{
    int val1 = 6;
    float val2 = 7.8;
    char val3[] = "Margin";
    string val4 = "C++ string";

    printValue(&val1, Type::INT);
    printValue(&val2, Type::FLOAT);
    printValue(&val3, Type::CSTRING);
    printValue(&val4, Type::STRING);
    return 0;
}
