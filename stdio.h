#ifndef STDIO_H
#define STDIO_H

#include <stdarg.h>
#include <cstdio>

// Define the FILE structure
typedef struct {
    int fd; // File descriptor
    int flags; // File status flags
    long int pos; // Current position in the file
    char *buffer; // Buffer for file operations
} FILE;

FILE *stdin; // Standard input stream

// Writes a character to stdout
int putchar(int character);

// Reads a character from stdin
int getchar(void);

// Writes a string to stdout followed by a newline
int puts(const char *str);

// Reads a string from stdin
char *gets(char *str);
#endif