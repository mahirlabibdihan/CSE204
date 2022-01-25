#include <iostream>
using namespace std;

void f(int (&arr)[100])
{
    cout << sizeof(arr) / sizeof(arr[0]) << endl;
}
int main()
{
    int arr[100];
    f(arr);
}