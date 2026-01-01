 #include <stdio.h>
 #include <stdlib.h>

int main(int argc, char *argv[])
{
 //check if correct number of arguments
if (argc != 3)
{
   printf("Usage: %s input_file.txt output_file.txt\n",
argv[0]);
   return 1;
}
  //open input file (argv[1])
  //open output file (argv[2])
  //process data
  //close files
  return 0;
}
