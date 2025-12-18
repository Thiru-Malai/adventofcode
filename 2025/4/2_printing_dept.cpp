#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    ifstream file("example_input.txt");
    ifstream file1("input.txt");

    vector<vector<char>> input;
    string line;
    int result = 0, count = 0, itrCount = 0;
    while(getline(file1, line)){
        vector<char> str;
        for(int i = 0; i < line.length(); i++){
            str.push_back(line[i]);
        }
        input.push_back(str);
    }
    do{
        itrCount = 0;
        for(int i = 0; i < input.size(); i++){
            for(int j = 0; j < input[i].size(); j++){
                result = 0;
                if(input[i][j] != '@'){
                    continue;
                }
                if(i == 0 && j == 0){
                    if(input[i][j+1] == '@'){
                        result++;
                    }
                    if(input[i+1][j+1] == '@'){
                        result++;
                    }
                    if(input[i+1][j] == '@'){
                        result++;
                    }
                }
                else if(i == input.size()-1 && j == input[i].size()-1){
                    if(input[i][j-1] == '@'){
                        result++;
                    }
                    if(input[i-1][j-1] == '@'){
                        result++;
                    }
                    if(input[i-1][j] == '@'){
                        result++;
                    }
                }
                else if(i == input.size()-1 && j == 0){
                    if(input[i][j+1] == '@'){
                        result++;
                    }
                    if(input[i-1][j+1] == '@'){
                        result++;
                    }
                    if(input[i-1][j] == '@'){
                        result++;
                    }
                }
                else if(i == 0 && j == input[i].size()-1){
                    if(input[i][j+1] == '@'){
                        result++;
                    }
                    if(input[i+1][j-1] == '@'){
                        result++;
                    }
                    if(input[i-1][j] == '@'){
                        result++;
                    }
                }
                else if(j == 0 && (i != 0 && i != input.size()-1)){
                    if(input[i-1][j] == '@'){
                        result++;
                    }
                    if(input[i-1][j+1] == '@'){
                        result++;
                    }
                    if(input[i][j+1] == '@'){
                        result++;
                    }
                    if(input[i+1][j+1] == '@'){
                        result++;
                    }
                    if(input[i+1][j] == '@'){
                        result++;
                    }
                }
                else if(j == input[i].size()-1 && (i != 0 && i != input.size()-1)){
                    if(input[i-1][j] == '@'){
                        result++;
                    }
                    if(input[i-1][j-1] == '@'){
                        result++;
                    }
                    if(input[i][j-1] == '@'){
                        result++;
                    }
                    if(input[i+1][j-1] == '@'){
                        result++;
                    }
                    if(input[i+1][j] == '@'){
                        result++;
                    }
                }
                else if(i == 0 && (j != 0 && j != input[i].size()-1)){
                    if(input[i][j-1] == '@'){
                        result++;
                    }
                    if(input[i+1][j-1] == '@'){
                        result++;
                    }
                    if(input[i+1][j] == '@'){
                        result++;
                    }
                    if(input[i+1][j+1] == '@'){
                        result++;
                    }
                    if(input[i][j+1] == '@'){
                        result++;
                    }
                }
                else if(i == input.size()-1 && (j != 0 && j != input[i].size()-1)){
                    if(input[i][j-1] == '@'){
                        result++;
                    }
                    if(input[i-1][j-1] == '@'){
                        result++;
                    }
                    if(input[i-1][j] == '@'){
                        result++;
                    }
                    if(input[i-1][j+1] == '@'){
                        result++;
                    }
                    if(input[i][j+1] == '@'){
                        result++;
                    }
                }
                else{
                    if(input[i-1][j-1] == '@'){
                        result++;
                    }
                    if(input[i-1][j] == '@'){
                        result++;
                    }
                    if(input[i-1][j+1] == '@'){
                        result++;
                    }
                    if(input[i][j+1] == '@'){
                        result++;
                    }
                    if(input[i+1][j+1] == '@'){
                        result++;
                    }
                    if(input[i+1][j] == '@'){
                        result++;
                    }
                    if(input[i+1][j-1] == '@'){
                        result++;
                    }
                    if(input[i][j-1] == '@'){
                        result++;
                    }
                }
                if(result <= 3){
                    count++;
                    input[i][j] = 'X';
                    itrCount++;
                }
            }
        }
        if(itrCount == 0){
            break;
        }
    } while(true);
    cout<<count;
}
