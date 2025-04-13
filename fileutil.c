#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

// Defines
#define INC_ALLOC 256
#define DEF_ALLOC INC_ALLOC*4
#define MAX_LINE 80

// DIRECTIONS
// Choose whether you are doing the 2D array or
// the array of arrays.
// For the 2D array,
//    implement loadFile2D, substringSearch2D, and free2D.
// For the array of arrays, 
//    implement loadFileAA, substringSearchAA, and freeAA.


// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFileAA(char *filename, int *size)
{
	int internalMax = DEF_ALLOC;
	char **strings;
	char *inputStr;
	FILE *inFile = fopen(filename, "r");
	if (!inFile)
	{
	    perror("Can't open file");
	    exit(1);
	}


	// TODO
	// Allocate memory for an array of strings (arr).
	// Read the file line by line.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Allocate memory for the string (str).
	//   Copy each line into the string (use strcpy).
	//   Attach the string to the large array (assignment =).
    // Close the file.
	
	// Initialization.
	*size = 0;
	strings = malloc(DEF_ALLOC * sizeof(char *));
	inputStr = malloc(MAX_LINE * sizeof(char));
	
	// Load all strings.
	// There is a bizarre crash involved here that I can't seem to fix.
	// After a certain point, malloc() results in a "invalid next size (unsorted)" error.
	// This doesn't actually reach the strcpy, mind you, it crashes AT the malloc.
	// My guess is that I'm running out of RAM, after tweaking the settings and a LOT of printf.
	// This means that sample3 actually CANNOT be loaded by this program, no matter how hard you try.
	// Works with sample2 though, so that's great.
	while (fgets(inputStr, MAX_LINE, inFile)) {
		//printf("%d\n", *size);
		char *str;
		// Get rid of the CRLF.
		inputStr[strlen(inputStr) - 1] = 0;
		if (strlen(inputStr) == 0) continue; // Blank strings get discard to conserve RAM.
		if (*size == internalMax) {
			//printf("TA %d %d\n", internalMax, INC_ALLOC);
			internalMax += INC_ALLOC;
			strings = realloc(strings, (internalMax) * sizeof(char *));
			//printf("TB %d %d\n", internalMax, (internalMax) * sizeof(char *));
		}
			//printf("TC %lu\n", strlen(inputStr) * sizeof(char));
		str = malloc(strlen(inputStr) * sizeof(char));
			//printf("TD\n");
		strcpy(str, inputStr);
			//printf("TE\n");
		// printf("[%d] %s (%ld):(%ld) %s\n", *size, str, strlen(str), strlen(inputStr), inputStr);
		strings[*size] = str;
		*size += 1;
	}
	
	// Cleanup.
	free(inputStr);
	fclose(inFile);


	// Return pointer to the array of strings.
	return strings;
}

char (*loadFile2D(char *filename, int *size))[COLS]
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an 2D array, using COLS as the width.
	// Read the file line by line into a buffer.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Copy each line from the buffer into the array (use strcpy).
    // Close the file.
	
	// The size should be the number of entries in the array.
	*size = 0;
	
	// Return pointer to the array.
	return NULL;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearchAA(char *target, char **lines, int size)
{
	for (int i = 0; i < size; i++) {
		if (strstr(lines[i], target))
			return lines[i];
	}
	return NULL;
}

char * substringSearch2D(char *target, char (*lines)[COLS], int size)
{
    
    return NULL;
}

// Free the memory used by the array
void freeAA(char ** arr, int size)
{
	for (int i = 0; i < size; i++) {
		free(arr[i]);
	}
	free(arr);
}

void free2D(char (*arr)[COLS])
{
	
}