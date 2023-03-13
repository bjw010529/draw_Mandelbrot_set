OBJDIR = image
mkdir_shell = $(shell if [ ! -d $(OBJDIR) ]; then echo "noexist"; else echo "exist"; fi)

ifeq ("$(mkdir_shell)", "noexist")
$(shell mkdir -p $(OBJDIR))
endif
$(info $(mkdir_shell))

main : main.cpp ./include/writeBmp.cpp ./include/writeBmp.h ./paper/Makefile ./paper/work.tex ./paper/work.bib
	g++ -o main ./include/writeBmp.cpp main.cpp -g
	./main ./image/colored_image.bmp
	cd ./paper && make generate_tex 

get_origin_pic:main.cpp ./include/writeBmp.cpp ./include/writeBmp.h
	g++ -o main ./include/writeBmp.cpp main.cpp -g
	./main ./image/origin_image.bmp 0 200



.PHONY : clean