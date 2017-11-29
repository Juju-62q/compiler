CC = gcc
YACC = yacc -d -v
LEX = lex

parser: y.tab.o lex.yy.o
	$(CC) -o parser y.tab.o lex.yy.o -lfl

y.tab.o: parser.y
	$(YACC) parser.y
	$(CC) y.tab.c -c -lfl

lex.yy.o: scanner.l y.tab.h
	$(LEX) scanner.l
	$(CC) lex.yy.c -c -lfl

clean:
	rm -f *.o lex.yy.c y.tab.c y.tab.h

