#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main(){
    ifstream file("example_input.txt");
    ifstream file1("input.txt");
    vector<pair<unsigned long long,unsigned long long>> ranges;
    string input;
    bool isValue = false;
    unsigned long long freshIngredients = 0;
    while(getline(file1, input)){
        cout<<input<<endl;
        if(input == ""){
            isValue = true;
            continue;
        }
        if(!isValue){
            unsigned long long low = stoull(input.substr(0, input.find('-')));
            unsigned long long high = stoull(input.substr(input.find('-')+1, input.length()));
            ranges.emplace_back(low, high);
        } else{
            for(const auto& iter: ranges){
                if(stoull(input) >= iter.first && stoull(input) <= iter.second){
                    freshIngredients++;
                    break;
                }
            }
        }
    }
    cout<<freshIngredients;
}
