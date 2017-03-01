# Choice of formula on DP

## Problem introduction
When handling with problem using dynamic programming, it is important to find a proper way to model the problem and use a formula based on it. 

The reason why I write this article is that when I tried to finish a problem today. The formula I come up with is quite complex. When I look up the answer, I find it actually can be quite easy. Thus it is important to choose the right angle to handle with the problem.

## Example
In the NLP, one of problem is "words segmentation". To find the segmentation with the highest score, we can use dynamic programming.

### My version
Denote opt(j) as the highest score we can get with first j letters. To calculate opt(k), we have two situations: 

1. The new letter is combined with the former letter.
2. The new letter is a stand-alone letter.

However, we also need to consider about how many former letter should be combined to the new letter. Thus for each opt(j), we also need to record cut(j), which shows the last position of the segmentation.

Thus we need to add a new letter, we need to consider these two situations. In the meantime, we also need to consider opt(k-1), opt(k-2), .., opt(1). 

The formula is skipped here. But from my analysis, it is obvious that the formula will be quite complex, and with a high time complexity.

### Standard version
Denote opt(j) as the highest score we can get with first j letters. To calculate the opt(k), we have k situations:

1. The new letter is a stand-alone letter.
2. The new letter is combined with last 1 letter.
3. The new letter is combined with last 2 letter.

	......

k. The new letter is combined with last k - 1 letter.

In such a way, we can get the formula which is much simpler than the vesion of mine. We do not need to record cut(j) any more. And the time complxity is cut down as well.

## Comparsion
Why the second version can be much better than the first version? Does it leave out something important? Actually it is not. The root of problem is that my version actually contains a lot of duplication, which makes it so complex and so slow.

For example, assume in my version, the newly added letter should be combined with former letter. And from cut(k-1) we know the last 4 letters are combined together. Now we need to combine last 5 letters together, we need to cut down the cost by quality(last 4) and add the cost by quality(last 5), which is quite painful.

However, in the standard version, to get the cost, the new letter is combined with last 4 letters. We calculate the quality of this 5 letters and added with opt(k-5). Or we can say, opt(k-1) = opt(k-5) + quality(last 4). Thus the cost is already stored in opt(k-5), I do not need to subtract it down, then add it up. At the same time, the case1 is exactly the first case of my version, and the cases remaining is the second case of my version.

In conclusion, when try to solve a problem using dynamic programming, it is indeed possible to have a complex method. But before you make up your mind, think about if there can be a simpler and straight-forward solution? Does my answer make it too complex? In this way, it will be more likely to design a algorithm with better clarity and simplicity.



