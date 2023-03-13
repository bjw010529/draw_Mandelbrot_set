#include "writeBmp.h"

int header_size = 14;
int info_size = 40;
int iter_max = 200;
int height = HEIGHT;
int width = WIDTH; 
int byte_per_pixel = BYTE_PER_PIXEL;
unsigned char color[NUMBER_OF_LAYER + 1][3];/* = {
	{0x00, 0x00, 0x00},
	{0x00, 0x8f, 0xff},
	{0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00}
};*/
int fibo[NUMBER_OF_LAYER];
void get_fibo(){
	fibo[0] = 1;fibo[1] = 2;
	for(int i = 2; i < NUMBER_OF_LAYER; i++)
		fibo[i] = fibo[i-1] + fibo[i-2];
}
void initial_color(){
	get_fibo();
	color[1][1] = 0x8f; color[1][2] = 0xff;
	for(int i = 2; i < NUMBER_OF_LAYER; i ++)
		for(int j = 0; j < 3; j++)
			color[i][j] = color[i-1][j] * 9 / 10;
}
unsigned char image[HEIGHT][WIDTH][BYTE_PER_PIXEL];
unsigned char* get_color(int n){
	if(n == 0)
		return color[1];
	for(int i = 1; i < NUMBER_OF_LAYER; i++)
		if(n >= fibo[i-1] && n < fibo[i] )
			return color[i+1];
	return color[0];
}


void buildBmp(unsigned char* image, int height, int width, char* filename){
	int widthInBytes = width * byte_per_pixel;

	unsigned char padding[3] = {0, 0, 0};
	int paddingSize = (4 - (widthInBytes) % 4) % 4;

	int stride = (widthInBytes) + paddingSize;

	FILE* imageFile = fopen(filename, "wb");

	unsigned char* fileHeader = createFileHeader(height, stride);
	fwrite(fileHeader, 1, header_size, imageFile);

	unsigned char* infoHeader = createFileInfo(height, width);
	fwrite(infoHeader, 1, info_size, imageFile);
	
	for (int i = 0; i < height; i++) {
		fwrite(image + (i*widthInBytes), byte_per_pixel, width, imageFile);
		fwrite(padding, 1, paddingSize, imageFile);
	}

	fclose(imageFile);
}


unsigned char* createFileHeader(int height, int stride){
	int filesize = header_size + info_size + (height * stride);
	static unsigned char fileheader[] = {
		(unsigned char)('B'), (unsigned char)('M'),
		(unsigned char)(filesize),(unsigned char)(filesize >> 8),(unsigned char)(filesize >> 16),(unsigned char)(filesize >> 24),
		0,0,0,0,	//reserved
		0,0,0,0 	//size of header
	};
	fileheader[10] =(unsigned char)(header_size + info_size);
	//cout << "fileHeader:" << fileheader << "end" << endl;
	return fileheader;
}


unsigned char* createFileInfo(int height, int width){

	static unsigned char infoheader[] = {
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,
		0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0
	};
	infoheader[ 0] = (unsigned char)(info_size);
	infoheader[ 4] = (unsigned char)(width    );
	infoheader[ 5] = (unsigned char)(width >>  8);
	infoheader[ 6] = (unsigned char)(width >> 16);
	infoheader[ 7] = (unsigned char)(width >> 24);
	infoheader[ 8] = (unsigned char)(height   );
	infoheader[ 9] = (unsigned char)(height >>  8);
	infoheader[10] = (unsigned char)(height >> 16);
	infoheader[11] = (unsigned char)(height >> 24);
	infoheader[12] = (unsigned char)(1);
	infoheader[14] = (unsigned char)(byte_per_pixel*8);
	return infoheader;
}

