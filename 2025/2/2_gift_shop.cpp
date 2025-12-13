#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void check_repeated(string str, unsigned long long *result){
    string temp = str;
    for(int i = 1; i <= str.length()/2; i++){
        string current = str.substr(0, i);
        str.erase(0, i);
        do {
            string new_str = str.substr(0, i);
            if(current != new_str){
                break;
            }
            str.erase(0, i);
            if(str.length() == 0){
                *result = *result + stoull(temp);
                return;
            }
        } while(str.length());
        str = temp;
    }
}

int main(){
    ifstream file("input.txt");
    ifstream file1("example_input.txt");

    string input, lower_limit, upper_limit;
    int pos;
    unsigned long long total = 0, lower_limit_no, upper_limit_no;
    unsigned long long result = 0;

    getline(file, input);
    while((pos = input.find(',')) != string::npos){
        string range = input.substr(0, pos);
        lower_limit = range.substr(0, range.find('-'));
        upper_limit = range.substr(range.find('-')+1, range.length()-1);

        lower_limit_no = stoull(lower_limit);
        upper_limit_no = stoull(upper_limit);

        for(unsigned long long i = lower_limit_no; i <= upper_limit_no; i++){
            check_repeated(to_string(i), &result);
        }
        input.erase(0, pos + 1);
    }
    cout << result;
    return 0;
}
