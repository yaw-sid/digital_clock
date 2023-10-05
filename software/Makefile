ifndef $(MSPGCCDIR)
	MSPGCCDIR=$(HOME)/ti/msp430-gcc
endif

INCLUDES_DIRECTORY = $(MSPGCCDIR)/include

DEVICE = msp430g2553

CC=$(MSPGCCDIR)/bin/msp430-elf-gcc
TESTCC=/usr/bin/gcc

CFLAGS = -I . -I $(INCLUDES_DIRECTORY) -mmcu=$(DEVICE) -g -Wall -Werror -Os
LFLAGS = -L . -L $(INCLUDES_DIRECTORY)

DRIVER:= rf2500

all: main.elf

%.elf: %.c clock.h
	$(CC) $(CFLAGS) $(LFLAGS) $< -o $@

install.%: %.elf
	mspdebug $(DRIVER) "prog $<" --allow-fw-update
	
test: clock_test.c
	$(TESTCC) -Wall -Werror -pedantic $< -o test.o

clean:
	rm -f *.o *.elf