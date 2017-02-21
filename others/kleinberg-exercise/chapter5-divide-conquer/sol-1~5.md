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

#### Answer

### Exercise5

#### Answer