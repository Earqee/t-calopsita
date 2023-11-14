# Parallel Boruvka's Minimum Spanning Tree (MST) Algorithm

This code provides an optimized and parallelized implementation of Boruvka's Minimum Spanning Tree (MST) algorithm using modern C++ techniques. Designed for performance, it efficiently computes the MST of a given graph while leveraging the multi-core capabilities of modern CPUs.

## Key Features:

1. **Graph Representation**:
   
   - The `Graph` class represents a weighted undirected graph. It consists of `V` vertices, `E` edges, and a list of `Edge` structures that define the graph's connectivity and weights.

2. **Disjoint Set Data Structure**:
   
   - The `Subset` structure facilitates the union-find operations, crucial for Boruvka's MST algorithm.
   - Operations include `find`, which determines the set a vertex belongs to, and `unionSets`, which combines two sets.

3. **Parallelization**:

   - The algorithm is parallelized using multiple threads, determined by the hardware's concurrency capabilities.
   - Threads work on different parts of the edge list simultaneously to find the minimum weight edge for every vertex.
   - Thread synchronization is achieved using `std::mutex` to ensure thread-safe modifications.

4. **Convergence**:
   
   - The algorithm keeps finding the minimum weight edge for all trees until only one tree (the MST) remains.
   
5. **I/O Handling**:
   
   - **Input**: Reads graph data from `in.txt`. The file should define the number of vertices and edges followed by the edges with their source, destination, and weight.
   - **Output**: The resulting MST edges and their weights are written to `out.txt` along with the total weight of the MST.

## Usage:

1. Prepare `in.txt` with the desired graph data. The format should be:
    ```
    [number of vertices] [number of edges]
    [source1] [dest1] [weight1]
    ...
    [sourceN] [destN] [weightN]
    ```

2. Compile and run the program.
3. Check `out.txt` to see the edges that make up the Minimum Spanning Tree and its total weight.

## Note:
This is a parallelized version of Boruvka's MST algorithm and is expected to provide better performance on multi-core systems compared to its serial counterpart. Proper synchronization ensures thread-safe operations, preventing race conditions.