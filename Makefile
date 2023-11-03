CC = gcc
SRC = main.c
TARGET = main
PLOT_SCRIPT = plot_script.txt

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $^ -o $@
	./$@

clean:
	rm -f $(TARGET)

re: clean all