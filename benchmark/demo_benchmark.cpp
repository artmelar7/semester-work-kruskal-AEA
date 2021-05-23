#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream

// подключаем вашу структуру данных
#include "data_structure.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

vector<int> split(const std::string &s, char delimiter) {
  vector<int> tokens;

  string token;
  istringstream tokenStream(s);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(stoi(token));
  }
  return tokens;
}

int main(int argc, char **argv) {

  string str;
  cout<<"Absolute path to file:";
  cin>>str;
  string pathToInputFile = str;

  ifstream file(pathToInputFile);
  string result;
  string line;

  while (getline(file, line)) {
    vector<int> intValues = split(line, ' ');
    int n = intValues.size();

    for (int j = 0; j < 10; ++j) {
      cout<< " " << j << " ";
      itis::Graph graph(n);
      int i = 0;
      for (int value : intValues) {
        graph.AddWeightedEdge(i, i + 1, value);
        i++;
      }
      auto time_diff = chrono::nanoseconds::zero();
      const auto time_point_before = chrono::steady_clock::now();
      graph.kruskal();
      const auto time_point_after = chrono::steady_clock::now();

      time_diff += time_point_after - time_point_before;
      const long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

      cout << "Kruskal (ns): " << time_elapsed_ns << '\n';
    }
  }
}
