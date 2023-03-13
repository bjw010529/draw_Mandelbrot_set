generate_tex: work.tex ./ref/ref.bib
	xelatex work.tex
	bibtex work.aux
	xelatex work.tex
	xelatex work.tex

generate_slide: slide1.tex ./ref/ref.bib
	xelatex slide1.tex
	xelatex slide1.tex
	bibtex slide1.aux
	xelatex slide1.tex
	xelatex slide1.tex

clear: work.tex work.bib
	rm work.bbl
	rm work.aux
	rm work.blg
	rm work.log
	rm work.pdf

.PHONY : clean