# Set the output to a png file
#set terminal png size 500,500
# The file we'll write to
#set output 'plot.png'
# The graphic title
set title 'Species number'
# labels:
set xlabel "Initial Number of Species"
set ylabel "Probability of Surviving"
#set limit for y axis
#set yrange [0:10]
#set location of legend
set key at graph 0.25, 0.95
#plot the graphic
plot "species_survived_extinct.csv" using 1:2 title "100 events"
# finish:
pause -1 "Hit any key to continue"
