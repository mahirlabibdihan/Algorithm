#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(NULL));
    int original = rand() % 32;
    cout << "Y=Correct Guess , N=Wrong Guess" << endl;
    for (int i = 0; i < 6; i++)
    {
        string guess;
        while (true)
        {
            cout << "Guess a 5 digit binary number: ";
            cin >> guess;
            if (guess.length() == 5)
            {
                break;
            }
            cout << "Invalid number!" << endl;
        }
        bool found = true;
        for (int j = 0; j < 5; j++)
        {
            if (guess[j] == '1')
            {
                if ((original & (1 << (5 - j - 1))) != 0)
                {

                    cout << 'Y';
                }
                else
                {
                    cout << 'N';
                    found = false;
                }
            }
            else
            {
                if ((original & (1 << (5 - j - 1))) == 0)
                {
                    cout << 'Y';
                }
                else
                {
                    cout << 'N';
                    found = false;
                }
            }
        }
        cout << endl;
        if (found)
        {
            cout << "Congrats" << endl;
            return 0;
        }
    }
    cout << "Failed" << endl;
}