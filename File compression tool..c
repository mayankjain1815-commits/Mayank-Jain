// Simple File Compressor using Run-Length Encoding (RLE)
 
 //This program reads an input file, compresses its content using a basic
 // RLE algorithm, and writes the compressed data to an output file.
 
 //How it works:
 //It counts consecutive occurrences of the same character and stores
 // the count followed by the character itself. For example, "AAAAA" becomes "5A".
 
 //Note: This implementation is for educational purposes. For files with few
 //repeating characters, the "compressed" file might be larger than the original.
 

#include <stdio.h>
#include <stdlib.h>

void compress_file(FILE *inputFile, FILE *outputFile) {
    int currentChar;
    int lastChar = EOF;
    int charCount = 0;

    // Read the first character to start the process
    lastChar = fgetc(inputFile);
    if (lastChar == EOF) {
        // The file is empty, nothing to do.
        return;
    }
    charCount = 1;

    // Loop through the rest of the file
    while ((currentChar = fgetc(inputFile)) != EOF) {
        // If the character is the same as the last one, increment count
        if (currentChar == lastChar) {
            charCount++;
        } else {
            // If character is different, write the previous sequence
            fputc(charCount, outputFile); // Write the count
            fputc(lastChar, outputFile);  // Write the character
            
            // Reset for the new character
            lastChar = currentChar;
            charCount = 1;
        }
    }
    
    // Write the very last sequence after the loop finishes
    fputc(charCount, outputFile);
    fputc(lastChar, outputFile);
}

int main(int argc, char *argv[]) {
    // Check for the correct number of command-line arguments
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1; // Indicate an error
    }

    // Open the input file for reading in binary mode
    FILE *inputFile = fopen(argv[1], "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Open the output file for writing in binary mode
    FILE *outputFile = fopen(argv[2], "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile); // Close the already opened input file
        return 1;
    }

    printf("Compressing '%s' into '%s'...\n", argv[1], argv[2]);
    
    // Call the compression function
    compress_file(inputFile, outputFile);

    printf("✅ Compression successful!\n");

    // Clean up: close the files
    fclose(inputFile);
    fclose(outputFile);

    return 0; // Indicate success
}
