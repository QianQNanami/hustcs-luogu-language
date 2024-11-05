from itertools import combinations
from math import sqrt

def is_prime(n):
	if n < 2:
		return False
	for i in range(2, round(sqrt(n))):
		if n % i == 0:
			return False
	return True

def main():
	# Get the input
	k = input().split()[1]
	s = input().split()

	# Count the number of permutations
	count = 0
	for p in combinations(s, int(k)):
		if is_prime(sum([int(x) for x in p])):
			count += 1

	# Print the result
	print(count)

if __name__ == '__main__':
	main()