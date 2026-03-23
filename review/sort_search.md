# distinct numbers 

- pattern - deduplication
- use set, insert every element to a set
- return set.size() 
- or use STL unique(x.begin(), x.end()) - x.begin() 
- time - O(NlogN)

# Apartments 

- pattern - matching two sorted arrays with buffer 
- use 2 pointers, both at beginning of each array 
- assign an apartment if condition is met
- if customer wants a bigger apt, i++ 
- else j++ 
- time - O((N+M)log(N+M))

# Ferris Wheel 

- pattern - pairing problem, subject to sum <= X, minimize number of groups 
- use 2 pointers, one at beginning, one at the end 
- if condition fulfilled, move both pointers inward(i++, j--) 
- if not, move only j-- 
- increment ans every while iteration 
- return ans 
- time - O(NlogN) 

# Concert Tickets 

- pattern - dynamic predecessor queries 
- for each input, find the largest ticket with price closest and greater than pricing willing to be paid for it 
- if not found , print -1 
- if found , print that ticket price and erase from the multiset of tickets 
- time - O((M+N)logN)


# Restaurant Customers 

- pattern - event count/accumulation 
- each event(entry or exit) add +1 and -1 respectively to customer count
- then sort, the vector of pairs by time --> time ordered flow of events 
- iterate through vector and get the maximum count at any time and return it 
- time - O(NlogN) 

# Movie Festival 

- pattern - interval scheduling, no overlap 
- always pick movies that ends earliest --> greedy 
- sort all movies by end time and if start of next movies >= last ending, watch it 
- return count 
- time - O(NlogN)

# Two Sum 

- find if X - a_i exists in the unordered map 
- use unordered map for quick checking if an element exists 
- time - O(N)

# Max Subarray Sum 

- condition - start new subarray sum if the current element is greater than previous subarray sum, else keep adding elements 
- if current subarray sum < 0, better to start new subarray 
- time - O(N) 

# Stick Lengths 

- pattern - to minimize sum of abs(a_i - x) , make x the median of a 
- time - O(NlogN)

# Missing Coin sum 

- find the first coin that is greater than sum of all smaller coins + 1 
- time - O(NlogN) 

# Collecting Numbers 

- instead of having multiple passes through the array 
- store pos_x = i, store position of element in another array, works due to guaranteed unique elements in input 
- at every pos_x < pos_(x-1) - increase count 
- ans = 1 + number of break in order 
- time - O(N) 

# Collecting Numbers II 

- same as above
- when switching elements, make appropriate changes to the position and element array 
-  time - O(1) per query

# Playlist 

- run a sweep using two pointers and return max 
- expand window as long as all elements in it are unique 
- if new element, exists, shrink, from left till distinct elements only in the window 
- time - O(N)

# Towers 

- always place current number on the leftmost tower whose top > x 
- store tops of all towers 
- for each element, place on existing tower or start new tower 
- keep tops as small as possible 
- always use smallest valid top --> greedy 
- time - O(NlogN) 


# Traffic Lights 

- maintain set of all traffic light positions (sorted automatically) 
- store multiset of lengths of segments between consecutive lights 
- when inserting, find which segment the new light breaks and update new segment lengths 
- *it2 ---- p and p ---- *it1, when p is inserted 
- time - O(NlogN) 

# Distinct Value Subarray

- use a set to check for uniqueness in each subarray and sliding window to go through subarrays 
- have two pointers l and r, at each step, if a_r not in the subarray, insert it to the set, if it is, keep removing leftmost elements till the subarray has only distincy elements again, and do this for r from 0 to N-1
- keep adding the subarray length, to count the number of distinct subarrays --> ans += r - l + 1 
- time - O(NlogN)

# Distinct Value Subsequence

- turn this into a simple combinatorics problem 
- build a frequency map of each element in the array
- ans = product of each frequency+1 (+1 to count exclusion) - 1 (subtract 1 from product to not count empty subsequence, where all elements were excluded) 

# Josephus Problem I 

- use a queue to simulate a circle 
- skip a person by, pushing the front of the queue, to the back, and popping it, then print the new front element and pop it to delete it 
- time - O(N)

# Josephus Problem II 

- use fenwick tree for speed
- modifying solution to above problem leads to TLE 
- build a fenwick Tree 
- update marks if an element is removed or to be counted 
- findk returns the kth person to be counted
- then iterate through the circle to count and print all elements
- 





























