#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include "C:\Users\natha\CLionProjects\WordCommonality\cmake-build-debug\grammerRemover.h"
using namespace std;
int main() {
    map<string, int> words;
    vector<string> keys;
    vector<int> currMax = {0};
    vector<string> arg = {" "};
    string inFilePath = "C:\\Users\\natha\\CLionProjects\\WordCommonality\\textForInput.txt";
    string outFilePath = "C:\\Users\\natha\\CLionProjects\\WordCommonality\\exportedData.csv";
    string test;
    ifstream inputFile;
    inputFile.open(inFilePath);

        if (!inputFile.fail()) {
            while (inputFile >> test){
                string word = grammerGone(test);
                remove_if(word.begin(),word.end(),isspace);
                if (word != " ") {
                    words[word] += 1;
                    if (words[word] == 1) {
                        keys.push_back(word);
                    }
                }
            }
        } else cout << "fail" << endl;
        cout << "____________" << endl;
    for (auto i = 0; i < keys.size(); ++i) {
        currMax.push_back(words[keys[i]]);
        arg.push_back(keys[i]);
    }
    // and the other for comparison

    //Now we will sort the array
    for(int i= 0;i < currMax.size()-1;i++)
    {
        for(int j=0;j<currMax.size()-i-1;j++)
        {
            //checking if previous value is
            //grater than next one or not
            if(currMax[j]>currMax[j+1])
            {
                //temp will temporarly store
                //the value of arr[j]
                //then we will swap the values
                int temp=currMax[j];
                string temp2 = arg[j];
                currMax[j]=currMax[j+1];
                 arg[j]=arg[j+1];
                currMax[j+1]=temp;
                arg[j+1]=temp2;
            }
        }
    }
    cout << arg.size() <<" " << currMax.size() << endl;
    for (int i = 0; i < arg.size(); ++i) {

            cout << arg[i] << "=" << currMax[i] << endl;
        }
    inputFile.close();
    ofstream outputFile;
    outputFile.open(outFilePath);
    outputFile << "Data From Text\n";
    outputFile << "word,count\n";
    for (int i = 0; i < arg.size(); ++i) {

        outputFile << arg[i] + ","  + to_string(currMax[i]) + "\n";
    }
    return 0;
}
