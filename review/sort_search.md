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







