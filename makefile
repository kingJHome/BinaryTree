files = main.c biTree.c

main: $(files)
	gcc -o $@ $^

maintest: $(files)
	gcc -g $^ -o $@
