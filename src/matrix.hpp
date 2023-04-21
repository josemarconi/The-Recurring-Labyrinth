#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

void Show(vector<vector<string>> Matriz, int line);

void Read(int *lootAll, int *line, int *columns, int *numberDG);

void Maps(vector<vector<string>> Matriz, int line, int columns, int n);

void AllLoot(vector<vector<string>> Matriz, int line, int columns, int *lootAll);

vector< vector <string>> GetMap(string mapName);

void SaveMap(vector<vector<string>> Matriz, string mapName, int line, int columns);

void Remove(int numberDG);

void ReadCompareMatrix(int line, int columns);

void CompareMatrix(vector<vector<string>> Matriz, int line, int columns, string NewArqName, int *contNotPosition);

void SaveOutput(int line, int columns, int numberDG);

#endif