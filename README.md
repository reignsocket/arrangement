Problem Description  
As you know, given a positive integer n, then n to n can be n! Arrangement, list these arrangements in ascending order (dictionary order), such as n=3, list 1 2 3,1 3 2,2 1 3,2 3 1,3 1 2,3 2 1 Six permutations. Given an alignment, find the next k permutations of the permutation. If the last permutation is encountered, the next 1 is ranked as the first permutation, ie 1 2 3...n. For example: n = 3, k = 2 gives the arrangement 2 3 1, then its next 1 is 3 1 2, and the next 2 is 3 2 1, so the answer is 3 2 1.  
  
Input data  
The first line is a positive integer m, indicating the number of test data, the following is m group test data, each set of test data
The first line is 2 positive integers n( 1 <= n < 1024 ) and k(1<=k<=64), and the second line has n positive integers, which is an arrangement of 1,2 ... n.  
  
Output requirements  
For each set of input data, output one line, n numbers, separated by spaces, indicating the next k permutations of the input arrangement.  
  
Input sample  
3  
3 1  
2 3 1  
3 1  
3 2 1  
10 2  
1 2 3 4 5 6 7 8 9 10  
  
Output sample  
3 1 2  
1 2 3  
1 2 3 4 5 6 7 9 8 10  
  
Problem solving  
The most intuitive idea for this topic is to find all the permutations from 1 to n, then sort all the rankings... and slow, n
The maximum can be 1024, 1024! Arrangement, almost never calculated, there is no place to calculate. So, is there a formula or a rule that can quickly calculate the next k alignments from one permutation? In fact, looking for rules or formulas is futile, and can only be honestly calculated from the given arrangement to calculate the next permutation, and then calculate the next permutation... all the way to the kth. Since the value of k is small, at most 64, this algorithm should be feasible. How to find the next permutation by a given arrangement? Let's do it yourself. such as:
What is the next arrangement of "2 1 4 7 6 3 5"? Easy, obviously "2 1 4 7 6 5 3", then, what is the next arrangement? A little difficult, it is "2 1 5 3 4 6 7". Taking the next arrangement "2 1 5 3 4 6 7" from "2 1 4 7 6 5 3" as an example, the steps of finding the next permutation of a given arrangement can be summarized:  
Suppose the n numbers in a given arrangement are a1, a2, a3...an from left to right.  
1) From an, look to the left until you find an aj that satisfies aj-1 < a (for example j, this aj is 7,
Aj-1 is 4).  
2) Find the smallest number greater than aj-1 in aj , aj+1 ... an , and swap this number with aj-1 (right  
In the above example, the number is 5, and 4 is changed after the position is changed to "2 1 5 7 6 4 3").
3) Reorder all the numbers from position j to position n (n-j+1 total) from small to large, after sorting,  
The new arrangement is the required arrangement. (For the above example, the "7 6 4 3" is sorted, and the new arrangement after the arrangement is "2"
1 5 3 4 6 7”).
Of course, according to the topic requirements, if a1, a2, a3...an are already descending, then its next order is an, an-1, an-2...a1.
