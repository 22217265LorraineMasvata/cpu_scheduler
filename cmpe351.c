 #include <stdio.h>
 #include <stdlib.h>

typedef struct Process {
    int burst_time;        // CPU execution time
    int priority;          // Priority level
    int arrival_time;      // Time process arrives
    int queue_id;          // Which queue it belongs to
    int waiting_time;      // Time spent waiting
    struct Process *next;  // Pointer to next process (linked list)
} Process;


int main(int argc, char *argv[])
{

int burst, priority, arrival, queue;

Process *head = NULL;
Process *tail = NULL;

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

if (inputFile == NULL || outputFile == NULL) 
{
    printf("Error opening file\n");
    return 1;
}

//process data
while (fscanf(inputFile, "%d:%d:%d:%d",&burst, &priority, &arrival, &queue) == 4) 
{

    Process *newProcess = (Process *)malloc(sizeof(Process));
      if (newProcess == NULL)
   {
       printf("Memory allocation failed\n");
       return 1;
   }

  newProcess->burst_time = burst;
  newProcess->priority = priority;
  newProcess->arrival_time = arrival;
  newProcess->queue_id = queue;
  newProcess->waiting_time = 0;
  newProcess->next = NULL;

      if (head == NULL)
   {
        head = newProcess;
        tail = newProcess;
   }

    else
   {
        tail->next = newProcess;
        tail = newProcess;
   }

}
//testing for correctness
Process *temp = head;
while (temp != NULL) {
    printf("BT=%d P=%d AT=%d Q=%d\n",
           temp->burst_time,
           temp->priority,
           temp->arrival_time,
           temp->queue_id);
    temp = temp->next;
}

//close files
fclose (inputFile);
fclose (outputFile);

  return 0;
}
