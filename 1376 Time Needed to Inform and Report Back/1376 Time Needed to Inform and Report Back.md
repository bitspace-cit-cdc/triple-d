# Time Needed to Inform and Report Back

A company has `n` employees with unique IDs ranging from `0` to `n - 1`. The head of the company is identified by `headID`. Each employee has a direct manager given in the `manager` array, where `manager[i]` is the direct manager of the `i-th` employee, and `manager[headID] = -1`. The company’s hierarchy has a tree structure.

The company has an urgent piece of news that needs to be communicated:
1. The `headID` starts by informing their direct subordinates.
2. Each employee takes `informTime[i]` minutes to inform all their direct subordinates.
3. Once informed, all employees must report back to their direct managers, taking the same amount of time it took to inform their subordinates.

Your task is to calculate the total time required for the entire process: from the moment the head starts informing employees until all employees have reported back to their managers.

## Input
- An integer `n` (1 ≤ `n` ≤ 10⁵), representing the total number of employees.
- An integer `headID` (0 ≤ `headID` < `n`), representing the ID of the head of the company.
- An array `manager` of size `n`, where `manager[i]` is the direct manager of the `i-th` employee (`-1` for the `headID`).
- An array `informTime` of size `n`, where `informTime[i]` is the time (in minutes) the `i-th` employee needs to inform all their subordinates (0 if the employee has no subordinates).

## Output
- Return the total time (in minutes) required to complete the informing and reporting process.

---

## Examples

### Example 1
**Input:**  
`n = 1`  
`headID = 0`  
`manager = [-1]`  
`informTime = [0]`  

**Output:**  
`0`

**Explanation:**  
The company has only one employee, so no informing or reporting is needed.

---

### Example 2
**Input:**  
`n = 6`  
`headID = 2`  
`manager = [2, 2, -1, 2, 2, 2]`  
`informTime = [0, 0, 1, 0, 0, 0]`

**Output:**  
`2`

**Explanation:**  
1. The head (employee `2`) informs all their direct subordinates in `1` minute.
2. Each subordinate reports back to the head, taking another `1` minute.
3. Total time = `1 (inform) + 1 (report) = 2`.

---

### Example 3
**Input:**  
`n = 7`  
`headID = 0`  
`manager = [-1, 0, 0, 1, 1, 2, 2]`  
`informTime = [1, 2, 3, 0, 0, 0, 0]`

**Output:**  
`8`

**Explanation:**  
1. The head (employee `0`) informs employees `1` and `2` in `1` minute.
2. Employee `1` informs employees `3` and `4` in `2` minutes. Employee `2` informs employees `5` and `6` in `3` minutes.
3. Once informed, employees report back to their direct managers:
   - Employees `3` and `4` report to `1` in `2` minutes.
   - Employees `5` and `6` report to `2` in `3` minutes
   - Employees `1` and `2` report to `0` in `1` minute..
4. Total time = `1 (inform by 0) + 3 (inform by 2) + 3 (report to 2) + 1 (report to 0) = 8`.

---

## Constraints
1. `1 ≤ n ≤ 10⁵`
2. `0 ≤ headID < n`
3. `manager.length == n`
4. `0 ≤ manager[i] < n` or `manager[i] == -1`
5. `informTime.length == n`
6. `0 ≤ informTime[i] ≤ 1000`
7. It is guaranteed that all employees can be informed.
