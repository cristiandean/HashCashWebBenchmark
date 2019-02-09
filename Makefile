CC      := emcc
CFLAGS  := -O3
LDFLAGS := -s "WASM=1" -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' -s ALLOW_MEMORY_GROWTH=1
SRCDIR  := ./src
OBJDIR  := ./obj
BINDIR  := ./bin
TARGET  := $(BINDIR)/md5-sha1.wasm
SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(addprefix $(OBJDIR)/, $(SOURCES:$(SRCDIR)/%.c=%.o))

.SUFFIXES: .c .o

default: $(TARGET)

$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) -o $(@:.wasm=.html) $^ $(LDFLAGS)

$(BINDIR):
	mkdir -p $@

$(OBJECTS): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)
