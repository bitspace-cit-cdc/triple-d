x=int(input())
if x == 0:
	print(0)
else:
	left, right = 1, x
	while left <= right:
		mid = (left + right) // 2
		if mid * mid *mid == x:
			return mid
		elif mid * mid * mid < x:
			left = mid + 1
		else:
			right = mid - 1
	print( right )