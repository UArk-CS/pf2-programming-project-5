//
// Created by Ben Worthington on 4/4/21.
//

#include "PhraseFrequency.h"

PhraseFrequency::PhraseFrequency() {

    count = 0;

}

PhraseFrequency::PhraseFrequency(PhraseFrequency &copy_) {

    copy_.count = count;

}

PhraseFrequency::~PhraseFrequency() {

}

void PhraseFrequency::ReadFile(string &fileName_) {

    string wordOne, wordTwo;
    string phrase;

    ifstream din;
    din.open(fileName_);
    if (din.fail()) {
        return;
    }

    if (din.is_open()) {

        ReadWord(wordOne, din);

        while (!din.fail() && !din.eof()) {

            cout << "Count: " << count << endl;

            ReadWord(wordTwo, din);

            phrase = wordOne + " " + wordTwo;

            cout << "Word One: " << wordOne << endl;
            cout << "Word Two: " << wordTwo << endl;
            cout << "Phrase: " << phrase << endl;

            WriteToArray(phrase);

            wordOne = wordTwo;

        }

    }

    din.close();

}

void PhraseFrequency::WriteFile(string &fileName_) {

}

void PhraseFrequency::WriteToArray(string &phrase_) {

    if (count < MAX_PHRASE_COUNT) {

        twoWordPhrases[count] = phrase_;
        count++;

    }

}

bool PhraseFrequency::ReadWord(string &word_, ifstream &din_) {

    // Initialize variables
    word_ = "";
    bool found_word = false;

    // Loop reading characters until word_ is found
    while (!din_.fail() && !din_.eof() && !found_word)
    {
        // Read next character from file
        char ch;
        din_.get(ch);

        // Append lower case letter to word_
        if (ch >= 'a' && ch <= 'z')
            word_ = word_ + ch;

            // Convert upper case letter to lower case and append
        else if (ch >= 'A' && ch <= 'Z')
            word_ = word_ + char(ch - 'A' + 'a');

            // Return word_ if length greater than zero
        else if (word_.length() > 0)
            found_word = true;
    }

    // Return boolean flag
    return found_word;

}

int PhraseFrequency::getCount() const {
    return count;
}

void PhraseFrequency::setCount(int count) {
    PhraseFrequency::count = count;
}

void PhraseFrequency::MergeSort(int low_, int high_) {

    // Check terminating condition
    int range = high_ - low_ + 1;
    if (range > 1)
    {
        // Divide the array and sort both halves
        int mid = (low_ + high_) / 2;
        MergeSort(low_, mid);
        MergeSort(mid + 1, high_);

        // Initialize array indices
        int index1 = low_;
        int index2 = mid + 1;
        int index = 0;

        // Merge smallest twoWordPhrases elements into sortedTwoWordPhrases array
        while (index1 <= mid && index2 <= high_)
        {
            if (twoWordPhrases[index1] < twoWordPhrases[index2])
                sortedTwoWordPhrases[index++] = twoWordPhrases[index1++];
            else
                sortedTwoWordPhrases[index++] = twoWordPhrases[index2++];
        }

        // Copy any remaining entries from the first half
        while (index1 <= mid)
            sortedTwoWordPhrases[index++] = twoWordPhrases[index1++];

        // Copy any remaining entries from the second half
        while (index2 <= high_)
            sortedTwoWordPhrases[index++] = twoWordPhrases[index2++];

        // Copy twoWordPhrases back from the temporary array
        for (index = 0; index < range; index++)
            twoWordPhrases[low_ + index] = sortedTwoWordPhrases[index];
    }

}