#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ifstream file("input.txt");
  ifstream file2("example_input.txt");

  string line;
  unsigned long long result = 0;
  int s_pos = 0, lineCount = 0, rowLength = 0;
  vector<vector<char>> manifold;
  vector<int> splitter_pos;
  char new_manifold[300][300];
  
  for(int i = 0; i < 300; i++){
      for(int j = 0; j < 300; j++){
          new_manifold[i][j] = '.'; 
      }
      cout<<endl;
  }
  while (getline(file, line)) {
    rowLength = line.length();
    vector<char> manifoldRow;
    for (int i = 0; i < line.length(); i++) {
      if (lineCount == 0) {
        if (line[i] == 'S') {
            new_manifold[lineCount][i] = 'S';
            s_pos = i;
        }
      } else {
          if(line[i] == '.' && lineCount > 0 && (new_manifold[lineCount-1][i] == 'S' || new_manifold[lineCount-1][i] == '|')){
              line[i] = '|';
              new_manifold[lineCount][i] = '|';
          } else if(line[i] == '^' && (new_manifold[lineCount-1][i] == '|')){
              result++;
              new_manifold[lineCount][i-1] = '|';
              new_manifold[lineCount][i+1] = '|';
              new_manifold[lineCount][i] = '^';
          } else if(line[i] == '^' && (new_manifold[lineCount-1][i] != '|')){
              new_manifold[lineCount][i] = '^';
          }
      }
      manifoldRow.push_back(line[i]);
    }
    lineCount++;
    manifold.push_back(manifoldRow);
  }
  cout<<endl;
  for(int i = 0; i < lineCount; i++){
      for(int j = 0; j < rowLength; j++){
        cout<<new_manifold[i][j]; 
      }
      cout<<endl;
  }
  cout<<"Result "<<result;
}
