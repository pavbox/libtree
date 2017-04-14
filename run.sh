
#
# Welcome!
# Please, compile and start program instruction (for mac or linux).
# exec by terminal command:
# sh run.sh
#

# if you experienced user, you can use another compilation.
# for example:
# c++ test.cpp -o test -std=c++11 -stdlib=libc++


# compile sources to object files
g++ -c libtree.cpp -o libtree.o
g++ -c test.cpp -o test.o

# create shared library (.so)
g++ -shared -fPIC -o libtree.so libtree.o

# compile test cpp file.
g++ test.o libtree.o -o test

# ./test
