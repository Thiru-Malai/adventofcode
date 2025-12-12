#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    ifstream file("1_secret_entrance.txt");
    ifstream file1("1_example.txt");
    string rotation;
    char direction;
    int current_position = 50, value, result = 0, prev_output;
    while(getline(file, rotation)){
        direction = rotation[0];
        value = stoi(rotation.substr(1, rotation.length() -1));
        cout<< "Input " << value;
        if(value > 100){
            value%=100;
        }
        if(direction == 'L'){
            if(current_position - value >= 0){
                current_position = current_position - value;
            } else if(current_position - value < 0) {
                current_position = current_position - value + 100;
            }
        } else {
            if(current_position + value <= 100){
                current_position = current_position + value;
            } else if(current_position + value >= 100){
                current_position = (current_position + value) % 100;
            }
            if(current_position == 100){
                current_position = 0;
            }
        }

        if(current_position == 0){
            result++;
        }
        cout << " Output " << current_position << endl;
    }
    cout << result << endl;
    return 0;
}
