#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    ifstream file("input.txt");
    ifstream file2("example_input.txt");
    string line;
    vector<vector<unsigned long long>> input;
    int maxIndex = 0, maxColumnIndex = 0;
    unsigned long long result = 0, maxColumnSize[5000] = {};
    string indivudualColumnStr[5000] = {};
    string symbolsStr;
    int lineCount = 0;
    while(getline(file, line)){
        lineCount++;
        int index = 0;
        int columnIndex = 0;
        unsigned long long number = 0;
        string numberStr = "";
        bool isSymLine = false;
        for(int i = 0; i < line.length(); i++){
            if(line[i] == '*' || line[i] == '+' || isSymLine){
                isSymLine = true;
                if(line[i] == '*' || line[i] == '+'){
                    symbolsStr+=line[i];
                }
            } else {
                if(line[i] == ' '){
                    if(numberStr.length()){
                        if(maxColumnSize[columnIndex] < numberStr.length()){
                            maxColumnSize[columnIndex] = numberStr.length();
                        }
                        columnIndex++;
                        numberStr = "";
                    }
                    index++;
                } else {
                    numberStr+=line[i];
                    string numberStr(1, line[i]);
                    indivudualColumnStr[index]+=(numberStr);
                    index++;
                }
            }
        }
        if(numberStr.length()){
            if(maxColumnSize[columnIndex] < numberStr.length()){
                maxColumnSize[columnIndex] = numberStr.length();
            }
            columnIndex++;
            numberStr = "";
        }
        if(maxColumnIndex < columnIndex){
            maxColumnIndex = columnIndex;
        }
        if(index > maxIndex){
            maxIndex = index;
        }
    }
    int lastIndex = 0;
    for(int i = 0; i < symbolsStr.length(); i++){
        int count = 0;
        unsigned long long sum = 0, multiply = 1;
        for(int j = lastIndex; j < maxIndex; j++){
            if(indivudualColumnStr[j].length() <= 0){
                continue;
            }
            if(symbolsStr[i] == '+'){
                sum+=stoull(indivudualColumnStr[j]);
            }
            if(symbolsStr[i] == '*'){
                multiply*=stoull(indivudualColumnStr[j]);
            }
            count++;
            if(maxColumnSize[i] == count){
                if(symbolsStr[i] == '+'){
                    result+= sum;   
                } else {
                    result+=multiply;
                }
                lastIndex = ++j;
                break;
            }
        }
    }
    cout<<result;
    return 0;
}