//
// Created by Ben Worthington on 4/4/21.
//

#ifndef PF2_PROGRAMMING_PROJECT_5_PHRASEFREQUENCY_H
#define PF2_PROGRAMMING_PROJECT_5_PHRASEFREQUENCY_H

int const MAX_PHRASE_COUNT = 70500;

#include <iostream>
#include <fstream>
using namespace std;

class PhraseFrequency {
public:
    PhraseFrequency();
    ~PhraseFrequency();
    int getCount() const;
    void setCount(int count);
    void ReadFile(string &fileName_);
    void WriteFile(string &fileName_, int &frequency_, string &phrase_);
    void WriteToArray(string &phrase_);
    bool ReadWord(string &word_, ifstream &din_);
    void MergeSort(int low_, int high_);
    void CountFrequency(string &fileName_);
    void Print();

private:
    string *twoWordPhrases;
    string *copyTwoWordPhrases;
    int count;
};


#endif //PF2_PROGRAMMING_PROJECT_5_PHRASEFREQUENCY_H
