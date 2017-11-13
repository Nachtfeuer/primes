# primes
Basically a sandbox for playing/testing with/of some techniques. Using cmake, catch2, openmp and .... some more

## Quick start

```
git clone https://github.com/Nachtfeuer/primes.git
cd primes
mkdir build
cd build
cmake ..
make
./primes
```

## Catch2

It's one reason for that repository to test the installation and usage of
that nice testing framework in cmake project. So far the good news:

 - it's header only
 - it's easy to download that file via cmake and to put it into the build folder only
 - the compiled binary offers nice options including filtering and the execution time
   of the individual tests.

## OpenMP

OpenMP is one way to organize code running in parallel. It offers support for loops
and synchronization in very easy way. At least for the primes problem it hides all
those thread logic you usually would have to do. Also via cmake it's easy to integrate
with just a small amount of cmake code.

## Boost Fibers

Fibers are non preemptive threads means that the fiber function itself decides when
it gives control to other fibers (yield). The prime algorithm based on fibers runs
single threaded which also means that you don't need synchronization. The
managing overhead makes - here - fibers slightly slower than just running the loop
without it. The main focus here was just to have a simple code example on how to use
fibers which is - basically - not difficult. In an reactive environment like processing
requests in a server the non blocking none synchronized idea behind fibers might
give you a complete other picture.
