#include "SparseMatrix.h"

int main() {
    SparseMatrix mat(10, 10);
    mat.set_value(5, 3, 5);
    mat.set_value(7, 3, 7);
    mat.set_value(2, 3, 2);
    SparseMatrix mat2(10, 10);
    mat2.set_value(5,1,9);
    mat2.set_value(6,3,8);
    mat2.set_value(9,9,9);
    mat.add(mat2);
    mat.print_array_non_zero();
    return 0;
}
