#include <fstream>
#include <iostream>
#include <string>

using namespace std;

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
        if(lower_limit.length() == upper_limit.length() && lower_limit.length() % 2 != 0 && upper_limit.length() % 2 != 0){
            input.erase(0, pos + 1);
            continue;
        }
        lower_limit_no = stoull(lower_limit);
        upper_limit_no = stoull(upper_limit);
        // if(lower_limit.length() % 2 != 0){
        //     if(upper_limit.length() % 2 != 0){
        //         upper_limit = string(upper_limit.length()-1, '9');
        //         upper_limit_no = stoull(upper_limit);
        //     }
        //     if(lower_limit.length() < upper_limit.length()){
        //         lower_limit = "1" + string(lower_limit.length(), '0');
        //         lower_limit_no = stoull(lower_limit);
        //     }
        // }
        // if(upper_limit.length() % 2 != 0){
        //     upper_limit = string(upper_limit.length()-1, '9');
        //     upper_limit_no = stoull(upper_limit);
        // }

        for(unsigned long long i = lower_limit_no; i <= upper_limit_no; i++){
            string num = to_string(i);
            if(num.length() % 2 == 0){
                string f_half = num.substr(0, num.length() / 2);
                if(f_half.find('-') != string::npos){
                    cout << i << endl;
                }
                string s_half = num.substr(num.length() / 2, num.length() - 1);
                if(stoull(f_half + f_half) <= upper_limit_no && stoull(f_half + f_half) >= lower_limit_no){
                    result+=stoull(f_half+f_half);
                    i=stoull(to_string(stoull(f_half)+1) + s_half);
                }
            }
        }
        input.erase(0, pos + 1);
    }
    cout << result;
}
