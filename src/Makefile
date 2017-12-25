CC = gcc
YACC = yacc -d -v
LEX = lex

parser: y.tab.o lex.yy.o stack.o makeCode.o
	$(CC) -o parser y.tab.o lex.yy.o stack.o makeCode.o -ll

y.tab.o: parser.y stack.h optype.h code.h
	$(YACC) parser.y
	$(CC) y.tab.c -c -ll

lex.yy.o: scanner.l y.tab.h stack.h optype.h
	$(LEX) scanner.l
	$(CC) lex.yy.c -c -ll

stack.o: stack.c stack.h
	$(CC) stack.c -c

.PHONY: clean rebuild
clean:
	rm -f *.o lex.yy.c y.tab.c y.tab.h y.output result.code

rebuild: clean parser

