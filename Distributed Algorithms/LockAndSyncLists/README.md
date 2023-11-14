# Concurrent Linked List with File I/O

This code provides an implementation of a singly linked list designed to support concurrent operations. Utilizing C++17 features, the implementation ensures that the list remains correctly synchronized even with concurrent insertions, deletions, and searches.

## Key Features:

1. **Concurrent Safety with Mutexes**: Each node in the list has its own mutex, ensuring that multiple threads can concurrently operate on the list without causing inconsistencies.
   
2. **Fine-Grained Locking**: The implementation uses hand-over-hand locking (also known as lock coupling) to allow multiple threads to traverse the list concurrently, ensuring minimal contention.

3. **Memory Management with `unique_ptr`**: Nodes are managed using `std::unique_ptr` ensuring automatic and safe deallocation of memory.

4. **File I/O**: The program reads operations from `in.txt` and writes the results to `out.txt`. Supported operations include `insert`, `search`, and `remove`.

5. **Using `std::optional` for Search**: The search function returns a `std::optional` indicating whether a searched-for value was found. This modern C++ feature provides a clear way to handle absent values.

## Usage:

Prepare an `in.txt` file with the desired operations, for instance:
```
insert 1
insert 2
search 2
remove 1
```

Run the program. The results of the operations will be written to `out.txt`.
