def binary_search(nums: list[int], n: int) -> int:
    low = 0
    high = len(nums)
    
    while low < high:
        mid = int((low+high) / 2)

        if nums[mid] == n:
            return mid
        elif nums[mid] < n:
            low = mid + 1
        else:
            high = mid
    
    return -1

def main():
    a = list(range(5))
    b = list(range(10))
    c = list(range(20))
    d = list(range(40))

    a_p = binary_search(a, 4)
    b_p = binary_search(b, 7)
    c_p = binary_search(c, 14)
    d_p = binary_search(d, 22)
    
    print(a_p)
    print(b_p)
    print(c_p)
    print(d_p)

if __name__ == "__main__":
    main()