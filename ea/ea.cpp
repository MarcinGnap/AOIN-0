#include <iostream>
#include "Loader.h"

using namespace std;

int main()
{
    short mainMenuChoice;
    Loader loader;

    for (;;)
    {
        //system("CLS");
        cout << "Hi,\nThis is task 0 for Nature-inspired ptimization algorithms.\n\nChoose what you want to do:\n";
        cout << "1. Load instance from .ini file.\n"
            "2. Create new random instance. (in progress)\n"
            "3. Exit.\n";

        cin >> mainMenuChoice;

        switch (mainMenuChoice)
        {
            case 1:
            {
                loader.OpenIni();
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                exit(0);
                break;
            }
            default:
            {
                cout << "There is no way I can do that. \nPlease choose again.\n";
                break;
            }
        }
    }

    return 0;
}
