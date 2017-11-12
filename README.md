# primes
Basically a sandbox for playing/testing with/of some techniques. Using cmake, catch2, openmp and .... some more

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


