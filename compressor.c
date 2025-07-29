#include <stdio.h>
#include <stdlib.h>

// Function to compress a text file using Run-Length Encoding
void compressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");                 //open inputfile for reading
    FILE *out = fopen(outputFile, "w");               //open outputfile for writting

    if (!in || !out) {                                //checking if file is opening or not
        printf("Error opening file.\n");
        return;
    }

    char current, prev;
    int count = 1;

    prev = fgetc(in);                                //read first character from the file
    if (prev == EOF) {
        printf("Input file is empty.\n");
        fclose(in);
        fclose(out);
        return;
    }

    while ((current = fgetc(in)) != EOF) {
        if (current == prev) {
            count++;
        } else {
            fprintf(out, "%c%d", prev,count);    //write character and its count in compressed output file
            count = 1;               //reset count for new character
        }
        prev = current;
    }

    // Write the last run
    fprintf(out, "%c%d", prev,count);

    fclose(in);
    fclose(out);
    printf("Compression complete. Output saved to '%s'.\n", outputFile);
}

// Function to decompress a file compressed with RLE
void decompressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");      //opening inputfile in read mode
    FILE *out = fopen(outputFile, "w");    //opening outputfile in write mode

    if (!in || !out) {
        printf("Error opening file.\n");   //checking if file is opening or not
        return;
    }

    int count;
    char ch;

    while (fscanf(in, "%c%d",&ch,&count)==2){ //
        for (int i = 0; i < count; i++) {
            fputc(ch, out);           //write the caracter count number of times 
        }  
        
    }
 
    fclose(in);
    fclose(out);
    printf("Decompression complete. Output saved to '%s'.\n", outputFile);
}

// Main menu
int main() {
    int choice;
    char inputFile[100], outputFile[100];

    printf("Text File Compressor/Decompressor (RLE Method)\n");
    printf("1. Compress File\n");
    printf("2. Decompress File\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();  // to clear newline

    switch (choice) {
        case 1:
            printf("Enter input file name: ");
            scanf("%s", inputFile);
            printf("Enter output (compressed) file name: ");
            scanf("%s", outputFile);
            compressFile(inputFile, outputFile);
            break;
        case 2:
            printf("Enter compressed file name: ");
            scanf("%s", inputFile);
            printf("Enter output (decompressed) file name: ");
            scanf("%s", outputFile);
            decompressFile(inputFile, outputFile);
            break;
        case 3:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}