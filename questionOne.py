def remove_duplicates(nums):
    if not nums:
        return 0

    unique_pointer = 0

    for i in range(1, len(nums)):
        if nums[i] != nums[unique_pointer]:
            unique_pointer += 1
            nums[unique_pointer] = nums[i]

    return unique_pointer + 1

nums = [1, 1, 2, 2, 3, 4, 4, 4, 5,6,7,7,8]
new_length = remove_duplicates(nums)
print(f"Original Array: {nums[:new_length]}")
print(f"New Length: {new_length}")
