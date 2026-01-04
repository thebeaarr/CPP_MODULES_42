#include <iostream>

class IntArray
{
private:
    int data[5];

public:
    IntArray()
    {
        for (int i = 0; i < 5; ++i)
            data[i] = 0;
    }

    // non-const version (allows modification)
    int& operator[](int index)
    {
        return data[index];
    }

    // const version (read-only access)
    const int& operator[](int index) const
    {
        return data[index];
    }
};

int main()
{
    IntArray a;
    a[2] = 42;                 // OK

    const IntArray b = a;
    std::cout << b[2] << '\n'; // OK

    return 0;
}