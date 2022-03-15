bin: main.c
	gcc $< -o $@ -lpthread

.PHONY: clean run

clean:
	rm bin

run:
	./bin -pthread