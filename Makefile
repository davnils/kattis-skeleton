# accepts the following arguments:
# mode=test expects a TestSuite target
# driver=TaskSomething/TestSomething should always be given

PROGRAM = out
SRC_DIR = .
DRIVER_FILE = $(SRC_DIR)/$(driver).cc
C_FILES = $(DRIVER_FILE)
C_FILES += $(SRC_DIR)/main.cc
# INCS = -I include/

OBJS = $(patsubst %.cc, %.o, $(C_FILES))
CC = g++
CFLAGS = -g -Wall -Wextra -O2 -std=gnu++0x $(INCS)
LDFLAGS =
DEPFILE = .dep

ifeq ($(mode),test)
	CFLAGS += -DTEST_DRIVER
endif

all: driver-set $(PROGRAM)

driver-set:
ifndef driver
	$(error You need to specify driver=TaskSomething/TestSomething...)
endif

$(PROGRAM): .depend $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(PROGRAM)

depend: .depend

.depend: cmd = $(CC) $(CFLAGS) -MM -MF $(DEPFILE) $(var);
.depend:
		@$(foreach var, $(C_FILES), $(cmd))

-include $(DEPFILE)

%.o: %.cc
		$(CC) $(CFLAGS) -c $< -o $@

%: %.cc
		$(CC) $(CFLAGS) -o $@ $<

clean:
		@rm -f $(DEPFILE) $(SRC_DIR)/*.o $(PROGRAM)

.PHONY: clean depend
