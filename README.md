*This project has been created as part of the 42 curriculum by sbadandi.*

# Libft

## Description

Libft is the first project of the 42 common core. Its goal is to build a personal C library by reimplementing a set of standard libc functions, adding a few extra utility functions, and then reusing this library in all later 42 projects.

By writing these functions from scratch, the project teaches how they behave internally and where their edge cases are: pointer arithmetic, byte-level memory handling, dynamic allocation with `malloc`, integer overflow, and writing clean code under the 42 Norm. No standard library functions are allowed beyond those the subject explicitly permits (`malloc`, `free`, `write`).

### Overview

The library is compiled into a static archive, `libft.a`, and is split into three parts:

1. **Libc functions**: reimplementations of standard functions, with the same prototypes and behavior, prefixed with `ft_`.
2. **Aditional functions**: utilities that are not in libc or that are in a different form, mostly for strings and file-descriptor output.
3. **lists management**: a small linked-list API built on the `t_list` structure.

## Instructions

### Requirements

- `cc` (or `gcc` / `clang`)
- `make`
- `ar`

### Compilation

```sh
make          # build libft.a (mandatory part)
make bonus    # build libft.a including the linked-list functions
make clean    # remove object files
make fclean   # remove object files and libft.a
make re       # fclean, then rebuild
```

All files are compiled with `-Wall -Wextra -Werror`.

### Usage

Include the header in your code:

```c
#include "libft.h"
```

Compile your program against the library:

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
./my_program
```

### Example

```c
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	printf("%s\n", ft_strrchr("hello world", 'o'));  // orld
	printf("%d\n", ft_atoi("  -12abc"));             // -12
	return (0);
}
```

## Library description

### Part 1: libc functions

| Function | Description |
|---|---|
| `ft_isalpha` | Returns non-zero if `c` is a letter. |
| `ft_isdigit` | Returns non-zero if `c` is a digit. |
| `ft_isalnum` | Returns non-zero if `c` is a letter or a digit. |
| `ft_isascii` | Returns non-zero if `c` is in the ASCII range (0 to 127). |
| `ft_isprint` | Returns non-zero if `c` is a printable character. |
| `ft_toupper` | Converts a lowercase letter to uppercase. |
| `ft_tolower` | Converts an uppercase letter to lowercase. |
| `ft_strlen` | Returns the length of a string, not counting the `'\0'`. |
| `ft_strchr` | Returns a pointer to the first occurrence of `c` in a string, or `NULL`. |
| `ft_strrchr` | Returns a pointer to the last occurrence of `c` in a string, or `NULL`. The terminating `'\0'` is treated as part of the string. |
| `ft_strncmp` | Compares up to `n` characters of two strings as `unsigned char`. |
| `ft_strnstr` | Finds the first occurrence of a substring within the first `len` characters of a string. |
| `ft_strlcpy` | Copies a string into a buffer of a given size, always null-terminating, and returns the length of the source. |
| `ft_strlcat` | Appends a string to a buffer of a given size, always null-terminating, and returns the length it tried to create. |
| `ft_strdup` | Returns a newly allocated copy of a string. |
| `ft_memset` | Fills the first `n` bytes of a memory area with a byte value. |
| `ft_bzero` | Sets the first `n` bytes of a memory area to zero. |
| `ft_memcpy` | Copies `n` bytes from one memory area to another (areas must not overlap). |
| `ft_memmove` | Copies `n` bytes between memory areas that may overlap. |
| `ft_memchr` | Finds the first occurrence of a byte in a memory area. |
| `ft_memcmp` | Compares two memory areas byte by byte. |
| `ft_calloc` | Allocates zero-initialized memory for `nmemb` elements, returning `NULL` if `nmemb * size` would overflow. |
| `ft_atoi` | Converts the beginning of a string to an `int`, handling leading whitespace and one optional sign. |

### Part 2: additional functions

| Function | Description |
|---|---|
| `ft_substr` | Returns a new string extracted from a string, starting at a given index with a maximum length. |
| `ft_strjoin` | Returns a new string made of two strings concatenated. |
| `ft_strtrim` | Returns a copy of a string with the given set of characters removed from both ends. |
| `ft_split` | Splits a string by a delimiter character into a `NULL`-terminated array of newly allocated strings. |
| `ft_itoa` | Converts an integer to a newly allocated string, including negative numbers and `INT_MIN`. |
| `ft_strmapi` | Applies a function to each character of a string and returns a new string with the results. |
| `ft_striteri` | Applies a function to each character of a string, passing its index. |
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

### Part 3: linked lists

The list functions work on this structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node holding the given content. |
| `ft_lstadd_front` | Adds a node at the beginning of a list. |
| `ft_lstsize` | Counts the nodes in a list. |
| `ft_lstlast` | Returns the last node of a list. |
| `ft_lstadd_back` | Adds a node at the end of a list. |
| `ft_lstdelone` | Frees one node's content with a given function, then frees the node. |
| `ft_lstclear` | Deletes and frees a node and all the nodes after it. |
| `ft_lstiter` | Applies a function to the content of every node. |
| `ft_lstmap` | Builds a new list by applying a function to each node's content, cleaning up on allocation failure. |

### Technical choices

- **Same behavior as libc.** Each reimplemented function follows the prototype and edge-case behavior of its man page (`man 3 <function>`), such as the `'\0'` case in `ft_strrchr`, the `unsigned char` comparison in `ft_strncmp`, and the single sign allowed in `ft_atoi`.
- **Overflow protection.** `ft_calloc` checks that `nmemb * size` does not overflow `size_t` before calling `malloc`.
- **Memory safety.** Functions that allocate return `NULL` on failure and free any partial allocations (for example `ft_split` and `ft_lstmap`).
- **Norm compliance.** All code follows the 42 Norm and is checked with `norminette`.

## Resources

### References

- `man 3 <function>` pages for each reimplemented libc function
- *The C Programming Language*, Brian W. Kernighan and Dennis M. Ritchie
- [The 42 Norm and norminette](https://github.com/42School/norminette)
- [cppreference: C standard library](https://en.cppreference.com/w/c)
- Peer discussions and peer evaluations at 42 Irbid

### Use of AI

AI (Claude) was used as a learning and writing aid, not to write the library code. Specifically:

- **Understanding functions:** explanations of what `strrchr`, `memset`, `atoi`, `strncmp` and `calloc` do, including edge cases (the `'\0'` case in `strrchr`, the byte-wise behavior of `memset`, the overflow check in `calloc`).
- **Testing:** examples of test cases and a sample `main.c` for checking my functions against the real libc.
- **Documentation:** help writing this README and a sample man page layout.

The implementations in `libft.a` were written, tested, and understood by me.
