#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> label(n);
    for (int i = 0; i < n; i++) {
        cin >> label[i];
    }

    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Adjacency List:" << "\n";

    for (int i = 0; i < n; i++) {
        cout << label[i] << " -> ";

        bool adaEdge = false;   
        string hasil = "";      

        for (int j = 0; j < n; j++) {
            if (mat[i][j] > 0) {
                if (adaEdge) {
                    hasil += ", ";
                }
                hasil += "(" + label[j] + "," + to_string(mat[i][j]) + ")";
                adaEdge = true;
            }
        }

        if (adaEdge) {
            cout << hasil << "\n";
        } else {
            cout << "-" << "\n";
        }
    }

    return 0;
}