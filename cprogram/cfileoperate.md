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

    /****** one ******/
    ch = fgetc(fp);    // ch = getc(fp);    //works the same
                       // ch = getchar();   //get character from standard stream
                       // ch = gets();      //get string from standard stream
    /****** one ******/

    char c_str[80];
    int size;

    /****** two ******/
    char *s = fgets(c_str, size, fp);
    /****** two ******/

    char str[80];

    /****** three ******/
    fscanf(fp, "%s", str);
    /****** three ******/

    printf("%s", str);
    ```

3. File Write
    
    > Open file

    ```c
    // the same as part of Read file
    ```

    > Write file

    ```c
    char ch = 'e';
    char *str;

    /****** one ******/
    fputc(ch, fp);     // putc(ch, fp);    //works the same
                       // putchar(ch);     //enter character from standard stream
                       // puts(str);       //enter string from standard stream
    /****** one ******/

    char c_str[80];
    int size;

    /****** two ******/
    fputs(c_str, fp);
    /****** two ******/

    char str[80];

    /****** three ******/
    fprintf(fp, "%s\n", str);
    /****** three ******/

    printf("%s", str);

    /****** four ******/
    fwrite();    //TODO(edony):finish it
    ```

4. File Redirection

    > Redirection

    ```c
    if (feof(fp)) printf("Get the end of file");

    freopen(const char *file_path, const char *file_modle, FILE *fp);

    fseek(FILE *fp, long offset, int whence);    //whence: SEEK_SET for the start of the file
                                                 //        SEEK_END for the end of the file
                                                 //        SEEK_CUR for current position of the file
    ftell(fp);                                   //current position
    ```
