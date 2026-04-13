def frequency_map(arr):
    freq_map = {}
    for num in arr:
        if num in freq_map:
            freq_map[num] += 1
        else:
            freq_map[num] = 1
    return freq_map

def main():
    arr = [1, 2, 2, 3, 3, 3, 4]
    freq_map = frequency_map(arr)
    print(freq_map)

if __name__ == "__main__":
    main()