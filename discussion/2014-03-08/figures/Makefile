all: cfg-stmt.pdf cfg-block.pdf exploded-stmt.pdf

%.pdf: %.dot
	dot -Tpdf -o $@ $<

%.pdf: %.ipe
	ipetoipe -pdf $<

# allinone.pdf: allinone