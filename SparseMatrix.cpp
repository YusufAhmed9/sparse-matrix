#include "SparseMatrix.h"

void SparseMatrix::delete_node(Node *node) {
    if (node->prev) {
        node->prev->next = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    }
    size--;
    node->prev = node->next = nullptr;
    delete node;
}

void SparseMatrix::pop_front() {
    if (!size) {
        throw std::out_of_range("index out of bounds");
    }
    Node *temp = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
    }
    delete_node(temp);
}

void SparseMatrix::link(Node *first, Node *second) const {
    if (first) {
        first->next = second;
    }
    if (second) {
        second->prev = first;
    }
}

Node *SparseMatrix::embed_after(Node *array_node, int value, int row_index, int col_index) {
    Node *node = new Node(value, row_index, col_index);
    Node *next = array_node->next;
    link(array_node, node);
    if (!next) {
        tail = node;
    } else {
        link(node, next);
    }
    ++size;
    return node;
}

Node *SparseMatrix::get_index(int row_index, int col_index, bool create_if_not_found) {
    Node *before = head;
    while (before->next && before->next->row_index < row_index) {
        before = before->next;
    }
    if (before->next && before->next->row_index == row_index) {
        while (before->next && before->next->row_index == row_index
               && before->next->col_index < col_index) {
            before = before->next;
        }
        if (before->next && before->next->row_index == row_index
            && before->next->col_index == col_index) {
            return before->next;
        }
    }
    if (!create_if_not_found) {
        return nullptr;
    }
    return embed_after(before, 0, row_index, col_index);
}

SparseMatrix::SparseMatrix(int row_capacity, int col_capacity) : row_capacity(row_capacity),
                                                                 col_capacity(col_capacity) {
    head = tail = new Node(0, -1, -1);
}

int SparseMatrix::get_value(int row_index, int col_index) {
    if (row_index >= row_capacity || col_index >= col_capacity) {
        throw std::out_of_range("index out of bounds");
    }
    Node *node = get_index(row_index, col_index, false);
    if (node) {
        return node->value;
    }
    return 0;
}

void SparseMatrix::set_value(int value, int row_index, int col_index) {
    if (row_index >= row_capacity || col_index >= col_capacity) {
        throw std::out_of_range("index out of bounds");
    }
    get_index(row_index, col_index, true)->value = value;
}

void SparseMatrix::print_array_non_zero() const {
    for (Node *node = head->next; node; node = node->next) {
        if (node->prev->row_index != node->row_index && ~node->prev->row_index) {
            cout << el;
        }
        cout << node->value << ' ';
    }
    cout << el;
}

void SparseMatrix::print_array() const {
    Node *node = head->next;
    for (int i = 0; i < row_capacity; ++i) {
        for (int j = 0; j < col_capacity; ++j) {
            if (node && i == node->row_index && j == node->col_index) {
                cout << node->value << ' ';
                node = node->next;
                continue;
            }
            cout << 0 << ' ';
        }
        cout << el;
    }
    cout << el;
}

void SparseMatrix::add(const SparseMatrix &another) {
    if (another.row_capacity != row_capacity || another.col_capacity != col_capacity) {
        throw std::invalid_argument("Mismatched capacities between containers");
    }

    Node *another_head = another.head;
    for (Node *node = another.head->next; node; node = node->next) {
        Node *array_node = get_index(node->row_index, node->col_index, true);
        array_node->value += node->value;
    }
}

SparseMatrix::~SparseMatrix() {
    while (size) {
        pop_front();
    }
}
