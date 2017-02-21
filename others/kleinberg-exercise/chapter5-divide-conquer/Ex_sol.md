# Exercises for Chapter5

### Solved Exercise1

Find the “peak entry” p without having to read the entire array—in fact, by reading as few entries of A as possible. Show how to find the entry p by reading at most O(log n) entries of A.

#### Answer
We probe the midpoint of the array and try to determine the peak is before or after this midpoint.

If len <= 3, return the index of the one with the largest value. 
Otherwise do as following: 

1. If A[n / 2 - 1] < A[n / 2] < A[n / 2 + 1], then the peak is strictly after a[n / 2], thus we can find peak in A[n / 2 + 1, n]
2. If A[n / 2 + 1] < A[n / 2] < A[n / 2 - 1], then the peak is strictly before a[n / 2], thus we can find peak in A[1, n / 2 - 1]
3. If A[n / 2] > A[n / 2 + 1] and A[n / 2] > A[n / 2 - 1], then 
A[n / 2] is the peak of the array

In all these cases, we perform at most 3 probes and reduce the problem to one of almost half size. From T(n) = T(n/2) + O(1), we can derive that the time complexity is O(logN).

### Solved Exercise2
Show how to find the correct numbers i and j in time O(n log n).

#### Answer
##### Version 1 with divide and conquer:

1. Buy and sell in the first n/2 days.
2. Buy and sell in the last n/2 days.
3. Buy in the first n/2 days and sell in the last n/2 days. (Find maximum and minimum)

Time complexity analysis: The first two alternatives are computed in time O(n/2), the third alternative needs O(n) to find minimum and maximum in first and second halves. Thus the running time T(n) satisfies `T(n) = 2 * T(n/2) + O(n)`, thus the time complexity is O(n * logn).

##### Version2:
Actually in this problem we try to get the difference between the maximum value and minimum value, and the maximum value should have a index larger than the minimum value.

Thus we can store the minimum number in a varible, whenever we meet with a number less than the minimum number, we update it. We can guarantee the minimum number is in the front of the maxmimum number because it is updated before meeting the maximum number. 

    for (int i = 0; i < len; i++){
        if (prices[i] < min_price)
            min_price = prices[i];
        else if(prices[i] - min_price > maxProfit)
            maxProfit = prices[i] - min_price;
    }

Time complexity analysis: it needs n iterations with each iteration consuming constant time. Thus the time complexity is O(n).




