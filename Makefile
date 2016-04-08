TARGET=IsoSurfaceExtraction
LIBTARGET=libIsoSurfaceExtraction.a
FILES= \
	IsoSurfaceExtraction.cpp \
	ISEDriver.cpp
BINCPP = \
	IsoSurfaceExtractionBin.cpp
SOURCE=$(FILES)

CFLAGS += -fopenmp -Wno-deprecated
LFLAGS += -lgomp

CFLAGS_DEBUG = -DDEBUG -g3 -std=c++11
LFLAGS_DEBUG =

CFLAGS_RELEASE = -O3 -DRELEASE -funroll-loops -ffast-math -std=c++11
LFLAGS_RELEASE = -O3

SRC = Src/
BIN = Bin/Linux/
LIB = Lib/Linux/
INCLUDE = /usr/include/ -I./

CC=gcc
CXX=g++
LIBTOOL=ar rcs
#LIBTOOL=libtool -static -o
MD=mkdir


OBJECTS=$(addprefix $(BIN), $(addsuffix .o, $(basename $(SOURCE))))
BINOBJ=$(addprefix $(BIN), $(addsuffix .o, $(basename $(BINCPP))))

all: CFLAGS += $(CFLAGS_RELEASE)
all: LFLAGS += $(LFLAGS_RELEASE)
all: $(BIN)
all: $(BIN)$(TARGET)

debug: CFLAGS += $(CFLAGS_DEBUG)
debug: LFLAGS += $(LFLAGS_DEBUG)
debug: $(BIN)
debug: $(BIN)$(TARGET)

lib: CFLAGS += $(CFLAGS_RELEASE)
lib: LFLAGS += $(LFLAGS_RELEASE)
lib: $(LIB)
lib: $(LIB)$(LIBTARGET)


clean:
	rm -f $(BIN)$(TARGET)
	rm -f $(OBJECTS)
	rm -f $(LIB)$(LIBTARGET)
	rm -f $(BINOBJ)

$(LIB):
	$(MD) -p $(LIB)

$(LIB)$(LIBTARGET): $(OBJECTS)
	$(LIBTOOL) $@ $(OBJECTS)

$(BIN):
	$(MD) -p $(BIN)

$(BIN)$(TARGET): $(OBJECTS) $(BINOBJ)
	$(CXX) -o $@ $(OBJECTS) $(BINOBJ) $(LFLAGS)

$(BIN)%.o: $(SRC)%.c
	mkdir -p $(BIN)
	$(CC) -c -o $@ $(CFLAGS) -I$(INCLUDE) $<

$(BIN)%.o: $(SRC)%.cpp
	mkdir -p $(BIN)
	$(CXX) -c -o $@ $(CFLAGS) -I$(INCLUDE) $<
