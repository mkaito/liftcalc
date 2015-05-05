CFLAGS = -Wall -Werror -pedantic -std=c99

all: release

release: CFLAGS += -DNDEBUG
release: liftcalc

test: clean liftcalc
	./liftcalc

clean:
	rm -f liftcalc
