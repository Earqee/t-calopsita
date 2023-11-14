# Distributed Matrix Multiplication using MPI

This code demonstrates the distributed multiplication of matrices using the Message Passing Interface (MPI) in C++. The program is designed to read two matrices from a file, multiply them in a distributed fashion across multiple MPI processes, and then save the result to an output file.

## Key Features:

1. **Matrix Class**: This class provides methods for reading matrices from files (`readFromInput`), writing matrices to files (`writeToOutput`), and matrix multiplication (`multiply`). The class leverages the power of the C++ STL, using `vector` to store matrix data.

2. **DistributedMatrixMultiplier Class**: This class encapsulates the distributed matrix multiplication logic:
   
   - Initialization determines the MPI rank (process ID) and size (total number of processes).
   - The `multiply` function performs the distributed multiplication, where matrices `A` and `B` are divided among the available MPI processes, multiplied locally, and then aggregated to produce the final matrix `C`.
   - The class uses the scatter-gather model of MPI (`MPI_Scatter` and `MPI_Gather`) to distribute parts of matrices to different processes and gather the results.
   - Upon destruction (`~DistributedMatrixMultiplier`), the MPI environment is finalized.

3. **File I/O**: The matrices to be multiplied are read from `in.txt` and the resulting matrix is written to `out.txt`.

4. **MPI Initialization**: The main function initializes the MPI environment (`MPI_Init`) and runs the test function (`testFunction`) to perform distributed matrix multiplication.

## Usage:

1. Prepare `in.txt` with two matrices. The format should be:
    ```
    [rows of matrix A] [columns of matrix A / rows of matrix B] [columns of matrix B]
    [Matrix A data row by row]
    [Matrix B data row by row]
    ```

2. Compile and run the program using an MPI environment (like OpenMPI). For example:
    ```bash
    mpic++ program.cpp -o program
    mpirun -np 4 ./program
    ```

3. The multiplied matrix will be saved in `out.txt`.

## Note:
Ensure that the number of MPI processes (specified with `-np` in `mpirun`) is a perfect square, as the program uses the square root of this number to determine block sizes for distributed multiplication.