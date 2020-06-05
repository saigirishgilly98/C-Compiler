rm ./a.out
yacc parser.y -Wnone
lex scanner.l
gcc y.tab.c -ll -ly -w 
echo "                     Test Case a: 		     "
./a.out testa.c 
echo "                     Test Case b: "
./a.out testb.c
echo "                     Test Case c: "
./a.out testc.c
echo "                     Test Case d: "
./a.out testd.c
echo "                     Test Case e: "
./a.out teste.c

