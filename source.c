#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;

    if (argc != 2)
    {
        printf("Usage: clang source.c <path_to_file> \n");
        exit(1);
    }

    FILE *ptr_in = fopen(argv[1], "rb");
    FILE *ptr_out = fopen("output.bmp", "w");

    unsigned char header[54];
    unsigned char colorTable[1024];

    for(int i = 0; i < 54; i++){
        header[i] = getc(ptr_in);
    }

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bitDepth = *(int*)&header[28];

    printf("Width: %i, Height: %i\n", width, height);

    if(bitDepth <= 8){
        fread(colorTable, sizeof(unsigned char), 1024 , ptr_in);
    }
    
    unsigned char buf[width*height];

    fread(buf, sizeof(unsigned char), (width*height), ptr_in);

    fwrite(header, sizeof(unsigned char), 54, ptr_out);

    if(bitDepth <= 8){
        fwrite(colorTable, sizeof(unsigned char), 54, ptr_out);
    }

    fwrite(buf, sizeof(unsigned char), (width*height), ptr_out);

    fclose(ptr_in);
    fclose(ptr_out);

    printf("End \n");
}