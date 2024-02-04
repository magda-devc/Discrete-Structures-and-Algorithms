def rotate_array(nums, k):
    k = k % len(nums)

    reverse(nums, 0, len(nums) - 1)
    
    reverse(nums, 0, k - 1)
    
    reverse(nums, k, len(nums) - 1)

def reverse(nums, start, end):
    while start < end:
        nums[start], nums[end] = nums[end], nums[start]
        start += 1
        end -= 1

nums = [1, 2, 3, 4, 5, 6, 7]
k = 3
rotate_array(nums, k)
print("Rotated Array:", nums)
