DOC = ./doc/
SRC = ./src/
report: $(DOC)report.tex
	xelatex $(DOC)report.tex
bin:$(SRC)roots.c
	gcc -o bin $(SRC)roots.c -I/home/changyijui/myinstall/include -L/home/changyijui/myinstall/lib -lgsl -lgslcblas -lm

