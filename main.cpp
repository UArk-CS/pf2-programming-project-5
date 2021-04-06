#include <iostream>
#include "PhraseFrequency.h"
using namespace std;

int main() {

    PhraseFrequency pf;
    string bookName;
    string outputFileName;

    cout << "Welcome to the Phrase Frequency Calculator" << endl;
    cout << endl;

    cout << "Enter the name of the book (with .txt extension): > ";
    cin >> bookName;
    cout << endl;

    cout << "Enter the name of the output file (with .txt extension): > ";
    cin >> outputFileName;
    cout << endl;

    clock_t time1 = clock();
    cout << "Extracting two word phrases from book..." << endl;
    pf.ReadFile(bookName);
    clock_t time2=clock();
    double readingRunTime = (time2-time1)/(double)CLOCKS_PER_SEC;
    cout << "Extraction complete." << endl;
    cout << endl;

    time1 = clock();
    cout << "Sorting phrases with Merge Sort..." << endl;
    pf.MergeSort(0, pf.getCount() - 1);
    time2=clock();
    double sortingRunTime = (time2-time1)/(double)CLOCKS_PER_SEC;
    cout << "Sorting complete." << endl;
    cout << endl;

    time1=clock();
    cout << "Calculating Frequency of phrases..." << endl;
    pf.CountFrequency(outputFileName);
    time2=clock();
    double frequencyRunTime = (time2-time1)/(double)CLOCKS_PER_SEC;
    cout << "Frequency calculation complete." << endl;
    cout << endl;

    cout << "Extraction Run Time: " << readingRunTime << " seconds." << endl;
    cout << "Sorting Run Time: " << sortingRunTime << " seconds." << endl;
    cout << "Frequency Run Time: " << frequencyRunTime << " seconds. " << endl;

    return 0;

}