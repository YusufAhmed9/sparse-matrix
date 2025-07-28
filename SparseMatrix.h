#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H


#include<iostream>

using namespace std;
#define el '\n'

struct Node {
    int value{};
    Node *next{};
    Node *prev{};
    int row_index{};
    int col_index{};

    Node(int value, int row_index, int col_index) : value(value), row_index(row_index), col_index(col_index) {
    }

    ~Node() {
        cout << "Node (" << value << ", " << row_index << ", " << col_index << ") destroyed at" << this << el;
    }
};

class SparseMatrix {
    /*
     * Capacity = maximum number of nodes
     * Size = Current number of nodes
     */
    int size{};
    Node *head{};
    Node *tail{};
    int row_capacity{};
    int col_capacity{};

    void delete_node(Node *node);

    void pop_front();

    void link(Node *first, Node *second) const;

    Node *embed_after(Node *array_node, int value, int row_index, int col_index);

    Node *get_index(int row_index, int col_index, bool create_if_not_found);

public:
    SparseMatrix(int row_capacity, int col_capacity);

    int get_value(int row_index, int col_index);

    void set_value(int value, int row_index, int col_index);

    void print_array_non_zero() const;

    void print_array() const;

    void add(const SparseMatrix &another);

    ~SparseMatrix();
};


#endif //SPARSEMATRIX_H
