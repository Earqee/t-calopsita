# Student Statistics Analysis with Parallel Processing

This C++ program is designed to efficiently analyze student statistics using parallel processing. The key aspects of this code include:

- **Parallel Processing**: The code employs multi-threading to perform parallel computation, allowing for faster calculation of statistics, such as the average, minimum, and maximum scores for students.

- **User-Defined Threads**: You can specify the number of threads to use for parallel processing, providing flexibility in resource allocation.

- **Thread Synchronization**: Mutexes are used to ensure safe concurrent access to shared resources, and the student data is divided into chunks for parallel processing.

## Usage

1. Create an input file (`in.txt`) with the following data:
   - The number of threads to use for parallel processing.
   - The number of students.
   - Student names and scores.

2. Execute the program.

3. The program calculates and outputs the average, minimum, and maximum scores for the students.

4. The results are written to an output file (`out.txt`).
