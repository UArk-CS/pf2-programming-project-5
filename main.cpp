#include <iostream>
#include <fstream>
using namespace std;

//bool read_word(string &word, ifstream &din);
//void merge_sort(int *data, int *copy, int low, int high);

int main() {

    // Get file names
//    cout << "Enter name of input file: ";
//    string name1;
//    cin >> name1;

    // Open files
//    ifstream din;
//    din.open(name1.c_str());

    // Read and print words
//    string word;
//    while (read_word(word, din))
//        cout << word << endl;

    // Close files
//    din.close();

    //TODO: Get the name of input file

    //TODO: Open input file

    //TODO: Read 2 word phrases into an array

    return 0;

}

//bool read_word(string &word, ifstream &din) {
//    // Initialize variables
//    word = "";
//    bool found_word = false;
//
//    // Loop reading characters until word is found
//    while (!din.fail() && !din.eof() && !found_word)
//    {
//        // Read next character from file
//        char ch;
//        din.get(ch);
//
//        // Append lower case letter to word
//        if (ch >= 'a' && ch <= 'z')
//            word = word + ch;
//
//            // Convert upper case letter to lower case and append
//        else if (ch >= 'A' && ch <= 'Z')
//            word = word + char(ch - 'A' + 'a');
//
//            // Return word if length greater than zero
//        else if (word.length() > 0)
//            found_word = true;
//    }
//
//    // Return boolean flag
//    return found_word;
//}

//void merge_sort(int *data, int *copy, int low, int high) {
//    // Check terminating condition
//    int range = high - low + 1;
//    if (range > 1)
//    {
//        // Divide the array and sort both halves
//        int mid = (low + high) / 2;
//        merge_sort(data, copy, low, mid);
//        merge_sort(data, copy, mid + 1, high);
//
//        // Initialize array indices
//        int index1 = low;
//        int index2 = mid + 1;
//        int index = 0;
//
//        // Merge smallest data elements into copy array
//        while (index1 <= mid && index2 <= high)
//        {
//            if (data[index1] < data[index2])
//                copy[index++] = data[index1++];
//            else
//                copy[index++] = data[index2++];
//        }
//
//        // Copy any remaining entries from the first half
//        while (index1 <= mid)
//            copy[index++] = data[index1++];
//
//        // Copy any remaining entries from the second half
//        while (index2 <= high)
//            copy[index++] = data[index2++];
//
//        // Copy data back from the temporary array
//        for (index = 0; index < range; index++)
//            data[low + index] = copy[index];
//    }
//}