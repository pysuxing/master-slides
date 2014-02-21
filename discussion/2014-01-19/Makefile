slides.pdf: slides.tex submake
	xelatex $<
	xelatex $<

submake:
	make -C listings
	make -C figures

view:
	mupdf slides.pdf

clean:
	-rm -f slides.pdf