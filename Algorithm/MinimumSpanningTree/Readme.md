##Problem Description:
A city want to build some transportation system between the other city(directly
or indirectly). Assume that the cost to build the connection between cities are
known(some city can not be connected directly due to some reasons); Every
connection is bi-directional. You need to writing a code to print the best way
to connect city so that the whole cost will be smallest.


##Input format:
In the first row is two positive number n and m, n represents the number of city,
m represents that there are m possible ways to connect cities.

The second row have n char to show the code of city. The next m row have 3 columns,
which shows the code of city and the distance between them.  

##Output format:
Print 2 columns. In the first few rows you print the pairs of cities connected in
brackets.The final row you print the whole cost.

##Input example:
6 9
A B C D E F G
A B 1
A D 7
B C 3
B D 6
B E 4
C E 5
C F 9
D E 3
E F 8

##Output example:
(A B)
(C D)
(D E)
(B E)
(E F)
19

##Method:
Minimum Spanning Tree
Kruskal's algorithm

##Reference
The Description is translated from https://github.com/HondaDai/MinimumSpanningTree. Thanks for his work.
