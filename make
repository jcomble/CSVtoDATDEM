# the compiler: gcc for C program, define as g++ for C++
  PP = g++
 
  # The build target 
  TARGET = myprogram
 
  all: $(TARGET)
 
  $(TARGET): $(TARGET).cpp
  	$(PP) *.cpp -o $(TARGET) 
 
  clean:
  	$(RM) $(TARGET)