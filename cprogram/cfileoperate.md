# File Operation with C

1. Head file:<br>`stdio.h`

2. File Read:

    > Open file

    ```c
    FILE *fp = NULL;
    //mode for read: "r"(read only and file exists), "r+", "rb", "r+b"
    //mode for read: "w"(open a file and write into it, if it doesn't exist, and new a file), "w+", "wb", "w+b"
    //mode for read: "a"(append the content into the end of the file), "a+", "ab", "a+b"
    fp = fopen(const char *path_file_name, const char* mode);
    ```

    > Read file

    ```c
    char ch;

    /* one */
    ch = fgetc(fp);    // ch = getc(fp);    //works the same
                       // ch = getchar();   //get character from standard stream
                       // ch = gets();      //get string from standard stream
    /* one */

    char c_str[80];
    int size;

    /* two */
    char *s = fgets(c_str, size, fp);
    /* two */

    char str[80];

    /* three */
    fscanf(fp, "%s", str);
    /* three */

    printf("%s", str);
    ```

3. File Write
    
    > Open file

    > Write file
