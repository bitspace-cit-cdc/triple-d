def index_of_first_and_last_occurrence(haystack, needle):
    first_index = haystack.find(needle)
    if first_index == -1:
        return -1
    last_index = haystack.rfind(needle)
    return first_index + last_index

haystack = input()
needle = input()

print(index_of_first_and_last_occurrence(haystack, needle))