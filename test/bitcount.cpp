#include<iostream>
using namespace std;

int count(int x)
{
    int count = 0;
    while (x)
    {
        count++;
        x = x & (x -1);
    }
    return count;
}

int main()
{
    cout << count(7) << endl;
    return 0;
}