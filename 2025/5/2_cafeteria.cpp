#include <fstream>
#include <iostream>
#include <limits.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void countExistingRanges(long long *existingCount, long long low, long long high, long long n_low, long long n_high, vector<pair<long long, long long>> &ranges){
    long long n_low_r = n_low, n_high_r = n_high;
    int i = 0;
    bool add = true;
    while(true){
        if(i > ranges.size()-1 && ranges.size()){
            break;
        }
        if(ranges[i].first <= n_low && ranges[i].second >= n_high){
            *existingCount-=(n_high-n_low+1);
            add = false;
            i++;
            break;
        } else {
            if(n_low >= ranges[i].first & n_low <= ranges[i].second){
                *existingCount-=(ranges[i].second-n_low+1);
                n_low_r = ranges[i].first;
                ranges.erase(ranges.begin()+i);
                if(ranges.size() == 0){
                    break;
                }
            } else if(n_high>=ranges[i].first && n_high <=ranges[i].second){
                *existingCount-=(n_high-ranges[i].first+1);
                n_high_r = ranges[i].first-1;
                i++;
            } else{
                if(ranges[i].first >= n_low && ranges[i].second <= n_high){
                    *existingCount-=(ranges[i].second-ranges[i].first+1);
                    ranges.erase(ranges.begin()+i);
                    if(ranges.size()== 0){
                        break;
                    }
                } else{
                    i++;
                }
            }
        }
    }
    if(add){
        ranges.emplace_back(n_low_r, n_high_r);
    }
}

int main(){
    ifstream file("example_input.txt");
    ifstream file1("input.txt");
    vector<pair<long long, long long>> ranges;
    long long low = 0, high = 0;
    string input;
    bool isValue = false;
    long long freshIngredients = 0, existingCount = 0;
    while(getline(file1, input)){
        cout<<input<<endl;
        if(input == ""){
            break;
        }
        long long n_low = stoull(input.substr(0, input.find('-')));
        long long n_high = stoull(input.substr(input.find('-')+1, input.length()));
        existingCount = n_high - n_low + 1;
        if(high <= n_low){
            if(high == n_low){
                existingCount-=1;
            }
            ranges.emplace_back(n_low, n_high);
        } else if(n_high <= low){
            if(n_high == low){
                existingCount-=1;
            }
            ranges.emplace_back(n_low, n_high);
        } else {
            if(high <= n_high && low <= n_low){
                countExistingRanges(&existingCount, low, high, n_low, n_high, ranges);
            } else if(high <= n_high && low > n_low){
                countExistingRanges(&existingCount, low, high, n_low, n_high, ranges);
            } else if(high >= n_high && low <= n_low){
                countExistingRanges(&existingCount, low, high, n_low, n_high, ranges);
            } else if(high >= n_high && low > n_low){
                countExistingRanges(&existingCount, low, high, n_low, n_high, ranges);
            }
        }

        if(low == 0 && high == 0){
            low = n_low;
            high = n_high;
            freshIngredients = high - low + 1;
        } else {
            if(low > n_low){
                low = n_low;
            } else if(high < n_high) {
                high = n_high;
            }
            if(existingCount != 0 && existingCount > 0){
                freshIngredients+=existingCount;
            }
        }
    }
    cout<<freshIngredients;
}
