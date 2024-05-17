/* A file might be inddented either by spaces or by tabs. It's important 
 * to stick to the same indentation style such that the code is readable.
 * It is matter of personal choise. 
 */

/* 
 * There are a standard library that contains standard functions 
 * and some wrappers for os features such as memory allocation and 
 * file operations 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* A structure is a way of declaring how something 
 * should be represented in memory and grouping data. 
 */
struct memory_layout
{
	uint32_t	x;
	int8_t		c;
};


//A function might return a value 
int print_layout(struct memory_layout *p)
{
	/* Note that the layout declared is not 
	 * the same as printed as the compiler might 
	  add some at the end. */
	uint8_t *v = (uint8_t *)p;
	for(uint32_t i = 0; i < sizeof(struct memory_layout); i++)
	{
		printf("%u,", v[i]);
	}
	printf("\n");

	return 32;
}

/* The os passes arguments from the command line.
 * run ./a.out arg1 arg2 arg3. The first arguemnt 
 * is allways the name of the executable. 
 **/
int main(int args, char *argv[])
{
	printf("Function arguments \n");
	for(int i = 0; i < args; i++)
	{
		/* Different types are formated differently, 
		 * %i indicates that the type is unsigned int
		 * %s indicates that the type is a null terminated 
		 * string. A null terminated string is a set of 
		 * characters where the last is 0 indicating the 
		 * end.
		 */ 
		printf("%i->%s", i, argv[i]);
	}
	printf("\n");
	
	/* i and j wont be visible outside of the brackets.
	 * a statment == is either true of false. if true it is 
	 * equal to 1 else it is 0. 
	 * */	
	{
		/* Both i and j contains the same binary representation 
		 * The valus are written using HEX, that is base 16 */
		unsigned char i = 0xFF;
		signed char j = 0xFF;
		
		/* This statement is true as they are equal 
		 * if j is used as an unsigned char. */
		unsigned char k = i == (unsigned char )j;

		/* This statement is false as they are not the same value */
		unsigned char l = i == j;

		printf("%u==%i, cast=%u, no cast=%u \n", i, j, k, l);

		i = 1;
		j = 1;

		/* This statement is true as they are the same value */
		l = i == j;
		printf("%u==%i, no cast=%u \n", i, j, l);
	}
	
	/* There are different ways of representing types */	
	{
		int8_t u = -1;
		uint8_t i = 8;

		int16_t o = -1000;
		int16_t k = 10000;

		int32_t p = 1000000;
		uint64_t v = p*p; 
		
		/* There are a system type that is the same size as the 
		 * computer operates on. etc 32-bit size for 32-bit system. 	
		 */
		size_t s = 1000;
		ssize_t g = -s;	
		
		/* If you dont assign a value the you dont know what it 
		 * contains */
		uint64_t dummy;
		printf("any value=%lu \n", dummy);

	}
	
	/* A string is a set of characters and is written as 
	 * "content of string " while a single character is
	 * written with 'C'.
	 **/
	{
		const char D = 'D';
		const char string[] = "This is a string";
	       	printf("char=%c, string=%s \n", D, string);
	}
	/* A pointer points to a block of memory. If a pointer is null(0)
	 * and the memory location is accessed then the program crashes. 
	 * It also happens that pointers point to memory that is freed. 
	 *
	 *  The * indicates that it point to a memory address and the 
	 *  the & symbol takes the address of a variable */
	 
	{
		uint8_t value = 8;

		uint8_t *value_ptr = &value;
		
		/* It is also possible to point to a pointer */
		uint8_t **value_ptr_ptr = &value_ptr;
		
		/* Print the memory address. Note that the last prints
		 * the address of value_ptr address.
		 */
		printf("pointers: %p %p %p \n", &value, value_ptr, value_ptr_ptr);
		
		/* Assign from pointer, i and j is now 8 */
		uint8_t i = *value_ptr;
		uint8_t j = **value_ptr_ptr;

		printf("Assigned: %u %u \n", i, j);
	
	}
	
	{	
		//Declare a varaible with the structure and assign values. 
		struct memory_layout a = {.x = 10, .c = 'A'};

		int result = print_layout(&a);

	}
	
	/* It is possible to request memory from the os if the size 
	 * is not known in advance.
	 * float can hold decimal values, double is double the resolution 
	 * of float. 
	 * */
	{
		float *numbers = (float *)malloc(sizeof(float) * 1000);

		//It is important to free the memory when it is no longer needed. 
		free(numbers);	
	}

	return 0;
}
