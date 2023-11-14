# PageRank Algorithm Implementation

This code offers a simple and straightforward implementation of the famous PageRank algorithm, which was developed by the founders of Google to rank websites in their search engine results. Utilizing modern C++ features, the code efficiently computes the PageRank values for a given set of pages.

## Key Features:

1. **PageRank Calculation**:
   
   - Each page has a rank and a list of outgoing links. The rank is initially set to `1.0` for all pages.
   - The `PageRank` function calculates the new rank values for each page based on the ranks of the pages that link to it. This calculation considers the damping factor, which accounts for the probability of a user randomly jumping to another page.
   - The algorithm iteratively refines the ranks of pages until the changes between iterations are smaller than a defined threshold (`EPSILON`).

2. **I/O Handling**:
   
   - **Input**: The `readInputFile` function reads page data from a given file. The file format consists of the number of pages followed by the number of outgoing links for each page and then the list of those links.
   - **Output**: The `generateOutputFile` function writes the computed PageRank values of all pages to a specified file after a sufficient number of iterations.

3. **Convergence**:
   
   - The algorithm is considered to have converged when the change in rank values between two consecutive iterations is less than `EPSILON`.
   - `DAMPING_FACTOR` is a constant representing the probability of a user to continue following links on a page. The value is usually set to `0.85`, as used in this implementation.

## Usage:

1. Prepare an `in.txt` file with the desired page data. The format should be:
    ```
    [number of pages]
    [number of outgoing links for page 1] [list of links]
    ...
    [number of outgoing links for page n] [list of links]
    ```

2. Compile and run the program.
3. Check the `out.txt` file to see the computed PageRank values for each page.

