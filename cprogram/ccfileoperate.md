# File operation with c++

File stream in c++

    ![](https://github.com/edonyM/PLC/blob/master/cprogram/pic/streamincpp.png)

    ```c
    #include <fstream>
    #include <cstring>  // for c_style string function, strlen(), strcpy(), strcmp()...

    ofstream out;    // class for writing into file(derived from ostream)
    ifstream in;     // class for read from file(derived from istream)
    fstream in_out;  // class for read and write with file(derived from iostream)

    // Open file
    out.open(const char *file_name, openmode mode);    //open mode:
                                                       // std::ios::in
                                                       // std::ios::out
                                                       // std::ios::ate
                                                       // std::ios::app
                                                       // std::ios::trunc
                                                       // std::ios::binary
    // another way to open file
    ofstream out_other(const char *file_name, openmode mode);    //ifstream and fstream get the same way

    // Check open is successful
    out.is_open();              // return bool

    // Write text into file
    out << "This ofstream writing\n";
    out.put('e');
    char str[80] = "edony";
    out.write(str, strlen(str));

    // Close file
    out.close();
    
    // Read from file
    in.open(const char *file_name, openmode mode);
    char buffer[256];
    char ch;
    in >> buffer;                       // stops when encounter with blank, '\0', '\n'
    in.get(ch);
    in.get(buffer, 256);                // in.get(buffer, 256, 0);
    in.read(buffer, sizeof(buffer));    // note about the difference between sizeof() and strlen()
                                        // sizeof(c_str) == strlen(c_str) + 1
    in.getline(buffer, 256);            // in.geline(buffer, 100, 0)
                                        //     change the termination with '\n' into '\0'

    // File redirection
    in.seekg(stream off_set, seek_dir origin);    // in.seekg(0, ios::beg);
                                                  // in.seekg(0, ios::end);
                                                  // in.seekg(100, ios::cur);
    out.seekp(stream off_set, seek_dir origin);   // the same

    // File flags
    // ofstream get the same
    in.bad();    // get error when read or write
    in.fail();   // when in.bad() return true
    in.eof();    // end of file
    in.good();   // when not fail() return true
    in.clear();  // when your want to reset the flags
                 //   for example, you want to read the file again while it has already read into the eof().
                 //   You need to reset the flag and seek the position into the head.

    // Position of stream
    in.tellg();  // get stream position
    /*** one application ***/
    in.clear();
    in.seekg(0, ios::beg);
    int start;
    start = in.tellg();
    in.clear();
    in.seekg(0, ios::end);
    int end;
    end = in.tellg();
    int bytes = end - start;
    cout << "the file size is " << bytes << endl;
    /*** one application ***/
    out.tellp(); // put stream position
    // TODO(edony): some other stream operation needs to be learned
    ```


