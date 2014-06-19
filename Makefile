# @file  Makefile
# @brief Automatisation of the compilation of C and ASM programmes for the 6502
#        processor embedded in the SECMAT ASIC.
# @note  This Makefile works even if the programs are split into several files
# @note  Imported variables: INCDIR (export done when calling make 6502_all)

MACH       = secmat# Set MACH to "secmat_gen" to have the rom and fix dumped
#MAIN_ADD   = 0x0321#
MAIN_ADD   = 0x0321#

CC65 = cc65 -t $(MACH)
CA65 = ca65 -t $(MACH)
LD65 = ld65 -t $(MACH)

CC65FLAGS  = -O -Or -Os -g#
CA65FLAGS  =#
# The _6502 define is used to specify that the code is for the the 6502 CPU
# (for intrinsic types or 8 versus 32 bit implementations)
CC65FLAGS += -D_6502#

SRCS= main.c foncs.c

OBJS=$(SRCS:.c=.o)

TARGET=algo

.SUFFIXES: # This declaration has the side effect of disabling %o:%c
           # implicit rules using cc instead of making make go through our
		   # dependencies


all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD65) $(LD65FLAGS) -o $@ -S $(MAIN_ADD) $^ $(MACH).o $(MACH).lib -m $(patsubst %.exe,%.map,$@) -Ln $(patsubst %.exe,%.lbl,$@)
	@echo "# Size in bytes for $@:   $$(wc -c $@ | cut -d' ' -f1)"
	@echo "# Program address for $@: $$(echo $(MAIN_ADD) | sed -e 's/0x0*//')"
	@echo "# Execute address for $@: $$(grep _main $(patsubst %.exe,%.lbl,$@) -m1 | cut -d' ' -f2 | sed -e 's/^0*//')"

%.s: %.c
	$(CC65) $(CC65FLAGS) -o $@ $<

%.o: %.s
	$(CA65) $(CA65FLAGS) -o $@ $<

%: %.o
	$(LD65) $(LD65FLAGS) -o $@ -S $(MAIN_ADD) $^ $(MACH).o $(MACH).lib -m $(patsubst %.exe,%.map,$@) -Ln $(patsubst %.exe,%.lbl,$@)
	@echo "# Size in bytes for $@:   $$(wc -c $@ | cut -d' ' -f1)"
	@echo "# Program address for $@: $$(echo $(MAIN_ADD) | sed -e 's/0x0*//')"
	@echo "# Execute address for $@: $$(grep _main $(patsubst %.exe,%.lbl,$@) -m1 | cut -d' ' -f2 | sed -e 's/^0*//')"

clean :
	rm -f *.o *.s *.map *.lbl *.exe
