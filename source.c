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
    FILE *ptr_out = fopen("output.bmp", "wb");

    unsigned char header[54];
    unsigned char colorTable[1024];

    for(int i = 0; i < 54; i++){
        header[i] = getc(ptr_in);
    }

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bitDepth = *(int*)&header[28];
    int size = height*width * (bitDepth/8);
    int bytePerPixel = bitDepth/8;

    if(bitDepth <= 8){
        fread(colorTable, sizeof(unsigned char), 1024 , ptr_in);
    }
    
    unsigned char buf[size];

    fread(buf, sizeof(unsigned char), size, ptr_in);

    fwrite(header, sizeof(unsigned char), 54, ptr_out);

    if(bitDepth <= 8){
        fwrite(colorTable, sizeof(unsigned char), 1024, ptr_out);
    }
    

    for(int j = 0; j < size;j+=bytePerPixel){
        int gray = buf[j] *.3 + buf[j+1] * .59 + buf[j+2] * .11;
        buf[j] = buf[j+1] = buf[j+2] = gray;
    }

    fwrite(buf, sizeof(unsigned char), size, ptr_out);

    fclose(ptr_in);
    fclose(ptr_out);

    printf("End \n");
}