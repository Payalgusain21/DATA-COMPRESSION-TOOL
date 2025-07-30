# DATA-COMPRESSION-TOOL

*COMPANY*: CODTECH IT SOLUTIONS

*NAME*: PAYAL GUSAIN

*INTERN ID*: CT04DH1488

*DOMAIN*: C LANGUAGE

*DURATION*: 4 WEEKS

*MENTOR*: NEELA SANTOSH

This C program is a menu-driven utility designed to perform text file compression and decompression using the Run-Length Encoding (RLE) method. RLE is a simple, lossless compression algorithm that reduces file size by replacing sequences of repeating characters with a single character and the number of repetitions. The program consists of three major components:
-> Compression function ,Decompression function and Main function with a user interface.

Compression Function:The compressFile() function is designed to reduce the size of a text file using a method called Run-Length Encoding (RLE). The idea is simple: if the same character appears multiple times in a row, we can store it just once along with a count of how many times it appeared. For example, instead of storing "aaaa", we can store it as "a4".

Here’s how the function works step-by-step:
1. Open Files: It takes two file names as input — one for reading (original text) and one for writing (compressed result). If any file fails to open, it displays an error and exits.
2. Read First Character: It reads the first character from the input file to start the compression process. If the file is empty, it exits.
3. Character Loop: Using a while loop, it reads each character one by one. It compares the current character with the previous one:
If they are the same, it increases a counter.
If they are different, it writes the previous character and the count to the output file, then resets the counter.
4. Final Write: After the loop ends, the last character and its count are written to ensure no data is missed.
5. Close Files: Both files are closed safely, and a success message is printed.

This function efficiently compresses repeated characters and can significantly reduce file size when large sequences of the same character exist.

Decompression Function:The decompressFile() function is responsible for restoring the original text from a file that was compressed using Run-Length Encoding (RLE). In RLE, each group of repeating characters is stored as a pair: the character itself and the number of times it occurs consecutively. For example, a4 represents aaaa.

Here's how the decompression function works:
1. Open Files: It opens two files — one for reading the compressed data and another for writing the decompressed (original) output. If either file fails to open, it prints an error and exits.
2. Read Character-Count Pairs: Using a loop and the fscanf() function, it reads the compressed file two items at a time: a character (ch) and an integer (count). Each line of the compressed file should follow the format like a 4.
3. Write Original Characters: Once a pair is read, a for loop writes the character back to the output file exactly count times using fputc(). This reconstructs the original data as it was before compression.
4. Repeat Until End of File: The loop continues reading and expanding pairs until all data has been processed.
5. Close Files: After all pairs are read and expanded, the input and output files are properly closed, and a confirmation message is printed to indicate that decompression is complete.

Main Function: The main() function serves as the central controller of the Run-Length Encoding program. It provides an interactive menu through which the user can choose to either compress a file, decompress a file, or exit the program. This function is essential because it connects the user to the compression and decompression logic without needing to understand how those processes work internally.
When the program starts, the user is shown a simple text-based menu on the screen. They are asked to choose one of three options by entering a number: 1 for compression, 2 for decompression, and 3 to exit the application. This approach is known as a menu-driven program.
After the user makes a choice, the program uses a switch statement to determine what action to take. If the user selects compression, the program asks them to input the name of the file they want to compress and then the name of the output file where the compressed data should be saved. It then calls the compressFile() function with those file names. Similarly, if the user chooses decompression, the program prompts for the compressed input file and the destination for the restored original text, then calls decompressFile().
If the user selects an invalid option (like 5 or a letter), the default case in the switch statement triggers, and the program displays a message like "Invalid choice." .
Once a valid operation is performed, the program prints a confirmation message like "Compression complete" or "Decompression complete" to inform the user of success. If the user selects the exit option, the program gracefully ends and returns 0, indicating successful execution.

*Application*: Basic file compression, Data storage optimization.

*EDITOR PLATFORM*: Visual Studio Code

*LIBRARY*: <stdio.h>,<stdlib.h>

*Concept*: Run Length Encoding Algorithm

*LANGUAGE*: C

*OUTPUT*: <img width="1920" height="1020" alt="Image" src="https://github.com/user-attachments/assets/62176846-29d2-482a-a2df-38a76550461b" />
