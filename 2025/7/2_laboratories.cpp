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
  char new_manifold[300][300];
  unsigned long long new_manifold_value[300][300];

  for(int i = 0; i < 300; i++){
      for(int j = 0; j < 300; j++){
          new_manifold[i][j] = '.';
          new_manifold_value[i][j] = 0;
      }
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
              new_manifold_value[lineCount][i] += new_manifold_value[lineCount-1][i];
          } else if(line[i] == '^' && (new_manifold[lineCount-1][i] == '|')){
              result++;
              new_manifold[lineCount][i-1] = '|';
              new_manifold[lineCount][i+1] = '|';
              new_manifold[lineCount][i] = '^';
              new_manifold_value[lineCount][i-1]+=(new_manifold_value[lineCount-1][i] ? new_manifold_value[lineCount-1][i] :  1);
              new_manifold_value[lineCount][i+1]+=(new_manifold_value[lineCount-1][i] ? new_manifold_value[lineCount-1][i] :  1);
          } else if(line[i] == '^' && (new_manifold[lineCount-1][i] != '|')){
              new_manifold[lineCount][i] = '^';
          }
      }
      manifoldRow.push_back(line[i]);
    }
    lineCount++;
    manifold.push_back(manifoldRow);
  }
  unsigned long long sum = 0;
  for(int i = 0; i < rowLength; i++){
      sum+=new_manifold_value[lineCount-1][i];
  }
  cout<<"Sum "<<sum<<endl;
}
