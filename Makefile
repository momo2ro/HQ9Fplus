PROGRAM = hq9fp
SRCS = main.c file_compile.c interpreter.c file_name.c print_result.c replace_char.c
OBJS = $(SRCS:%.c=%.o)
DEPS = $(SRCS:%.c=%.d)
CC = gcc
CFLAGS = -Wall -O2 -MMD -MP

.PHONY:all
all:$(PROGRAM)

-include $(DEPS)

$(PROGRAM):$(OBJS)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c $<

.PHONY:clean
clean:
	$(RM) $(PROGRAM) $(OBJS) $(DEPS)
