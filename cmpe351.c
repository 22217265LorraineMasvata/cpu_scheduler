 #include <stdio.h>
 #include <stdlib.h>

/* ===== STRUCT DEFINITIONS ===== */
typedef struct Process {
    int burst_time;        // CPU execution time
    int priority;          // Priority level
    int arrival_time;      // Time process arrives
    int queue_id;          // Which queue it belongs to
    int waiting_time;      // Time spent waiting
    struct Process *next;  // Pointer to next process (linked list)
} Process;

/* ===== FUNCTION PROTOTYPES (optional for now) ===== */

int main(int argc, char *argv[])
{
FILE *inputFile;
FILE *outputFile;
 //check if correct number of arguments
if (argc != 3)
{
   printf("Usage: %s input_file.txt output_file.txt\n",
argv[0]);
   return 1;
}
//open input file (argv[1]) and output file (argv[2])
inputFile = fopen(argv[1], "r");
outputFile = fopen(argv[2], "w");

if (inputFile == NULL || outputFile == NULL) {
    printf("Error opening file\n");
    return 1;
}
  //process data
 fclose(inputFile);
 fclose(outputFile);

  //close files
  return 0;
}
