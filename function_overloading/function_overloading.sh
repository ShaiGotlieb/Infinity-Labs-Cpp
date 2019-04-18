gdp -c -fPIC function_overloading.cpp 
gdp -shared function_overloading.o -o libfoo.so
gd -o function_overloading.cpp -ldl