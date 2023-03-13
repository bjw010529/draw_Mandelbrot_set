generate_tex: work.tex work.bib
	xelatex work.tex
	bibtex work.aux
	xelatex work.tex
	xelatex work.tex

clear: work.tex work.bib
	rm work.bbl
	rm work.aux
	rm work.blg
	rm work.log
	rm work.pdf

.PHONY : clean