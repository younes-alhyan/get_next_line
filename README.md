_This project has been created as part of the 42 curriculum by yalahian._

## Description

`get_next_line` is a project where you have to create a function that only reads one line from a file per each function call. For example :

- `file.txt:`

```text
Line 1
Line 2
Line 3
```

- `test.c:`

```c
#include "get_next_line.h"
#include <fcntl.h>

int main()
{
    int fd = open("file.txt", O_RDONLY);
    if (!fd)
        return (1);
    get_next_line(fd); // "Line 1\n"
    get_next_line(fd); // "Line 2\n"
    get_next_line(fd); // "Line 3\n"
    get_next_line(fd); // NULL
    return (0);
}
```

The main goal of this project is to learn how to work with `static` variables, as well as learning how to interact with files in `C`.

## Instructions

To run the programme you'll just have to compile it it by running :

```shell
    # Mandatory
    cc get_next_line.c get_next_line_utils_bonus.c <main_file> -o <output_file>
    # Bonus
    cc get_next_line_bonus.c get_next_line_utils_bonus.c <main_file> -o <output_file>
```

Just make sure that the `get_next_line.h` (or `get_next_line_bonus.h`) is in the same path as the source files.

## Resources

### Refferences

- [Unix/Linux Files Explained - what is an inode? (hardlinks, symlinks, etc.)](https://youtu.be/ScDv02ff8oc)
- [File Descriptors: the table of integers behind \*nix file I/O](https://youtu.be/QRZUqmf0PR4)
- [Memory Segments in C/C++](https://youtu.be/2htbIR2QpaM)
- [Linux kernal `file` struct](https://github.com/torvalds/linux/blob/master/include/linux/fs.h#L1255)
- [File Descriptor](https://en.wikipedia.org/wiki/File_descriptor)
- [User space and kernel space](https://en.wikipedia.org/wiki/User_space_and_kernel_space)

### AI usage

- Variable naming suggestions & coding convention tips
- Markdown & Git command quick references
- Edge case identification for rigorous testing
- Detailed explanations for difficult concepts

## Algorithm Explanation

- **Step 1:** Define a `char *buffer` to read file contents into, a `static char *stash` to accumulate and save leftover data across function calls, and a `char *line` to store and return the current line.
- **Step 2:** Loop to read from the file into the `buffer` and append it to the `stash` as long as the `stash` does not contain a newline (`'\n'`) and the read operation returns bytes greater than `0`.
- **Step 3:** Extract the current line from the `stash` (stopping at the first `'\n'` if it exists, or the `'\0'` string terminator if it doesn't) to assign to `line`.
- **Step 4:** Update the `stash` by removing the extracted line, leaving only the remaining bytes for the next function call.

> **Note :** The bonus uses the same algorithm except that it uses `static char *stash[1024]` instead of `static char *stash` to handle multiple file descriptors.
