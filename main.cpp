#include <iostream>

using namespace std;

int main() {

    //program 1 guide
    //optimized profit = 50c + 10h + 20g (c = coat, h = hat, g = gloves)
    //simplify to just hats and coats & leather and fabric

    //Leather variables
    double yardsOfLeatherPerCoat{1};
    double yardsOfLeatherPerHat{0.5};
    double yardsOfLeatherPerGloves{0.25};

    //fabric variables
    double yardsOfFabricPerCoat{0.5};
    double yardsOfFabricPerHat{0.25};
    double yardsOfFabricPerGloves{0.25};

    //thread variables
    double yardsOfThreadPerCoat{5};
    double yardsOfThreadPerHat{2.5};
    double yardsOfThreadPerGloves{7.5};

    //profit variables
    double profitPerHat{0};
    double profitPerCoat{0};
    double profitPerGloves{0};

    //starting amount variables
    double amountOfLeather{0};
    double amountOfFabric{0};
    double amountOfThread{0};
    //max profit var
    double maxProfit{0};

    //total hats, coats, gloves
    int totalAmountOfHats{0};
    int totalAmountOfCoats{0};
    int totalAmountOfGloves{0};

    //profit = profitPerCoat * i + profitPerHat * j;
    //amountOfLeather >= yardsOfLeatherPerCoat * i + yardsOfLeatherPerHat * j;
    //amountOfFabric >= yardsOfFabricPerCoat * i + yardsOfFabricPerHat;

    int h{0}; //number of hats
    int c{0}; //number of coats
    int g{0}; //number of gloves

    //iteration count check
    int iterationCount{0};

    //loop condition initialization
    char userInput;

    //welcome messsage
    cout << "Welcome to the Winter Apparel Manufacturing Optimizer!" << "\n" << endl;

    while (true) {
        //user inputs
        cout << "Profit per coat: ";
        cin >> profitPerCoat;
        cout << "Profit per hat: ";
        cin >> profitPerHat;
        cout << "Profit per pair of gloves: ";
        cin >> profitPerGloves;
        cout << "Yards of leather available: ";
        cin >> amountOfLeather;
        cout << "Yards of fabric available: ";
        cin >> amountOfFabric;
        cout << "Yards of thread available: ";
        cin >> amountOfThread;

        while (amountOfFabric >= yardsOfFabricPerCoat * c && amountOfLeather >= yardsOfLeatherPerCoat * c &&
               amountOfThread >= yardsOfThreadPerCoat * c) {//make coat?
            //need both leather and fabric so &&
            h = 0;
            while (amountOfLeather >= yardsOfLeatherPerCoat * c + yardsOfLeatherPerHat * h &&
                   amountOfFabric >= yardsOfFabricPerCoat * c + yardsOfFabricPerHat * h &&
                   amountOfThread >= yardsOfThreadPerCoat * c + yardsOfThreadPerHat * h) {//make coat + hat
                g = 0;
                double profit = profitPerHat * h + profitPerCoat * c;
                if (maxProfit <= profit) {
                    maxProfit = profit;
                    totalAmountOfHats = h;
                    totalAmountOfCoats = c;
                    totalAmountOfGloves = g;
                }
                //CLION formats long while loop conditions this way
                while (amountOfLeather >=
                       yardsOfLeatherPerCoat * c + yardsOfLeatherPerHat * h + yardsOfLeatherPerGloves * g &&
                       amountOfFabric >=
                       yardsOfFabricPerCoat * c + yardsOfFabricPerHat * h + yardsOfFabricPerGloves * g &&
                       amountOfThread >=
                       yardsOfThreadPerCoat * c + yardsOfThreadPerHat * h + yardsOfThreadPerGloves * g) {
                    profit = profitPerHat * h + profitPerCoat * c + profitPerGloves * g;
                    iterationCount++;
                    if (maxProfit <= profit) {
                        maxProfit = profit;
                        totalAmountOfHats = h;
                        totalAmountOfCoats = c;
                        totalAmountOfGloves = g;
                    }
                    g++;
                }
                h++;
            }
            c++;
        }

        //result screen variables
        double leatherUsed =
                (totalAmountOfGloves * yardsOfLeatherPerGloves) + (totalAmountOfCoats * yardsOfLeatherPerCoat) +
                (totalAmountOfHats * yardsOfLeatherPerHat);
        double leatherRemaining = leatherUsed - amountOfLeather;
        double fabricUsed =
                (totalAmountOfGloves * yardsOfFabricPerGloves) + (totalAmountOfCoats * yardsOfFabricPerCoat) +
                (totalAmountOfHats * yardsOfFabricPerHat);
        double fabricRemaining = fabricUsed - amountOfFabric;
        double threadUsed =
                (totalAmountOfGloves * yardsOfThreadPerGloves) + (totalAmountOfCoats * yardsOfThreadPerCoat) +
                (totalAmountOfHats * yardsOfThreadPerHat);
        double threadRemaining = threadUsed - amountOfThread;

        //ending result screen
        cout << "\n" << "Optimal Mix:" << endl;
        cout << "    " << "Coats: " << totalAmountOfCoats << endl;
        cout << "    " << "Hats: " << totalAmountOfHats << endl;
        cout << "    " << "Gloves: " << totalAmountOfGloves << endl;
        cout << "    " << "Profit: " << maxProfit << endl;
        cout << "    " << "Leather used / remaining: " << leatherUsed << " / " << leatherRemaining << endl;
        cout << "    " << "Fabric used / remaining: " << fabricUsed << " / " << fabricRemaining << endl;
        cout << "    " << "Thread used / remaining: " << threadUsed << " / " << threadRemaining << endl;
        cout << "    " << "Iterations: " << iterationCount << endl;
        cout << "\n" << "Would you like to continue (Y/y or N/n): ";
        cin >> userInput;
        if (userInput == 'n' || userInput == 'N')
            break;

    }

    return 0;
}