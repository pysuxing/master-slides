DOTSOURCES = $(wildcard *.dot)
DOTFIGURES = $(DOTSOURCES:.dot=.pdf)
ASYFIGURES = lu0.pdf

once: slides.pdf

slides.pdf: slides.tex $(DOTFIGURES) $(ASYFIGURES)
	xelatex slides

%.pdf: %.dot
	dot -Tpdf -o $@ $<

$(ASYFIGURES): lumatrix.asy
	asy $<

twice: once
	xelatex slides

clean:
	-rm -f *~
