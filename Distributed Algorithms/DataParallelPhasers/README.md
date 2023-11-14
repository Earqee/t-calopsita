## Data Parallel Processing with Threads

This C++ code demonstrates data parallel processing using multiple threads to compute a result from a set of input data. The code's most important aspects are as follows:

- **Parallel Processing**: The code leverages multi-threading to perform data parallel processing, which allows for more efficient computation on multi-core systems.

- **Thread Synchronization**: The code uses mutexes and condition variables to synchronize the execution of threads, ensuring that they complete specific phases of the computation before proceeding to the next.

- **Phase-Based Processing**: The processing involves two phases: Phase 1 for parallel computation (e.g., squaring numbers) and Phase 2 for combining the results.

- **Dynamic Thread Allocation**: The code dynamically divides the data into chunks, distributing them among the specified number of threads for parallel processing.

To use the code, provide the input data in `in.txt`, specifying the number of elements, the data, and the desired number of threads. The code will perform data parallel processing and produce the final result in `out.txt`.