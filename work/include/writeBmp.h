#ifndef __WRITE_BMP__
#define __WRITE_BMP__ 

#include<iostream>
#include<cstdio>
#include<complex>
using namespace std;


#define HEIGHT 9000
#define WIDTH 16000
#define BYTE_PER_PIXEL 3
#define NUMBER_OF_LAYER 40

extern int header_size;
extern int info_size;
extern int iter_max;
extern int height;
extern int width; 
extern int byte_per_pixel;
extern unsigned char color[NUMBER_OF_LAYER+1][3];
extern int fibo[NUMBER_OF_LAYER];
int get_fibo(int n);
void initial_color();
unsigned char* get_color(int n);
void buildBmp(unsigned char* image, int height, int width, char* filename);
unsigned char* createFileHeader(int height, int stride);
unsigned char* createFileInfo(int height, int width);
extern unsigned char image[HEIGHT][WIDTH][BYTE_PER_PIXEL];



#endif