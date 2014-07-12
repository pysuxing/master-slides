all: ipdps12-load-banlancing.pdf

%.pdf: %.dot
	dot -Tpdf -o $@ $<

%.pdf: %.ipe
	ipetoipe -pdf $<

clean:
	-rm -f $(all) *~