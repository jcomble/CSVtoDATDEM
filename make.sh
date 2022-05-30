g++ -c *.cpp -g
g++ -o csvtodatdem.run *.o -g
./csvtodatdem.run test-PMR_simple.csv 
gnuplot output_nodes.dem