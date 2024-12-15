md2html: md2html.o
	${CC} -o md2html md2html.o `pkg-config --libs lowdown` -lm -static -pie 
md2html.o:
	${CC} -pedantic `pkg-config --cflags lowdown` -c -o md2html.o md2html.c

clean:
	rm -rf md2html *.o

.PHONY: clean
