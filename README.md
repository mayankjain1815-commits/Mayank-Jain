# Mayank-Jain

BANK MANAGEMENT SYSTEM{
A begginer-friendly, console-based banking application written entirely in C. This project simulates basic banking operations and is designed to demonstrate fundamental programming concepts like structures,functions, and conditional logic.

FEATURES-> 
Create New Account: Add a new user with a name and initial deposit.

Deposit Funds: Add money to any existing account.

Withdraw Funds: Withdraw money from an account, with checks for insufficient balance.

Check Balance: Display the details and current balance of a specific account.

Simple & Secure: All data is managed in memory for the duration of the program's execution.

TECH STACK->
Language: C

Compiler: GCC (GNU Compiler Collection)

PREREQUISTES->
You need a C compiler like GCC installed on your system.
How to Compile and Run->
1. Clone the repository:
   git clone https://github.com/your-username/Bank-Management-System.git

2. Navigate to the project directory:
   cd Bank-Management-System

3. Compile the source code:
   gcc bank_system.c -o bank_app

4. Run the application:
   ./bank_app

USAGE->
Once the application is running, a menu will appear with several options. Simply enter the number corresponding to the action you want to perform (e.g., enter 1 to create a new account) and follow the on-screen prompts.


FUTURE IMPROVEMENTS->
1.Add file handling to save account data permanently.

2. Implement a feature for transaction history.

3. Add a simple interest calculation function.

---------------------------------------------------------------------------------------



SIMPLE C FILE COMPRESSOR USING RUN-LENGTH ENCODING->

This is a basic, educational file compression tool written in C. It uses the Run-Length Encoding (RLE) algorithm to compress data. The project is designed for beginners to understand fundamental C programming concepts, including file I/O, command-line arguments, and basic algorithm implementation.

HOW IT WORKS->
Run-Length Encoding is a simple form of lossless data compression. It works by replacing sequences of identical, consecutive characters with a single count and the character itself.

For example, a file containing the text:
AAAAABBBBBBBCCCC

Would be compressed by this program into a sequence of bytes representing:
5A 7B 4C

NOTE: This algorithm is most effective on files with high-frequency repeating characters (like simple text art or uncompressed bitmap images). For files with little repetition, the output file may be slightly larger than the original.


FEATURES ✨->
1. Simple RLE Algorithm: Implements a straightforward compression logic.

2. Command-Line Interface: Takes input and output filenames as arguments for easy use in a terminal.

3. Binary Mode File I/O: Reads and writes files in binary mode to handle any type of character data.

4. Readable Code: The source code is well-commented and structured for learning purposes.


TECH STACK->
1. Language: C

2. Compiler: GCC (GNU Compiler Collection)


GETTING STARTED->
Follow these instructions to compile and run the program on your own machine.

PREREQUISITES->
You must have a C compiler, such as GCC, installed on your system.


HOW TO COMPILE AND RUN->
1. Clone the repository:

git clone [https://github.com/your-username/your-repository-name.git](https://github.com/your-username/your-repository-name.git)
cd your-repository-name

2. Compile the C file:

gcc compress.c -o compressor

3. Run the program:
Create a sample file named input.txt with some repeating text (e.g., aaaaabbc). Then, run the executable with the input and desired output filenames:

./compressor input.txt compressed_output.bin















   

