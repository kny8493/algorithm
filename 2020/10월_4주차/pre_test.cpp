#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <deque>
#include <stack>
#include <vector>
#include<cstdio>
#include<algorithm>
#include<memory.h>
#include<queue>
#include<map>
#include <sstream>

#define MAX 10

using namespace std;

bool visit[MAX][MAX];
vector<int> v;
int locX[] = { -1,0,1,0 };
int locY[] = { 0,1,0,-1 };
void func(int size, int** matrix, int i, int j) {
    int sum = 0;
    if (!matrix[i][j]) {
        visit[i][j] = true;
        return;
    }
    if (visit[i][j]) return;

    queue<pair<int, int>> q;
    q.push({ i,j });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        sum++;
        visit[x][y] = true;
        for (int cnt = 0; cnt < 4; cnt++) {
            if (x + locX[cnt] < 0 || x + locX[cnt] >= size || y + locY[cnt] < 0 || y + locY[cnt] >= size) { continue; }
            if (matrix[x + locX[cnt]][y + locY[cnt]] && !visit[x + locX[cnt]][y + locY[cnt]]) {
                 q.push({ x + locX[cnt], y + locY[cnt] });
                 visit[x + locX[cnt]][y + locY[cnt]] = true;
            }
        }

    }
    v.push_back(sum);

}

void solution(int sizeOfMatrix, int** matrix) {
    // TODO: 이곳에 코드를 작성하세요.
    for (int i = 0; i < sizeOfMatrix; i++) {
        for (int j = 0; j < sizeOfMatrix; j++) {
            if (visit[i][j]) continue;
            else func(sizeOfMatrix, matrix, i, j);
        }
    }
    if (!v.size()) {
        cout << "0";
        return;
    }
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }


}

struct input_data {
    int sizeOfMatrix;
    int** matrix;
};

void process_stdin(struct input_data& inputData) {
    string line;
    istringstream iss;

    getline(cin, line);
    iss.str(line);
    iss >> inputData.sizeOfMatrix;

    inputData.matrix = new int* [inputData.sizeOfMatrix];
    for (int i = 0; i < inputData.sizeOfMatrix; i++) {
        getline(cin, line);
        iss.clear();
        iss.str(line);
        inputData.matrix[i] = new int[inputData.sizeOfMatrix];
        for (int j = 0; j < inputData.sizeOfMatrix; j++) {
            iss >> inputData.matrix[i][j];
        }
    }
}

int main() {
    struct input_data inputData;
    process_stdin(inputData);

    solution(inputData.sizeOfMatrix, inputData.matrix);
    return 0;
}