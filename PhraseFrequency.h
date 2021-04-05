//
// Created by Ben Worthington on 4/4/21.
//

#ifndef PF2_PROGRAMMING_PROJECT_5_PHRASEFREQUENCY_H
#define PF2_PROGRAMMING_PROJECT_5_PHRASEFREQUENCY_H

int const MAX_PHRASE_COUNT = 70000;

#include <iostream>
#include <fstream>
using namespace std;

class PhraseFrequency {
public:
    PhraseFrequency();
    PhraseFrequency(PhraseFrequency &copy_);
    ~PhraseFrequency();
    void ReadFile(string &fileName_);
    void WriteFile(string &fileName_);
    bool ReadWord(string &word_, ifstream din_);
    void MergeSort(int *data_, int *copy_, int low, int high);

private:
    string twoWordPhrases[MAX_PHRASE_COUNT];
    int count;
};


#endif //PF2_PROGRAMMING_PROJECT_5_PHRASEFREQUENCY_H
