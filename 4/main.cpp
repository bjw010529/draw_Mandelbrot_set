#ifndef __MAIN__
#define __MAIN__

#include "./include/writeBmp.h"
using namespace std;
#pragma GCC optimize(2)

int main(int argc, char* argv[])
{
	initial_color();
	char* filename = (char*) "./image/colored_image.bmp";
	int mode = 1;//默认为彩色模式
	if(argc == 2){
		filename = argv[1];
	}
	else if(argc == 3){
		filename = argv[1];
		sscanf(argv[2], "%d", &iter_max);
	}
	else if(argc == 4){
		filename = argv[1];
		sscanf(argv[2], "%d", &mode); 
		sscanf(argv[3], "%d", &iter_max); 
	}

	
	double scale = min(width,height) / 2.5;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			double tmpx = (j - width / 2.0) / scale;
			double tmpy = (i - height / 2.0) / scale;
			complex<double> c = {tmpx, tmpy};
			complex<double> z;
			for(int n = 0; n < iter_max; n++){
				if(norm(z) > 4){
					if(mode == 1){
						unsigned char* tmp = get_color(n);
						image[i][j][0] = tmp[0];
						image[i][j][1] = tmp[1];
						image[i][j][2] = tmp[2];
					}
					else if(mode == 0){
						image[i][j][0] = 0xff;
						image[i][j][1] = 0xff;
						image[i][j][2] = 0xff;
					}
					goto label;
				}
				z = z * z + c;
			}
			image[i][j][0] = 0x00;
			image[i][j][1] = 0x00;
			image[i][j][2] = 0x00;
			label:{}
		}

	buildBmp((unsigned char*) image,height,width,filename);
	printf("Built successfully!\n");
	//delete image;
	return 0;
		
}

#endif