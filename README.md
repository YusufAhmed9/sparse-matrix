# Sparse Matrix

A **sparse matrix** is a matrix where most of the elements are zero. It's a way to efficiently store and manipulate matrices, particularly large ones, where a significant portion of the data is made up of zeros.
## Why Use Sparse Matrices?

- **Memory Efficiency**: Only non-zero elements are stored, saving space.
- **Faster Computations**: Algorithms can skip zero values, improving performance.
- **Scalability**: Useful for large datasets like graphs, machine learning models, and scientific computations.

## Common Storage Formats

- **COO (Coordinate List)**: Stores row, column, and value of non-zero elements.
- **CSR (Compressed Sparse Row)**: Efficient for row slicing and matrix-vector products.
- **CSC (Compressed Sparse Column)**: Efficient for column slicing and solving linear systems.

## Applications

- Graphs (adjacency matrices)
- Recommendation systems
- Natural language processing (bag-of-words models)
- Image compression



## Implementation Provided Content

This project includes a basic implementation of sparse matrix operations:

-  **Setting and getting values**
-  **Adding two matrices (with the same size)**

### Example Diagram

![Sparse Matrix Diagram](https://media.geeksforgeeks.org/wp-content/uploads/Sparse-Matrix-Array-Representation1.png)

## 📚 Sources

- [Wikipedia: Sparse Matrix](https://en.wikipedia.org/wiki/Sparse_matrix)
- [Scipy Sparse Docs](https://docs.scipy.org/doc/scipy/reference/sparse.html)
- [GeeksforGeeks - Sparse Matrices](https://www.geeksforgeeks.org/sparse-matrix-representation/)
