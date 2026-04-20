def maximumLengthSubstr(s: str) -> int:
    left = 0
    right = 0
    _max = 0
    counter: dict[str, int] = {}

    while right < len(s):
        char_r = s[right]
        counter[char_r] = counter.get(char_r, 0) + 1
        
        # Invariante: nenhum caractere pode ter frequência 3
        while counter[char_r] == 3:
            char_l = s[left]
            counter[char_l] -= 1
            left += 1
        
        current_window_size = right - left + 1
        if current_window_size > _max:
            _max = current_window_size
            
        right += 1
    return _max


def main():
    cases = [
        ("aaaa", 2),
        ("aaabb", 4),
        ("bcbbbcba", 4), 
        ("", 0),
        ("abcdef", 6),
        ("aabbccade", 8)
    ]
    
    for s, expected in cases:
        result = maximumLengthSubstr(s)
        print(f"String: {s:10} | Esperado: {expected} | Resultado: {result}")

if __name__ == "__main__":
    main()