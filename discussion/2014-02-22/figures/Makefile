all: callgraph.pdf clangtool-structure.pdf

# hierachy.pdf: hierachy.dot
# 	dot -Tpdf -o $@ $<

# forward.pdf: forward.dot
# 	dot -Tpdf -o $@ $<

%.pdf: %.dot
	dot -Tpdf -o $@ $<

%.pdf: %.ipe
	ipetoipe -pdf $<

# allinone.pdf: allinone