# distinct numbers 

- use set, insert every element to a set
- return set.size() 
- or use STL unique(x.begin(), x.end()) - x.begin() 
- time - O(NlogN)

# Apartments 

- use 2 pointers, both at beginning of each array 
- assign an apartment if condition is met
- if customer wants a bigger apt, i++ 
- else j++ 
- time - O((N+M)log(N+M))

# Ferris Wheel 

- use 2 pointers, one at beginning, one at the end 
- if condition fulfilled, move both pointers inward(i++, j--) 
- if not, move only j-- 
- increment ans every while iteration 
- return ans 
- time - O(NlogN) 

# Concert Tickets 

- for each input, find the largest ticket with price closest and greater than pricing willing to be paid for it 
- if not found , print -1 
- if found , print that ticket price and erase from the multiset of tickets 
- time - O((M+N)logN)


