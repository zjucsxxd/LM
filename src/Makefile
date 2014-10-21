# Author: zhangfang
# Email: thuzhf@gmail.com

CC = g++
CFLAGS = -std=c++11
DEPS = 
OBJ = lm.o inverted_index.o tokenizer.o estimator.o locations_of_word.o documents.o

lm.out: $(OBJ)
	$(CC) -o lm.out $(OBJ) $(CFLAGS)

lm.o locations_of_word.o: locations_of_word.h
inverted_index.o: inverted_index.h
tokenizer.o lm.o inverted_index.o: tokenizer.h
estimator.o lm.o: estimator.h
documents.o inverted_index.o: documents.h

.PHONY: clean
clean:
	rm lm.out $(OBJ)
