#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
    ifstream file("example_input.txt");
    ifstream file1("input.txt");
    string input = "";
    int result = 0;
    while(getline(file1, input)){
        char firstMaxValue = input[0], secondMaxValue;
        if(input[1]){
            secondMaxValue = input[1];
        }
        for(int i = 1; i < input.length()-1; i++){
            if(input[i] - '0' > firstMaxValue - '0'){
                firstMaxValue = input[i];
                secondMaxValue = input[i+1];
            }
            else if(input[i+1] - '0' > secondMaxValue - '0'){
                secondMaxValue = input[i+1];
            }
        }
        if(input[input.length()-1] - '0' > secondMaxValue - '0'){
            secondMaxValue = input[input.length()-1];
        }
        cout<<input<< " " << firstMaxValue<<" "<<secondMaxValue<<endl;
        result+=stoi(to_string(firstMaxValue - '0')+to_string(secondMaxValue - '0'));
    }
    cout<<result;
    return 0;
}
