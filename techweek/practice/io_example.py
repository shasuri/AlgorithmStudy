# PNU TECHWEEK Competition
# Practice Session Python I/O Example


# Get N from standard input
N = int(input())

# Declare list to contain vote results
votes = []

# get each vote result in 'votes' list with for loop
for i in range(N):
    x = input()
    votes.append(int(x))
    
# calculate answer

# TO-DO part
# Uses votes[0] as a temporary answer
answer = votes[0]

# print answer
print(answer)