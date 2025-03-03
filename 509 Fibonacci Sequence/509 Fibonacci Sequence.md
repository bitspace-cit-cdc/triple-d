##  Fibonacci Sequence 


Given the `n`th and `(n+1)`th terms of a sequence, and the value of `n`, find the first term `F(0)` of the sequence.
	
The sequence is defined as:

- `F(n) = F(n - 1) + F(n - 2)` for `n > 1`

You're given `x`, which represents `F(n)`, and `y`, which represents `F(n+1)`. You are also given the integer `n`. Your task is to return the first term `F(0)` of the sequence.

### Example 1:

**Input**:  
`x = 3`, `y = 5`, `n = 3`

**Output**:  
`0`

### Example 2:

**Input**:  
`x = 26`, `y = 42`, `n = 5`

**Output**:  
`2`

### Constraints:

- `0 <= n <= 30`
- `0 <= x, y <= 10^9`
- The given `x` and `y` are valid Fibonacci-like numbers.