#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// This solution uses recursion to print all the timelines.
// This approach takes a lot of time. So this is not feasible.
// Solution is at 2_laboratories.cpp

// recursive function that follows left first and the right
void input_traverse(vector<string> input, int index, vector<string> input_copy){
    static int count = 0;
    if(index == input.size()){
        count++;
        for(const auto& element : input){
            cout<<element<<endl;
        }
        input = input_copy;
        cout<<"Result "<<count<<endl;
        return;
    }
    static int position = -1;
    int size = input.size();
    int i = 0;
    string line = input.at(index);
    for(int i = 0; i < line.length(); i++){
        if(line[i] == 'S'){
            position = i;
            input_traverse(input, index+1, input_copy);
        }
        else if(position == i && line[i] == '^'){
            line[i-1] = '|';
            input[index] = line;
            position = i-1;
            input_traverse(input, index+1, input_copy);
            line[i-1] = '.';
            line[i+1] = '|';
            position = i+1;
            input[index] = line;
            input_traverse(input, index+1, input_copy);
        }
        else if(position == i && line[i] == '.'){
            line[i] = '|';
            position = i;
            input[index] = line;
            input_traverse(input, index+1, input_copy);
            line[i] = '.';
            position = i;
            input[index] = line;
        }
    }
}

int main(){
    ifstream file2("example_input.txt");
    string line;
    vector<string> input = {};
    int i = 0;
    while(getline(file2, line)){
        cout<<line<<endl;
        input.push_back(line);
    }
    input_traverse(input, 0, input);
    return 0;
}
