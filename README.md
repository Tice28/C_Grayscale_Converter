# C Grayscale Image Converter

## Purpose

The purpose of this project was to exercise skills learned reading through a book on programming in C.

This project allows the user to convert .bmp files to grayscale. It reads the file, saves its header in a buffer, and takes the image data and converts it to grayscale. This converted data is stored in another buffer and it written out to a file that, by default, is labeled "output.bmp".

## Tech Stack

- Ubunutu v22.04
- C programming language
- Clang for compiling the C code

## How to Use

1. First, clone the repo.
2. Next, navigate to the repo and make it your active directory.
3. Run the following command to compile the program (assuming you've installed <a href="https://clang.llvm.org/get_started.html">clang</a>).

```
clang source.c
```

4. Once you have compiled it, you should see a new file called a.out, now you should be able to execute the grayscale converter with the following command:

```
./a.out <file_path>
```

5. Finally, it should output your converted image as output.bmp.

### Like the project? Check out my other work <a href="https://github.com/tice28">here</a>.

### Want to get in touch?

Feel free to email me at trisstonprogramming@gmail.com
