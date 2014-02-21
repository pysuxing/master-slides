all: clangtool-structure.pdf visiting-scheme.pdf

clangtool-structure.pdf: clangtool-structure.ipe
	ipetoipe -pdf $<

visiting-scheme.pdf: visiting-scheme.dot
	dot -Tpdf -o $@ $<