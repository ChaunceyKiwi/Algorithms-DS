# Exercises for Chapter5

### Exercise1
Skipped due to has been done

### Exercise2
Give an O(n log n) algorithm to count the number of significant inversions between two orderings.
#### Answer
Using the modifiction version of merge sort. Need to merge for sorting and merge for counting significant inversions.**TODO: add more details here in the future** 

    while (curr1 <= last1 && curr2 <= last2) {
      if (arr[curr1] > sensitivity * arr[curr2]) {
        arr2.push_back(arr[curr2++]);
        count += (last1 - curr1 + 1);
      } else if (arr[curr1] > arr[curr2]) {
        arr2.push_back(arr[curr2]);
        curr1++;
      } else {
        arr2.push_back(arr[curr1++]);
      }
    }

### Exercise3
Among the collection of n cards, is there a set of more than n/2 of them that are all equivalent to one another? Assume that the only feasible operations you can do with the cards are to pick two of them and plug them in to the equivalence tester. Show how to decide the answer to their question with only O(n log n) invocations of the equivalence tester.

#### Answer
##### Version1
If |S| = 1 return the one card

If |S| = 2 test if the two cards are equivalent. Return either card if they are.

Let S1 be the first floor(n/2) cards. 

Let S2 be the remaining ceiling(n/2) cards. 

Run algorithm on S1, if return one, test it. If non, run on S2.

If one is found, return it.

Time complexity is O(N * logN). Since T(n) = 2*T(n/2) + O(n)

##### Version2
Pair up all cards. For all pairs, if the cards are equivallent, then keep them, otherwise abandon them. If the total number of card is odd, then keep that card. Finally the card remains is the candidate. Verify it with the other cards.

It takes n/2 + n/4, .... 1 to do the elimination and n-1 for final verification, thus with less than 2n tests the time complexity is O(n).
 

### Exercise4
Help them out by designing an algorithm that computes all the forces Fj in O(n log n) time.

#### Answer
Using the convolution (lol... it is a math issue to use fast convolution which has a time complexity of O(N * logN)

### Exercise5
Give an algorithm that takes n lines as input and in O(n log n) time returns all of the ones that are visible.

#### Answer
Firstly label the lines in order of increasing slope, and then use a divide-and-conquer approach. If n <= 3, we can easily find the visible lines in constant time. The first and the third will always be visible and the second will be visable. The second will be visible if and only if it meets the first line to the left of where the third line meets the first line.

Let m = ceiling(n/2), we first recursively compute the sequence of visible lines among L1, ..., Lm, say they are {Li1, Li2, ... Lip} in order of increasing slope. And we also compute the sequence of intersection points a1, a2... a(p-1), where ak is the intersection of line Lik and Li(k+1). We can derive that a1, a2, ... a(p-1) will have increasing x-coordinates. And we do the same things for the line remains.

To merge L and L', we know the Li1 and Ljq is visible becasue they have minimum and maximum slope.

We merge the sorted list a1, ..., a(p-1) and b1, ..., b(q-1) into a single list of points c1,c2,c..c(p+q-2), ordered by increasing x-coordinate. Now for each k we consider which line is uppermost at ck in L and L'.

The sequence of visible lines is Li1, ... Lis, Ljt,..., Ljq.

**To be consider in detail in the future**