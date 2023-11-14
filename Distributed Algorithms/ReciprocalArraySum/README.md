## Parallel Reciprocal Array Sum

This C++ program calculates the reciprocal array sum in a parallel fashion, leveraging multiple threads for improved performance. The program takes input from an `in.txt` file, which specifies the array size, the number of threads to use, and the array elements. It then computes the reciprocal sum and outputs the result to an `out.txt` file.

### Key Features:

- **Parallel Processing**: The code utilizes multiple threads to distribute the computation of the reciprocal sum, improving efficiency on multi-core processors.

- **Dynamic Thread Distribution**: The array is divided into chunks, and each thread processes a portion, ensuring that the work is balanced and efficient.

- **Accumulation of Results**: Partial results from each thread are combined to obtain the final reciprocal sum.

### Usage:

1. Create an `in.txt` file with the following format:

   ```
   arraySize numThreads
   element1 element2 element3 ... elementN
   ```

   - `arraySize` is the size of the array.
   - `numThreads` specifies the number of threads to use.
   - `element1`, `element2`, ..., `elementN` are the array elements.

2. Compile and run the program.

3. The result of the reciprocal array sum will be written to an `out.txt` file in the format: "Reciprocal Array Sum: result".

### Example:

Given the input in `in.txt`:

```
10 2
1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0
```

The program will calculate the reciprocal sum in parallel using 2 threads and produce the following output in `out.txt`:

```
Reciprocal Array Sum: 2.92897
```
