# Parallel Sieve of Eratosthenes

This code provides a parallelized implementation of the Sieve of Eratosthenes algorithm, one of the most efficient ways to find all prime numbers smaller than a given number. Using C++ and multithreading techniques, the code computes prime numbers up to a specified limit and writes them to an output file.

## Key Features:

1. **Parallelized Prime Computation**:

   - The core idea of the Sieve of Eratosthenes is iteratively marking the multiples of each prime number starting from 2.
   - The `markMultiples` function is responsible for marking non-prime numbers.
   - The algorithm leverages multiple threads to mark multiples of different prime numbers simultaneously, achieving a speed-up on multi-core processors.

2. **Dynamic Thread Management**:

   - The number of threads is determined by the hardware's concurrency capabilities.
   - Threads are created dynamically as prime numbers are found, and their count is limited to prevent oversubscription.
   - Threads are joined (i.e., their execution is completed) once the maximum allowable threads are active, ensuring synchronization and proper completion of tasks.

3. **Output Management**:

   - Found prime numbers are written to an `out.txt` file.
   - Non-prime numbers are skipped, providing a space-separated list of primes up to the input limit.

4. **File I/O**:

   - **Input**: Reads the upper limit for prime computation from `in.txt`.
   - **Output**: Writes computed prime numbers to `out.txt`.

## Usage:

1. Prepare an `in.txt` file with a single integer - the upper limit up to which primes need to be computed.

2. Compile and run the program.
3. Check `out.txt` to see the list of computed prime numbers up to the provided limit.
