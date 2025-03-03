class Employee:
    def __init__(self, id, importance, working, subordinates):
        self.id = id
        self.importance = importance
        self.working = working
        self.subordinates = subordinates

def dfs(employees_map, emp_id, total_importance):
    if employees_map[emp_id].working:
        total_importance[0] += employees_map[emp_id].importance
    for subordinate in employees_map[emp_id].subordinates:
        dfs(employees_map, subordinate, total_importance)

def get_importance(employees, emp_id):
    employees_map = {}
    for emp in employees:
        employees_map[emp.id] = emp
    total_importance = [0]
    dfs(employees_map, emp_id, total_importance)
    return total_importance[0]


n = int(input()) 
employees = []

for _ in range(n):
	id, importance, working, num_subordinates = map(int, input().split())
	working = bool(working)
	subordinates = list(map(int, input().split())) if num_subordinates > 0 else []
	
	employees.append(Employee(id, importance, working, subordinates))

emp_id = int(input())  

print(get_importance(employees, emp_id))