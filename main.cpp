#include <iostream>
#include <fstream>
#include "PhraseFrequency.h"
using namespace std;

int main() {

    PhraseFrequency pf;
    string fileName = "TreasureIsland.txt";

    pf.ReadFile(fileName);
    pf.MergeSort(0, pf.getCount() - 1);

    return 0;

}