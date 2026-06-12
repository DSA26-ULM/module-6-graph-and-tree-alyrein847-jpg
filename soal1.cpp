#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    string labels[10];
    for (int i = 0; i < N; i++) {
        cin >> labels[i];
    }

    int matrix[10][10] = {0};

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        string U, V;
        int W;
        cin >> U >> V >> W;

        int idxU = -1, idxV = -1;
        for (int j = 0; j < N; j++) {
            if (labels[j] == U) idxU = j;
            if (labels[j] == V) idxV = j;
        }

        matrix[idxU][idxV] = W;
    }

    int colWidth = 1;
    for (int i = 0; i < N; i++) {
        if ((int)labels[i].size() > colWidth)
            colWidth = labels[i].size();
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            string s = to_string(matrix[i][j]);
            if ((int)s.size() > colWidth)
                colWidth = s.size();
        }
    }

    cout << "Adjacency Matrix:" << endl;
    cout << string(colWidth, ' ');
    for (int j = 0; j < N; j++) {
        cout << " ";
        cout << string(colWidth - labels[j].size(), ' ') << labels[j];
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
        cout << string(colWidth - labels[i].size(), ' ') << labels[i];
        for (int j = 0; j < N; j++) {
            string val = to_string(matrix[i][j]);
            cout << " " << string(colWidth - val.size(), ' ') << val;
        }
        cout << endl;
    }

    return 0;
}
