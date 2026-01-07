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
    int maxIndex = 0;
    unsigned long long result = 0;
    unsigned long long sumOfColumn[1000] = {}, multiplyOfColumn[1000] = {1};
    for(int i = 0; i < 1000; i++){
        multiplyOfColumn[i] = 1;
    }
    while(getline(file, line)){
        vector<unsigned long long> lineInput;
        int index = 0;
        unsigned long long number = 0;
        string numberStr = "";
        for(int i = 0; i < line.length(); i++){
            if(line[i] == '*' || line[i] == '+'){
                if(line[i] == '*'){
                    result+=multiplyOfColumn[index];
                } else{
                    result+=sumOfColumn[index];
                }
                index++;
            }
            else if(line[i] != ' '){
                numberStr+=line[i];
            }
            else if(line[i] == ' '){
                if(numberStr.length()){
                    number = stoull(numberStr);
                    lineInput.push_back(number);
                    sumOfColumn[index]+=number;
                    multiplyOfColumn[index]*=number;
                    index++;
                    numberStr = "";                    
                }
            }
        }
        if(numberStr.length()){
            number = stoull(numberStr);
            lineInput.push_back(number);
            sumOfColumn[index]+=number;
            multiplyOfColumn[index]*=number;
            index++;
            numberStr = "";    
        }
        if(index > maxIndex){
            maxIndex = index;
        }
        input.push_back(lineInput);
    }
    cout<<result;
    return 0;
}