set terminal pngcairo enhanced font "arial,10" size 800,600
set output "execution_times.png"

set title "Execution Times for Sorting Algorithms"

set xlabel "List Size"
set ylabel "Time (seconds)"
set key outside
set grid

# Specify that the data is in CSV format and define the delimiter
set datafile separator ","

# Plot data using column numbers (1:2, 1:3, etc.) for x and y values
plot "execution_times.csv" using 1:2 with lines title "Insertion Sort", \
     "execution_times.csv" using 1:3 with lines title "Selection Sort", \
     "execution_times.csv" using 1:4 with lines title "Bubble Sort", \
     "execution_times.csv" using 1:5 with lines title "Merge Sort", \
     "execution_times.csv" using 1:6 with lines title "Quick Sort"

# Save the plot to a file
set output
