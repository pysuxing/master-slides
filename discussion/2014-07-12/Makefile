slides.pdf: slides.tex submake bib
	xelatex $<
	xelatex $<

bib: slides.tex
	xelatex $<
	bibtex slides

submake:
	# make -C listings
	make -C figures

view:
	mupdf slides.pdf

clean:
	-rm -f slides.pdf *.log *.nav *.out *.toc *.aux *.snm *.blb *.blg *~