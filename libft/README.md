*This project has been created as part of the 42 curriculum by jcervera.*

# Libft

## Description

Libft is a custom C library developed as part of the 42 School curriculum. Its purpose is to recreate a collection of standard C library functions and implement additional utility functions that can be reused in future C projects.

The project focuses on understanding memory management, pointers, strings, linked lists, and low-level programming while following the 42 coding standards.

The library is compiled into a static library named `libft.a`, which can be linked to other C programs.

## Instructions

### Requirements

- A C compiler, such as `cc` or `gcc`.
- GNU Make.
- A Unix-like environment.

### Compilation

Clone the repository and navigate to its root directory:

```bash
git clone https://github.com/devxerve/libft.git
cd libft
```

Compile the library using:

```bash
make
```

This generates the static library `libft.a` in the project root directory.

### Makefile rules

| Command       | Description                                                |
| ------------- | ---------------------------------------------------------- |
| `make`        | Compiles the library.                                      |
| `make all`    | Builds the library using the default target.               |
| `make clean`  | Removes the object files (`.o`).                           |
| `make fclean` | Removes object files and the compiled library (`libft.a`). |
| `make re`     | Performs a full rebuild of the library.                    |

### Using the library

Include the library header in your C source file:

```c
#include "libft.h"
```

Compile your program and link it against `libft.a`:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o program
```

Run the resulting executable:

```bash
./program
```

The compiler must be able to find `libft.h`; if your source file is in another directory, add the appropriate include path with `-I`.

## Library Reference

The following sections describe the functions implemented in the library. Each description summarizes the purpose of one function.

### Character Checks and Conversion

| Function     | Description                                                                |
| ------------ | -------------------------------------------------------------------------- |
| `ft_isalpha` | Checks whether a character is an uppercase or lowercase alphabetic letter. |
| `ft_isdigit` | Checks whether a character is a decimal digit (`0`–`9`).                   |
| `ft_isalnum` | Checks whether a character is an alphabetic letter or a decimal digit.     |
| `ft_isascii` | Checks whether a value belongs to the ASCII character set (`0`–`127`).     |
| `ft_isprint` | Checks whether a character is printable, including the space character.    |
| `ft_toupper` | Converts a lowercase alphabetic character to uppercase.                    |
| `ft_tolower` | Converts an uppercase alphabetic character to lowercase.                   |

### String and Memory Functions

| Function      | Description                                                                                          |
| ------------- | ---------------------------------------------------------------------------------------------------- |
| `ft_strlen`   | Returns the length of a string, excluding the terminating null character.                            |
| `ft_memset`   | Fills a memory block with a specified byte value.                                                    |
| `ft_bzero`    | Sets every byte in a memory block to zero.                                                           |
| `ft_memcpy`   | Copies a specified number of bytes between non-overlapping memory regions.                           |
| `ft_memmove`  | Copies bytes between memory regions, including overlapping regions.                                  |
| `ft_memchr`   | Searches a memory block for the first occurrence of a byte.                                          |
| `ft_memcmp`   | Compares two memory blocks byte by byte.                                                             |
| `ft_calloc`   | Allocates memory for an array of elements,all bytes initalized to 0, returns a pointer to the array. |
| `ft_strlcpy`  | Copies a string into a size-limited destination buffer and returns the source length.                |
| `ft_strlcat`  | Appends a string to a size-limited destination buffer and returns the length it attempted to create. |
| `ft_strchr`   | Finds the first occurrence of a character in a string.                                               |
| `ft_strrchr`  | Finds the last occurrence of a character in a string.                                                |
| `ft_strncmp`  | Compares two strings up to a specified number of characters.                                         |
| `ft_strnstr`  | Searches for a substring within a string, limiting the search to a specified length.                 |
| `ft_strdup`   | Allocates memory for and returns a duplicate of a string.                                            |
| `ft_substr`   | Allocates and returns a substring starting at a specified index.                                     |
| `ft_strjoin`  | Allocates and returns a new string formed by concatenating two strings.                              |
| `ft_strtrim`  | Allocates and returns a string with specified characters removed from both ends.                     |
| `ft_split`    | Splits a string into an array of substrings using a delimiter.                                       |
| `ft_strmapi`  | Applies a function to each character of a string and returns a newly allocated result.               |
| `ft_striteri` | Applies a function to each character of a string, passing its index and a pointer to the character.  |

### Conversion and Output Functions

| Function        | Description                                                                     |
| --------------- | ------------------------------------------------------------------------------- |
| `ft_atoi`       | Converts the initial numeric portion of a string into an integer.               |
| `ft_itoa`       | Allocates and returns the string representation of an integer.                  |
| `ft_putchar_fd` | Writes a character to a specified file descriptor.                              |
| `ft_putstr_fd`  | Writes a string to a specified file descriptor.                                 |
| `ft_putendl_fd` | Writes a string followed by a newline to a specified file descriptor.           |
| `ft_putnbr_fd`  | Writes the decimal representation of an integer to a specified file descriptor. |

### Linked List Functions

These functions operate on the `t_list` singly linked list structure, typically defined in `libft.h`.

| Function          | Description                                                                                           |
| ----------------- | ----------------------------------------------------------------------------------------------------- |
| `ft_lstnew`       | Allocates and initializes a new list node with the given content.                                     |
| `ft_lstadd_front` | Adds a node to the beginning of a linked list.                                                        |
| `ft_lstsize`      | Returns the number of nodes in a linked list.                                                         |
| `ft_lstlast`      | Returns the last node of a linked list.                                                               |
| `ft_lstadd_back`  | Adds a node to the end of a linked list.                                                              |
| `ft_lstdelone`    | Deletes a single list node and frees its content using a specified function.                          |
| `ft_lstclear`     | Deletes all nodes in a linked list and sets the list pointer to `NULL`.                               |
| `ft_lstiter`      | Applies a function to the content of every node in a linked list.                                     |
| `ft_lstmap`       | Creates a new list by applying a function to each node's content, with cleanup on allocation failure. |

## Resources

The following resources were useful for understanding the expected behavior of standard C functions and implementing the library:

- **C standard library documentation:** [https://en.cppreference.com/w/c](https://en.cppreference.com/w/c)
- **Linux manual pages:** [https://man7.org/linux/man-pages/](https://man7.org/linux/man-pages/)
- **42 School:** [https://42.fr/](https://42.fr/)
- **Paco testing suite for 42** [https://github.com/sanlega/paco.git](https://github.com/sanlega/paco.git) (Credits to [sanlega]\([https://github.com/sanlega](https://github.com/sanlega)))

### Artificial Intelligence Usage

Artificial intelligence was used as a supplementary learning tool to clarify algorithms, understand expected function behavior, and interpret relevant manual (`man`) page entries.

Its use was limited to technical clarification and understanding of inputs, outputs, and edge cases. The project was developed and tested within the context of the 42 curriculum, and the implementation should be reviewed and understood by the author.

## Project Structure

The project  contains:

- `libft.h` — Function prototypes and shared type definitions.
- `Makefile` — Build rules for compiling the source files into `libft.a`.
- `*.c` — The source files implementing the library functions.
- `*.o` — Object files generated during compilation.
- `libft.a` — The compiled static library.

## License

This project was created for educational purposes as part of the 42 School curriculum.
