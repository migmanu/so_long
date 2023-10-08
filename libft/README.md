# libft

## Functions index 

| Function | Prototype | Description | External functions | Notes |
|----------|-----------|-------------|--------------------|-------|
| isalpha | `int isalpha(int c);` | Checks if the given character is an alphabetic character. | - | - |
| isdigit | `int isdigit(int c);` | Checks if the given character is a decimal digit. | - | - |
| isalnum | `int isalnum(int c);` | Checks if the given character is an alphanumeric character. | - | - |
| isascii | `int isascii(int c);` | Checks if the given character is a 7-bit ASCII character. | - | - |
| isprint | `int isprint(int c);` | Checks if the given character is a printable character (including space). | - | - |
| strlen | `size_t strlen(const char *s);` | Calculates the length of the given string. | - | - |
| memset | `void *memset(void *s, int c, size_t n);` | Fills the first n bytes of the memory area pointed to by s with the constant byte c. | - | - |
| bzero | `void bzero(void *s, size_t n);` | Fills the first n bytes of the memory area pointed to by s with zero bytes. | - | - |
| memcpy | `void *memcpy(void *dest, const void *src, size_t n);` | Copies n bytes from the memory area src to the memory area dest. | - | - |
| memmove | `void *memmove(void *dest, const void *src, size_t n);` | Copies n bytes from the memory area src to the memory area dest, even if they overlap. | - | - |
| strlcpy | `size_t strlcpy(char *dest, const char *src, size_t dest_size);` | Safely copies a C string (including the null terminator) to a fixed-size buffer. | - | - |
| strlcat | `size_t strlcat(char *dest, const char *src, size_t dest_size);` | Safely concatenates a C string (including the null terminator) to a fixed-size buffer. | - | - |
| toupper | `int toupper(int c);` | Converts the given character to uppercase. | - | - |
| tolower | `int tolower(int c);` | Converts the given character to lowercase. | - | - |
| strchr | `char *strchr(const char *s, int c);` | Returns a pointer to the first occurrence of the character c in the string s, or NULL if the character is not found. | - | - |
| strrchr | `char *strrchr(const char *s, int c);` | Returns a pointer to the last occurrence of the character c in the string s, or NULL if the character is not found. | - | - |
| strncmp | `int strncmp(const char *s1, const char *s2, size_t n);` | Compares up to the first n characters of two strings s1 and s2. | - | - |
| memchr | `void *memchr(const void *s, int c, size_t n);` | Searches the first n bytes of the memory area pointed to by s for the character c and returns a pointer to the first occurrence, or NULL if the character is not found. | - | - |
| memcmp | `int memcmp(const void *s1, const void *s2, size_t n);` | Compares the first n bytes of the memory areas s1 and s2. | - | - |
| strnstr | `char *strnstr(const char *haystack, const char *needle, size_t haystack_len);` | Locates the first occurrence of the null-terminated string needle in the string haystack, where the search is limited to the first haystack_len characters. | - | - |
| atoi | `int atoi(const char *str);` | Converts the initial portion of the string str to an integer. | - | - |
| calloc | `void *calloc(size_t nmemb, size_t size);` | Allocates memory for an array of nmemb elements, each of size bytes, and initializes the memory to zero. | - | - |
| strdup | `char *strdup(const char *s);` | Returns a pointer to a new string that duplicates the string s. | - | - |
| ft_substr | `char *ft_substr(char const *s, unsigned int start, size_t len);` | Allocates (with malloc(3)) and returns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’. | malloc | - |
| ft_strjoin | `char *ft_strjoin(char const *s1, char const *s2);` | Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’. | malloc | - |
| ft_strtrim | `char *ft_strtrim(char const *s1, char const *set);` | Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string. | malloc | - |
| ft_split | `char **ft_split(char const *s, char c);` | Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must end with a NULL pointer. | malloc, free | - |
| ft_itoa | `char *ft_itoa(int n);` | Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled. | malloc | - |
| ft_substr | `char *ft_substr(char const *s, unsigned int start, size_t len);` | Allocates (with malloc) and returns a substring from the string 's'. The substring begins at index 'start' and is of maximum size 'len'. | `malloc` | - |
| ft_strjoin | `char *ft_strjoin(char const *s1, char const *s2);` | Allocates (with malloc) and returns a new string, which is the result of the concatenation of 's1' and 's2'. | `malloc` | - |
| ft_strtrim | `char *ft_strtrim(char const *s1, char const *set);` | Allocates (with malloc) and returns a copy of 's1' with the characters specified in 'set' removed from the beginning and the end of the string. | `malloc` | - |
| ft_split | `char **ft_split(char const *s, char c);` | Allocates (with malloc) and returns an array of strings obtained by splitting 's' using the character 'c' as a delimiter. The array must end with a NULL pointer. | `malloc`, `free` | - |
| ft_itoa | `char *ft_itoa(int n);` | Allocates (with malloc) and returns a string representing the integer received as an argument. Negative numbers must be handled. | `malloc` | - |
| ft_strmapi | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` | Applies the function 'f' to each character of the string 's', and passing its index as the first argument to create a new string (with malloc) resulting from successive applications of 'f'. | `malloc` | - |
| ft_striteri | `void ft_striteri(char *s, void (*f)(unsigned int, char*));` | Applies the function 'f' on each character of the string passed as an argument, passing its index as the first argument. Each character is passed by address to 'f' to be modified if necessary. | - | - |
| ft_putchar_fd | `void ft_putchar_fd(char c, int fd);` | Outputs the character 'c' to the given file descriptor. | `write` | - |
| ft_putstr_fd | `void ft_putstr_fd(char *s, int fd);` | Outputs the string 's' to the given file descriptor. | `write` | - |
| ft_putendl_fd | `void ft_putendl_fd(char *s, int fd);` | Outputs the string 's' to the given file descriptor followed by a newline. | `write` | - |
| ft_putnbr_fd | `void ft_putnbr_fd(int n, int fd);` | Outputs the integer 'n' to the given file descriptor. | `write` | - |
| ft_lstnew | `t_list *ft_lstnew(void *content);` | Allocates (with malloc) and returns a new node. The member variable 'content' is initialized with the value of the parameter 'content'. The variable 'next' is initialized to NULL. | `malloc` | - |
| ft_lstadd_front | `void ft_lstadd_front(t_list **lst, t_list *new);` | Adds the node 'new' at the beginning of the list. | - | - |
| ft_lstsize | `int ft_lstsize(t_list *lst);` | Counts the number of nodes in a list. | - | - |
| ft_lstlast | `t_list *ft_lstlast(t_list *lst);` | Returns the last node of the list. | - | - |
| ft_lstadd_back | `void ft_lstadd_back(t_list **lst, t_list *new);` | Adds the node 'new' at the end of the list. | - | - |
| ft_lstdelone | `void ft_lstdelone(t_list *lst, void (*del)(void*));` | Takes a node as a parameter and frees the memory of the node's content using the function 'del', then frees the node. The memory of 'next' must not be freed. | `free` | - |
| ft_lstclear | `void ft_lstclear(t_list **lst, void (*del)(void*));` | Deletes and frees the given node and every successor of that node, using the function 'del' and free. Finally, the pointer to the list must be set to NULL. | `free` | - |
| ft_lstiter | `void ft_lstiter(t_list *lst, void (*f)(void *));` | Iterates the list 'lst' and applies the function 'f' on the content of each node. | - | - |
| ft_lstmap | `t_list *ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));` | Iterates the list 'lst' and applies the function 'f' on the content of each node. Creates a new list resulting from the successive applications of the function 'f'. The 'del' function is used to delete the content of a node if needed. | `malloc`, `free` | - |
