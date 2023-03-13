main : ./src/main.cpp ./include/writeBmp.cpp ./include/writeBmp.h 
	cd ./src && g++ -o main ../include/writeBmp.cpp main.cpp -g
	cd ./src && ./main ../image/tmp_colored_image_1.bmp -0.79  0.15
	cd ./src && ./main ../image/tmp_colored_image_2.bmp 0.28 0.085
	cd ./src && ./main ../image/tmp_colored_image_3.bmp -0.12 -0.77
	cd ./src && ./main ../image/tmp_colored_image_4.bmp -1.476 0

report:./doc/work.tex ./doc/work.bib ./doc/Makefile
	cd ./doc && make generate_tex

slide: ./doc
	cd ./doc && make generate_slide


.PHONY : clean