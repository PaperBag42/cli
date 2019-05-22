
SRCDIR  := src
INCDIR  := include
OBJDIR  := build
BINDIR  := bin
TESTDIR := tests

OBJECTS := $(OBJDIR)/cli.o $(OBJDIR)/command.o $(OBJDIR)/history.o $(OBJDIR)/parsing.o
TARGET  := $(BINDIR)/libcli.a
TEST    := $(BINDIR)/test
TESTSRC := $(TESTDIR)/test.c

CC      := gcc -Wall -Wextra -I$(INCDIR)


.PHONY: all debug test clean

all: $(TARGET)

debug: CC += -g
debug: $(TARGET)

$(TARGET): $(OBJECTS) $(BINDIR)
	ar rcs $(TARGET) $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@

test: CC += -g
test: $(TEST)

$(TEST): $(TESTSRC) $(TARGET)
	$(CC) $< -L$(BINDIR) -lcli -o $@

clean:
	rm -rf $(OBJDIR)

$(OBJECTS): | $(OBJDIR)

$(OBJDIR):
	mkdir $@

$(BINDIR):
	mkdir $@
