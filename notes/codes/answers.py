# Zhihu
# 14. Longest Common Prefix
def longestCommonPrefix(self, strs):
	def helper(s, t):
		if len(s) > len(t):
			s, t = t, s
		for i in range(0, len(s)):
			if s[i] != t[i]:
				return s[:i]
		return s
	if not strs: return ""
	ans = reduce(lcp, strs)
	return ans

def longestCommonPrefix(self, strs):
	if not strs:
		return ""
	for i, letter_group in enumerate(zip(*strs)):
		if len(set(letter_group)) > 1:
			return strs[0][:i]
	else:
		return min(str)

# Longest substring

# Meeting Rooms
def canAttendMeetings(self, intervals):
	intervals.sort(key=lambda x: x.start)
        for i in range(1, len(intervals)):
            if intervals[i].start < intervals[i-1].end:
                return False
        return True

# Meeting Rooms II
def minMeetingRooms(self, intervals):
	timelines = collections.defaultdict(int)
	for interval in intervals:
		timelines[interval.start] += 1
		timelines[intervals.end] -= 1
	ans, ongoing = 0, 0
	for t in sorted(timelines.keys()):
		ongoing += timelines[t]
		ans = max(ans, onging)
	return ans

def minMeetingRooms(self, intervals):
	starts = sorted(x.start for x in intervals)
	ends = sorted(x.end for x in intervals)
	num_rooms, available = 0, 0
	s, e = 0, 0
	while s < len(starts):
		if starts[s] < ends[e]:
			if available == 0:
				num_rooms += 1
			else:
				available -= 1
		else:
			available += 1
			e += 1
	return num_rooms

# Exam Room
class ExamRoom(object):
	def __init__(self, N):
		self.N = N
		self.occupied = []

	def seat(self):
		N, occupied = self.N, self.occupied
		if not occupied:
			res = 0
		else:
			d, res = occupied[0]-0, 0
			for i, j in zip(occupied, occupied[1:]):
				if (j-i)/2 > d:
					d, res = (j-i)/2, (i+j)/2
			if N-1-occupied[-1] > d:
				res = N-1
		bisect.insort(self.occupied, res)
		return res

	def leave(self, p):
		self.occupied.remove(p)

# The Skyline Problem
from heapq import *
def getSkyline(self, buildings):
	events = sorted(event for L, R, H in buildings for event in ([L, -H, R], [R, 0, None]))
	res, hp = [[0, 0]], [[0, float("inf")]]
	for left, negH, right in events:
		while left >= hp[0][1]:
			heappop(hp)
		if negH:
			heappush(hp, [negH, right])
		if res[-1][1]+hp[0][0]:
			res += [[left, -hp[0][0]]]
	return res[1:]

# Rectangel Area II
def rectangleArea(self, rectangles):
	OPEN, CLOSE = 0, 1
	events = [event for x1, y1, x2, y2 in rectangles for event in [(y1, OPEN, x1, x2), (y2, CLOSE, x1, x2)]]
	events.sort()
	def mergeInterval(actives):
		ans = 0
		cur = -sys.maxint
		for x1, x2 in actives:
			cur = max(cur, x1)
			ans += max(0, x2 - cur)
			cur = max(cur, x2)
		return ans

	ans = 0
	actives = []
	cury = events[0][0]
	for y, ty, x1, x2 in events:
		ans += mergeInterval(actives)*(y-cury)
		if ty == OPEN:
			actives.append((x1, x2))
			actives.sort()
		else:
			actives.remove((x1, x2))
		cury = y
	return ans%(10**9+7)

# Rectangle Area
def computeArea(self, A, B, C, D, E, F, G, H):
	overlap = max(min(C, G) - max(A, E), 0)*max(min(D, H) - max(B, F), 0)
	return (C-A)*(D-B) + (G-E)*(H-F) - overlap

# Rectangle Overlap
def isRectangleOverlap(self, rec1, rec2):
        return (rec1[2] > rec2[0]) and   \
               (rec1[3] > rec2[1]) and   \
               (rec1[0] < rec2[2]) and   \
               (rec1[1] < rec2[3])

# Merge K Sorted List
def mergeKLists(self, lists):
	dummy = ListNode(-1)
	cur = cummy
	hq = []
	for l in lists:
		if l:
			heapq.heappush(hq, (l.val, l))

	while hq:
		val, node = heapq.heappop(hq)
		cur.next = node
		cur = cur.next
		if node.next:
			heapq.heappush(hq, (node.next.val, node.next))

	return dummy.next

# path sum
def hasPathSum(self, root, target):
	if not root: return False
	if not root.left and not root.right and root.val == target:
		return True
	return self.hasPathSum(root.left, target-root.val) or \
			self.hasPathSum(root.right, target-root.val)

# path sum II
def pathSum(self, root, target):
	ans = []
	self.dfs(root, target, [], ans)
	return ans
def dfs(self, root, target, partRes, ans):
	if not root and target == 0:
		ans.append(partRes)
		return
	if not root and target != 0:
		return
	self.dfs(root.left, target-root.val, partRes+[root.val], ans)
	self.dfs(root.right, target-root.val, partRes+[root.val], ans)

# Path Sum III
# Naive Solution:
def pathSum(self, root, target):
	if not root: return 0
	return self.helper(root, target) + self.pathSum(root.left, target) + self.pathSum(root.right, target)
def helper(self, root, target):
	if not root: return 0
	return (root.val==target) + self.helper(root.right, target-root.val) + self.helper(root.left, target-root.val)
# With Prefix Cache
def pathSum(self, root, target):
	self.ans = 0
	prefix = collections.defaultdict(int)
	prefix[0] = 1
	self.helper(root, target, 0, prefix)
	return self.ans
def helper(self, root, target, accu, prefix):
	if not root:
		return
	accu += root.val
	self.ans += prefix[accu-target]
	prefix[accu] += 1
	self.helper(root.left, target, accu, prefix)
	self.helper(root.right, target, accu, prefix)
	prefix[accu] -= 1

# path sum IV
def pathSum(self, nums):
	self.ans = 0
	self.values = {x/10: x%10 for x in nums}
	self.helper(nums[0]/10, 0)
	return self.ans
def helper(self, node, accu):
	if node not in self.values: return
	accu += self.values[node]
	degree, pos = divmod(node, 10)
	right = (degree+1)*10 + 2*pos
	left = right - 1
	if left not in self.values and right not in self.values:
		self.ans += accu
	else:
		self.helper(left, accu)
		self.helper(right, accu)

# Peak Index in a Mountain Array
for i in range(1, len(A)-1):
    if A[i-1] < A[i] and A[i] > A[i+1]:
        return i

# 162. find peak element 
# Naive Solution
def findPeakElement(self, nums):
    for i in range(len(nums)-1):
        if nums[i] > nums[i+1]:
            return i
    return len(nums) - 1  
# binary search
def findPeakElement(self, nums):
	l, r = 0, len(nums)-1
    while l < r:
        mid = l + (r-l)/2
        if nums[mid] > nums[mid+1]:
            r = mid
        else:
            l = mid + 1
    return l

# Search a 2D matrix I 
def searchMatrix(self, matrix, target):
    m = len(matrix)
    if m == 0: return False
    n = len(matrix[0])
    if n == 0: return False
    l, r = 0, m*n-1
    while l < r:
        mid = l + (r-l)/2
        if matrix[mid/n][mid%n] == target:
            return True
        elif matrix[mid/n][mid%n] > target:
            r = mid
        else:
            l = mid + 1
    return matrix[l/n][l%n] == target

# Search a 2D matrix II
def searchMatrix(self, matrix, target):
	if matrix == [] or matrix = [[]]: return False
	m, n = len(matrix), len(matrix[0])
	i, j = m - 1, 0
	while i >= 0 and j < n:
		if matrix[i][j] > target:
			i -= 1
		elif matrix[i][j] < target:
			j += 1
		else:
			return True
	return False

# Search in Rotate Sorted Array I
def search(self, nums, target):
	if not nums: return -1
	start, end = 0, len(nums)-1
	while start < end:
		mid = (end+start)/2
		if nums[mid] == target:
			return mid
		else:
			# mid and target are in the same side
			if (nums[mid] > nums[end]) == (target > nums[end]):
				num = nums[mid]
			# mid and target are not in the same sie
			else:
				if target > nums[end]:
					num = sys.maxint
				else:
					num = -sys.maxint
			if num < target:
				start = mid + 1
			else:
				end = mid

	if nums[start] == target: return start
	else: return -1

# Search in Rotate Sorted Array II
def search(self, nums, target):
	if not nums: return False
	start, end = 0, len(nums)-1
	while start < end:
		mid = (end+start)/2
		if nums[mid] == target:
			return True
		if nums[mid] == nums[end]:
			end -= 1
		else:
			if (nums[mid] > nums[end]) == (target > nums[end]):
				num = nums[mid]
			else:
				if target > nums[end]:
					num = sys.maxint
				else:
					num = -sys.maxint
			if num < target:
				start = mid + 1
			elif num > target:
				end = mid

	if nums[start] == target: return True
	else: return False

# Maximum Subarray
def maxSubArray(self, nums):
    curSum, maxSum = 0, -sys.maxint
    for i in range(len(nums)):
        curSum = nums[i] if curSum < 0 else curSum + nums[i]
        maxSum = max(maxSum, curSum)
    return maxSum

# House Robbery I
def rob(self, nums):
	dp = [[0]*2 for _ in range(len(nums)+1)]
	for i, n in enumerate(nums):
		dp[i+1][0] = max(dp[i][0], dp[i][1])
		dp[i+1][1] = dp[i][0] + n
	return max(dp[-1])

# House Robbery II
def rob(self, nums):
	if not nums: return 0
	if len(nums) == 1: return nums[0]
	return max(self.Helper(nums[:-1]), self.Helper(nums[1:]))
def Helper(self, nums):
	exclude, include = 0, 0
	for i in range(len(nums)):
		temp = include
		include = exclude + nums[i]
		exclude = max(exclude, temp)
	return max(include, exclude)

# House Robbery III
def rob(self, root):
	return max(self.robSub(root))
def robSub(self, root):
	if not root: return [0, 0]
	left = self.robSub(root.left)
	right = self.robSub(root.right)
	val = [0, 0]
	val[0] = max(left) + max(right)
	val[1] = root.val + left[0] + right[0]
	return val

# Delete and earn
def deleteAndEarn(self, nums):
	if not len(nums): return 0
	mx, mn = max(nums), min(nums)
	num_sum = [0]*(mx-mn+1)
	for i, n in enumerate(nums):
		num_sum[n-mn] += n
	return self.HouseRobbery(num_sum)
def HouseRobbery(self, nums):
	exclude, include = 0, 0
	for i in range(len(nums)):
		temp = include
		include = exclude + nums[i]
		exclude = max(exclude, temp)
	return max(include, exclude)

# Paint House I
def minCost(self, costs):
	n = len(costs)
	if n == 0: return 0
	for i in range(1, n):
		costs[i][0] += min(costs[i-1][1], costs[i-1][2])
		costs[i][1] += min(costs[i-1][0], costs[i-1][2])
		costs[i][2] += min(costs[i-1][1], costs[i-1][0])
	return min(costs[n-1])

# Paint House II
def minCostII(self, costs):
	if len(costs) == 0: return 0
	n, k = len(costs), len(costs[0])
	for i in range(1, n):
		min1 = min(costs[-1])
		m1_pos = costs[i-1]
		min2 = min(costs[i-1][:min1_pos]+costs[i-1][min1_pos+1:])
		for j in range(k):
			if j != m1_pos:
				costs[i][j] += min1
			else:
				costs[i][j] += min2
	return min(costs[-1])

# wild matching
def isMatch(self, s, p):
	dp = [[False]*(len(s)+1) for _ in range(len(p)+1)]
	dp[0][0] = True
	for i in range(len(p)):
		dp[i+1][0] = dp[i][0] and p[i] == '*'
	for i in range(len(p)):
		for j in range(len(s)):
			if p[i] != '*':
				dp[i+1][j+1] = dp[i][j] and (p[i] == s[j] or p[i] == '?')
			else:
				dp[i+1][j+1] = dp[i][j+1] or dp[i+1][j]
	return dp[-1][-1]

# Regular Expression Matching
def isMatch(self, s, p):
	dp = [[False]*(len(s)+1) for _ in range(len(p)+1)]
	dp[0][0] = True
	for i in range(1, len(p)+1):
		dp[i][0] = (p[i-1] == "*" and dp[i-2][0])
	for i in range(len(p)):
		for j in range(len(s)):
			if p[i] != '*':
				dp[i+1][j+1] = dp[i][j] and (p[i] == s[j] or p[i] == '.')
			else:
				if p[i-1] != s[j] and p[i-1] != '.':
					dp[i+1][j+1] = dp[i-1][j+1]
				else:
					dp[i+1][j+1] = dp[i+1][j] or dp[i][j+1] + dp[i-1][j+1]
	return dp[-1][-1]

# Alien Dictionary
def alienOrder(self, words):
	pre, suc = collections.defaultdict(set), collections.defaultdict(set)
	for pair in zip(words, words[1:]):
		for a, b in zip(*pair):
			if a != b:
				suc[a].add(b)
				pre[b].add(a)
				break
	chars = set("".join(words))
	queue = chars - set(pre)
	ans = ''
	while queue:
		char = queue.pop()
		ans += char
		for n in suc[char]:
			pre[n].discard(char)
			if not pre[n]:
				queue.add(n)
	return ans if set(ans) == char else ""

# Create Maximum Number


# Spiral Matrix I
def spiralOrder(self, matrix):
	if len(matrix) == 0 or len(matrix[0]) == 0: return []
	left, right, top, bottom = 0, len(matrix[0])-1, 0, len(matrix)-1
	res = []
	while True:
		for i in range(left, right+1):
			res.append(matrix[top][i])
		top += 1
		if top > bottom: break
		for j in range(top, bottom+1):
			res.append(matrix[j][right])
		right -= 1
		if left > right: break
		for p in range(right, left-1, -1):
            res.append(matrix[bottom][p])
        bottom -= 1
        if bottom < top: break
        for q in range(bottom, top-1, -1):
            res.append(matrix[q][left])
        left += 1
        if left > right: break
    return res
# Spiral Matrix II
def generateMatrix(self, n):
    left, right, top, bottom = 0, n - 1, 0, n - 1
    s = 1
    matrix = [[0]*n for _ in range(n)]
    while True:
        for i in range(left, right + 1):
            matrix[top][i] = s
            s += 1
        top += 1
        if top > bottom: break
        for j in range(top, bottom + 1):
            matrix[j][right] = s
            s += 1
        right -= 1
        if right < left: break
        for p in range(right, left-1, -1):
            matrix[bottom][p] = s
            s += 1
        bottom -= 1
        if bottom < top: break
        for q in range(bottom, top-1, -1):
            matrix[q][left] = s
            s += 1
        left += 1
        if left > right: break
    return matrix

# Spiral Matrix III
def spiralMatrixIII(self, R, C, r0, c0):
	res = [(r0, c0)]
	direction = [[0, 1], [1, 0], [0, -1], [-1, 0]]
	steps, d = 0, 0
	while len(res) < R*C:
		steps += 1 if d%2 == 0 else 0
		for i in range(steps):
			r0 += direction[d][0]
			c0 += direction[d][1]
			if 0<=r0<R and 0<=c0<C:
				res.append((r0, c0))
		d = (d+1)%4
	return res

# Rotate Image
def rotate(self, matrix):
	m, n = len(matrix), len(matrix[0])
	# up-down
	for i in range(m/2):
		matrix[i], matrix[m-1-i] = matrix[m-1-i], matrix[i]
	# transpose
	for i in range(m):
		for j in range(i+1, n):
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

# Excel Sheet Column Number
def titleToNumber(s):
	s = s[::-1]
	sum = 0
	for exp, char in enumerate(s):
		sum += (ord(char) - ord('a')+1)*(26**exp)
	return sum

# Excel Sheet Column Title
def convertToTitle(self, n):
	capitals = [chr(x) for x in range(ord('A'), ord('Z')+1)]
	res = ""
	while n > 0:
		n, remain = divmod(n-1, 26)
		res = capitals[remain] + res
	return res

# Valid anagram:
def isAnagram(self, s, t):
	from collections import Counter
	if Counter(S) == Counter(t):
		return True
	return False

# Group Anagrams
def groupAnagrams(self, strs):
	d = {}
	for w in strs:
		key = tuple(sorted(w))
		d[key] = d.get(key, []) + [w]
	return d.values()

# Maze I
def hasPath(self, maze, start, destination):
	if not maze or not maze[0]:
		return False
	if start[0]==destination[0] and start[1]==destination[1]:
		return True
	visited = [[False]*len(maze[0]) for _ in range(len(maze))]
	visited[start[0]][start[1]] = True
	return self.mazeHelper(maze, visited, start, destination)

def mazeHelper(self, maze, visited, start, end):
	dirs = [[0,1],[1,0],[0,-1],[-1,0]]
	for d in dirs:
		x = start[0]; y = start[1]
		while 0<=x<len(maze) and 0<=y<len(maze[0]) and maze[x][y]==0:
			x += d[0]
			y += d[0]
		x -= d[0]
		y -= d[0]
		if x==end[0] and y==end[1]:
			return True
		if not visited[x][y]:
			visited[x][y] = True
			if self.mazeHelper(maze, visited, [x, y], end):
				return True
	return False

# Maze II
def shortestDistance(self, maze, start, destination):
	from heapq import *
	dirs = [[0,1],[1,0],[0,-1],[-1,0]]
	if not maze or not maze[0]:
		return -1
	if start[0]==destination[0] and start[1]==destination[1]:
		return 0
	m, n = len(maze), len(maze[0])
	dist = [[sys.maxint]*n for _ in range(m)]
	dist[start[0]][start[1]] = 0
	heap = []
	heappush(heap, (0, start[0], start[1]))
	while heap:
		cur = heappop(heap)
		for d in dirs:
			l, x, y = cur[0], cur[1], cur[2]
			while 0<=x<m and 0<=y<n and maze[x][y]==0:
				x += d[0]
				y += d[1]
				l += 1
			x -= d[0]
			y -= d[1]
			l -= 1
			if dist[x][y] > l:
				dist[x][y] = l
				heappush(heap, (l, x, y))
	res = dist[destination[0]][destination[1]]
	return res if res != sys.maxint else -1

# Maze III
def findShortestWay(self, maze, ball, hole):
	from heapq import *
	dirs = ((-1, 0, "u"), (1, 0, "d"), (0, -1, "l"), (0, 1, "r"))
	if not maze or not maze[0]: return "impossible"
	if ball == hole: return ''
	m, n = len(maze), len(maze[0])
	dist = {(ball[0], ball[1]): [0, '']}
	heap = [(0, '', ball[0], ball[1])]
	while heap:
		l, path, x, y = heappop(heap)
		if [x, y] == hole:
			return path
		for i, j, p in dirs:
			nx, ny, d = x, y, 0
			while 0<nx+i<m and 0<=ny+j<n and maze[nx+i][ny+j]!=1:
				nx += i
				ny += j
				d += 1
				if nx = hole[0] and ny == hole[1]:
					break
			if (nx, ny) not in dist or dist[(nx, ny)] > [l+d, path+p]:
				dist[(nx, ny)] = [l+d, path+p]
				heappush(heap, (l=d, path+p, nx, ny))
	return "impossible"

# Next Permutation
def nextPermutation(self, nums):
	right = len(nums) - 1
	while right-1>=0 and nums[right]<=nums[right-1]:
		right -= 1
	if right == 0:
		nums[:] = reversed(nums)
	else:
		pivot = right-1
		sucessor = 0
		for i in range(len(nums)-1, pivot, -1):
			if nums[i] > nums[pivot]:
				successor = i
				break
		nums[pivot], nums[successor] = nums[successor], nums[pivot]
		nums[pivot+1:] = reversed(nums[pivot+1:])

# Previous Permutation
def previousPermutation(self, nums):
	right = len(nums)-1
	while right-1>=0 and nums[right-1]<=nums[right]:
		right -= 1
	if right == 0:
		nums[:] = reversed[nums]
	else:
		pivot = right-1
		successor = 0
		for i in range(len(nums)-1, pivot, -1):
			if nums[i] < nums[pivot]:
				successor = i
				break
		nums[pivot], nums[successor] = nums[successor], nums[pivot]
		nums[pivot+1:] = reversed(nums[pivot+1:])












