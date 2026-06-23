#include <iostream>
#include <string>
#include "RedBlackTree.h"
#include <bits/stdc++.h>
using namespace std;

using Node = RedBlackTree::Node;

void preorder(const Node* node, const Node* nil, vector<int>& out) {
    if (node == nil) return;
    out.push_back(node->key);       
    preorder(node->left, nil, out); 
    preorder(node->right, nil, out);
}

void inorder(const Node* node, const Node* nil, vector<int>& out) {
    if (node == nil) return;
    inorder(node->left, nil, out); 
    out.push_back(node->key);      
    inorder(node->right, nil, out);
}

void postorder(const Node* node, const Node* nil, vector<int>& out) {
    if (node == nil) return;
    postorder(node->left, nil, out); 
    postorder(node->right, nil, out); 
    out.push_back(node->key);         
}

void printList(const string& label, const vector<int>& list) {
    cout << label << " : ";
    for (size_t i = 0; i < list.size(); i++) {
        if (i > 0) cout << " ";
        cout << list[i];
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;

    RedBlackTree tree;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        if (!tree.contains(value)) {
            tree.insert(value);
        }
    }

    int q;
    cin >> q;

    vector<string> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    if (tree.empty()) {
        cout << "Tree kosong. Tidak ada yang bisa ditampilkan." << "\n";
        return 0;
    }

    const Node* root = tree.root();
    const Node* nilNode = tree.nil();

    for (const string& type : queries) {
        if (type == "PREORDER" || type == "ALL") {
            vector<int> pre;
            preorder(root, nilNode, pre);
            printList("[Preorder]", pre);
        }
        if (type == "INORDER" || type == "ALL") {
            vector<int> in;
            inorder(root, nilNode, in);
            printList("[Inorder]", in);
        }
        if (type == "POSTORDER" || type == "ALL") {
            vector<int> post;
            postorder(root, nilNode, post);
            printList("[Postorder]", post);
        }
    }

    return 0;
}