CC = gcc
SRC = main.c
TARGET = main
OUTPUT_FILE = data.txt
PLOT_SCRIPT = plot_script.txt

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $^ -o $@
	./$@ > $(OUTPUT_FILE)
	gnuplot $(PLOT_SCRIPT)

clean:
	rm -f $(TARGET)

re: clean all