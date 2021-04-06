#include <iostream>
#include <fstream>
#include "PhraseFrequency.h"
using namespace std;

int main() {

    PhraseFrequency pf;
    string fileName = "TreasureIsland.txt";
    string output = "output.txt";

    pf.ReadFile(fileName);
    pf.MergeSort(0, pf.getCount() - 1);
//    pf.Print();

    clock_t time1=clock();
    pf.CountFrequency(output);
    clock_t time2=clock();
    double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
    cout << "Count Frequency took " << run_time << " seconds." << endl;

    return 0;

}