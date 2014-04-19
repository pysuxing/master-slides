all: anderson-0.pdf anderson-1.pdf anderson-2.pdf \
     anderson-3.pdf anderson-4.pdf anderson-5.pdf \
     steensgaard-0.pdf steensgaard-1.pdf steensgaard-2.pdf \
     steensgaard-3.pdf steensgaard-4.pdf steensgaard-5a.pdf steensgaard-5b.pdf steensgaard-5c.pdf

%.pdf: %.dot
	dot -Tpdf -o $@ $<

%.pdf: %.ipe
	ipetoipe -pdf $<

clean:
	-rm -f *.pdf *~