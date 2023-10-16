#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

			/* FLAGS */

#define FlagMinus 1
#define FlagPlus 2
#define FlagZero 4
#define FlagHash 8
#define FlagSpace 16

			/* SIZES */

#define STRING_LONG 2
#define STRING_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: Function associated.
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: Function associated.
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handlePrint(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

			/*                    FUNCTIONS                */

			/* Functions for printing characters and strings */

int printChar(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int printString(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int printPercent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

			/* Functions for printing numbers */

int printInt(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int printBinary(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int printUnsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int printOctal(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int printLowerHexa(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int printUpperHexa(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int printHexadecimal(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

			/* Function for printing unprintable characters */

int printUnprintable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

			/* Function for printing memory address */

int printPointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

			/* Functions for handling other specifiers */

int _flags(const char *format, int *i);
int _width(const char *format, int *i, va_list list);
int _precision(const char *format, int *i, va_list list);
int _size(const char *format, int *i);

			/* Function to print string in reverse */

int printReverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

			/* Function to print a string in rot 13 */

int printString_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size);

			/* Handles width */

int handleWriteChar(char c, char buffer[],
	int flags, int width, int precision, int size);

int writeNumber(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);

int writeNum(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);

int writePointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int writeUnsigned(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

			/*      UTILS    */

int printability(char);
int appnd_hex_code(char, char[], int);
int is_digit(char);

long int conv_sz_num(long int num, int size);
long int conv_sz_unsigned(unsigned long int num, int size);

#endif /* MAIN_H */
