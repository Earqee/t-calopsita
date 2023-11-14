# Thread-safe Bank Account Transaction System

This code demonstrates a bank transaction system using modern C++ features. It is designed to safely handle simultaneous transactions on bank accounts using mutex-based synchronization to prevent race conditions.

## Key Features:

1. **BankAccount Class**: A robust representation of a bank account with fundamental operations:
   
   - **Deposit**: Safely deposit a specified amount into the account.
   - **Withdraw**: Safely withdraw a specified amount from the account, if the balance permits.
   - **GetBalance**: Retrieve the current account balance.

2. **Concurrency Control**:
   
   - **Local Mutex**: Each `BankAccount` instance has its own mutex (`accountMutex`) ensuring that concurrent operations on the same account are synchronized.
   - **Global Mutex**: A global mutex (`globalMutex`) is utilized for global transactions, ensuring synchronized operations spanning multiple accounts.

3. **Transfer Functions**:

   - **Global Transfer**: Uses the global mutex to synchronize a transfer operation between two bank accounts.
   - **Object-Based Transfer**: Utilizes individual account mutexes, locking both accounts involved in the transaction. This allows concurrent operations on different accounts but serializes operations involving the same accounts. It uses `std::lock` to avoid potential deadlocks.

4. **File I/O**:
   
   - **Input**: Reads initial balances and a list of transfer operations from `in.txt`.
   - **Output**: Writes the final balances of the bank accounts to `out.txt` after processing all transactions.

## Usage:

1. Prepare an `in.txt` file with the following format:
    ```
    [Initial balance for Account1] [Initial balance for Account2]
    [operation] [amount]
    ...
    ```
   Where `operation` can be `global` or `object` and `amount` is the amount to be transferred from Account1 to Account2.

2. Compile and run the program.
3. Check the `out.txt` file to see the final balances of the bank accounts after all transactions.
