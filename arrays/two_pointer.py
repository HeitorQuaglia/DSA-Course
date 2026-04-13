def odd(i: int) -> bool: 
    return i & 1 == 0

def main():
    #ex 1: inverter string
    left = 0
    right = 0 
    stri = ['c', 'a', 'r', ' ', 'b' ,'a', 'r', 't']
    
    #find blank
    for i, ch in enumerate(stri):
        if ch == ' ':
            right = i
    
    #reversing first
    reverse_word(stri, left, right - 1, odd(right))
    #reverse second
    left = right + 1 
    right = len(stri) -1
    reverse_word(stri, left, right, odd(1 + right - left))

    print(stri)

def reverse_word(arr: list, p1: int, p2: int, odd: bool):
    print(arr, p1, p2, odd)
    if odd and p1 == (p2 + 1):
        return
    elif p1 == p2:
        return
    
    temp = arr[p1]
    arr[p1] = arr[p2]
    arr[p2] = temp

    return reverse_word(arr, p1 + 1, p2 - 1, odd)


if __name__ == "__main__":
    main()