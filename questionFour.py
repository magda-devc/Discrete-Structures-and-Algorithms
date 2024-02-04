def single_number(nums):
    result = 0   
    for num in nums:
        result ^= num
    
    return result

nums = [2, 3, 1, 2, 1]
print("Single Number: ", single_number(nums)) 
