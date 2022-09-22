chemion: Encoder.o main.o
	clang++ $^ -o $@

test: chemion
	./$<

clean:
	rm -f chemion Encoder.o main.o

%.o: %.cpp Encoder.h
	clang++ -c -std=c++20 -O0 -g $< -o $@
