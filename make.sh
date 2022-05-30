g++ -c *.cpp -g
g++ -o csvtodatdem.run *.o -g
rm *.o
./csvtodatdem.run test-PMR_simple.csv 
gnuplot output_graph_and_traffics.dem
rm *.run *.dat *.dem