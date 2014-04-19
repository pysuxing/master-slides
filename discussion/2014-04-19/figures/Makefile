all: 

%.pdf: %.dot
	dot -Tpdf -o $@ $<

%.pdf: %.ipe
	ipetoipe -pdf $<

clean:
	-rm -f $(all) *~