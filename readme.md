# Matrix Calculator with basic operations (+,-,*) C++

+ 7.12: temporary array removed
+ in difference with the C-Version, it's possible to calculate with more than 2 matrices, by chaining the last result 

usage with g++ compiler:
```
$ g++ main.cpp matrix.cpp -std=c++11 -o main
$ ./main
n: new calculation
c: continue calculation with last result
any key, except n, c: end program
n
Enter row (A1): 2
Enter col (A1): 3
A1: a11=5
A1: a12=4
A1: a13=2
A1: a21=5
A1: a22=6
A1: a23=7
(   5   4   2   )
(   5   6   7   )

Enter row (A2): 3
Enter col (A2): 2
A2: a11=5
A2: a12=3
A2: a21=2
A2: a22=5
A2: a31=6
A2: a32=7
(   5   3   )
(   2   5   )
(   6   7   )

Choose operation: +, - or *: *
Result:
(  45  49   )
(  79  94   )

n: new calculation
c: continue calculation with last result
any key, except n, c: end program
c
Enter row (A3): 2
Enter col (A3): 2
A3: a11=5
A3: a12=4
A3: a21=2
A3: a22=6
(   5   4   )
(   2   6   )

Choose operation: +, - or *: +
Result:
(  50  53   )
(  81 100   )

n: new calculation
c: continue calculation with last result
any key, except n, c: end program
c
Enter row (A4): 2
Enter col (A4): 2
A4: a11=-4
A4: a12=-7
A4: a21=-2
A4: a22=-8
(  -4  -7   )
(  -2  -8   )

Choose operation: +, - or *: +
Result:
(  46  46   )
(  79  92   )

n: new calculation
c: continue calculation with last result
any key, except n, c: end program
c
Enter row (A5): 2
Enter col (A5): 2
A5: a11=6
A5: a12=6
A5: a21=9
A5: a22=2
(   6   6   )
(   9   2   )

Choose operation: +, - or *: -
Result:
(  40  40   )
(  70  90   )

n: new calculation
c: continue calculation with last result
any key, except n, c: end program
n
Enter row (A1): 2
Enter col (A1): 3
A1: a11=5
A1: a12=4
A1: a13=2
A1: a21=6
A1: a22=4
A1: a23=2
(   5   4   2   )
(   6   4   2   )

Enter row (A2): 2
Enter col (A2): 3
A2: a11=6
A2: a12=3
A2: a13=6
A2: a21=7
A2: a22=3
A2: a23=8
(   6   3   6   )
(   7   3   8   )

Choose operation: +, - or *: +
Result:
(  11   7   8   )
(  13   7  10   )

n: new calculation
c: continue calculation with last result
any key, except n, c: end program
x
```
