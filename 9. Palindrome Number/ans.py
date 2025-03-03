def min_operations_to_palindrome(num):
    num_str = str(num)
    if num_str == num_str[::-1]:
        return 0
    
    candidates = []
    l = len(num_str)
    
    if l > 1:
        candidates.append('9' * (l - 1))
    candidates.append('1' + '0' * (l - 1) + '1')
    
    k = (l + 1) // 2
    prefix = num_str[:k]
    
    for delta in (-1, 0, 1):
        new_prefix = str(int(prefix) + delta)
        if l % 2 == 0:
            candidate = new_prefix + new_prefix[::-1]
        else:
            candidate = new_prefix + new_prefix[:-1][::-1]
        candidates.append(candidate)
    
    original_num = int(num_str)
    min_steps = float('inf')
    
    for candidate in candidates:
        if not candidate:
            continue
        candidate_num = int(candidate)
        if candidate_num == original_num:
            continue
        steps = abs(candidate_num - original_num)
        if steps < min_steps:
            min_steps = steps
    
    return min_steps