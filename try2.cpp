#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int range = 0;
    int num = 0;
    int i = 0;

    cout <<"Enter range of numbers: ";
    cin >> range;
    cout <<"Enter" <<range << " consecutive numbers:" ;
    while (i!=range)
    {

        cin >> num;
        i++;

        if (num%2==0)
        {
            cout << num << " Even \n";
        }
        else 
        {
            cout << num << " Odd \n";
        }

    }


    return 0;
}