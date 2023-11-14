## Parallel Matrix Multiplication

This C++ program demonstrates parallel matrix multiplication using multithreading. The program reads two matrices from an input file, multiplies them in parallel, and writes the result to an output file. Key aspects of the code include:

- **Matrix Input**: The code reads two input matrices from the "in.txt" file. It also reads the number of threads to use for parallel processing.

- **Matrix Multiplication**: The matrices A and B are multiplied in parallel using multiple threads. Each thread is responsible for computing a subset of the rows in the result matrix C.

- **Thread Management**: The code dynamically creates and manages threads to perform matrix multiplication concurrently.

- **Thread Synchronization**: The program ensures proper synchronization between threads to avoid data races and to obtain the correct result.

The provided code allows you to perform matrix multiplication efficiently by distributing the work among multiple threads, taking advantage of parallel processing capabilities.

To use the code, prepare an "in.txt" file with the matrices and the number of threads, run the program, and it will produce the result in the "out.txt" file.