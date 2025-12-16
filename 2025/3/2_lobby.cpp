#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int maxNumIndexWithinRange(int low, int high, string str){
    char maxNum = '0';
    int maxIndex = low;
    for(int i = low; i <= high; i++){
        if(str[i] - '0' > maxNum - '0'){
            maxNum = str[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main(){
    ifstream file("example_input.txt");
    ifstream file1("input.txt");
    string input = "";
    unsigned long long result = 0;
    string array="";
    while(getline(file1, input)){
        int startIndex = 0;
        for(int i = 0; i < 12; i++){
            startIndex = maxNumIndexWithinRange(startIndex, input.length()-12+i, input);
            array += input[startIndex];
            startIndex++;
        }
        cout<<array<<endl;
        result+=stoull(array);
        array = "";
    }
    cout<<result;
    return 0;
}
