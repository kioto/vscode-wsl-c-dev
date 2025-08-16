CC		= gcc
LD 		= gcc
CFLAGS	= -g -Wall
SRCS	= main.c
OBJS	= $(SRCS:.c=.o)
LIBS	= -lz
TARGET	= zlib-sample

all : $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(OBJS) -o $@ $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -fr $(TARGET) $(OBJS)
