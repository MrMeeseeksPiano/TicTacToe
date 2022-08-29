bin/jogo_da_velha: src/* include/* lib/libjogo.a
	@gcc -o bin/jogo_da_velha jogo/main.c -lSDL2 -Llib -ljogo -Iinclude

lib/libjogo.a: src/* include/*
	@gcc -c src/functions.c -Iinclude
	@gcc -c src/measures.c -Iinclude
	@ar rcs $@ functions.o measures.o
	@mv *.o bin/

clean:
	@rm -f bin/* lib/* 
	@find . -name '*.o' -exec rm -f {} \;

install: bin/jogo_da_velha
	cp $? /usr/local/bin
 
uninstall:
	rm -f /usr/local/bin/jogo_da_velha

run:
	./bin/jogo_da_velha

sdl2:
	apt-get install libsdl2-dev


