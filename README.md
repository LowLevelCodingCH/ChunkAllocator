# Chunk Allocator (MWrite)
## Usecases:
### - You can allocate memory, so use it ig
## How to use:
### To allocate a string, you do:
```c
char* string = (char*)mwrite(sizeof(char)*15);
string = "Hello, world!\n\0";
// Do stuff with the string
mfree(string);
```
