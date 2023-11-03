CC = gcc
SRC = main.c
TARGET = main
PLOT_SCRIPT = plot_script.txt

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $^ -o $@
	./$@
	gnuplot $(PLOT_SCRIPT)

clean:
	rm -f $(TARGET)

re: clean all