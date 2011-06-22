PROJECT_NAME=prog
#MAJOR=1
#MINOR=0
#VERSION=$(MAJOR).$(MINOR)

DEFS+=-D_GNU_SOURCE=1 -D_REENTRANT
INCLUDES+=
LIBS+=

CFLAGS+=-g -c -Wall
LDFLAGS+=

OBJS = prog.o iniParser.o


include $(MAKE_DIR)/global.mak
