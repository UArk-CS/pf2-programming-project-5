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

}

void PhraseFrequency::WriteFile(string &fileName_) {

}

bool PhraseFrequency::ReadWord(string &word_, ifstream din_) {

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

void PhraseFrequency::MergeSort(int *data_, int *copy_, int low_, int high_) {

    // Check terminating condition
    int range = high_ - low_ + 1;
    if (range > 1)
    {
        // Divide the array and sort both halves
        int mid = (low_ + high_) / 2;
        MergeSort(data_, copy_, low_, mid);
        MergeSort(data_, copy_, mid + 1, high_);

        // Initialize array indices
        int index1 = low_;
        int index2 = mid + 1;
        int index = 0;

        // Merge smallest data_ elements into copy_ array
        while (index1 <= mid && index2 <= high_)
        {
            if (data_[index1] < data_[index2])
                copy_[index++] = data_[index1++];
            else
                copy_[index++] = data_[index2++];
        }

        // Copy any remaining entries from the first half
        while (index1 <= mid)
            copy_[index++] = data_[index1++];

        // Copy any remaining entries from the second half
        while (index2 <= high_)
            copy_[index++] = data_[index2++];

        // Copy data_ back from the temporary array
        for (index = 0; index < range; index++)
            data_[low_ + index] = copy_[index];
    }

}