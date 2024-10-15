#include <iostream>
#include "Loader.h"
#include "EvoAlg.h"
#include "AdjacencyMatrix.h"

using namespace std;

int main()
{
    short mainMenuChoice;
    Loader loader;
    EvoAlg evoalg;

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
                loader.openIni();
                loader.openTSPFile(loader.fileName);
                break;
            }
            case 2:
            {
                int generatedVertices, maxValue;
                cout << "How many vertices should be in the instance <2 - X>?\n";
                cin >> generatedVertices;
                cout << "What should be the maximum value of X and Y? <2 - Y>?\n";
                cin >> maxValue;
                loader.createRandomGraph(generatedVertices, maxValue);
                AdjacencyMatrix adjacencymatrix(generatedVertices, loader.verticesGraph);
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
