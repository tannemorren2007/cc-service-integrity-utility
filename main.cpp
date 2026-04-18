import sys

def luhn_checksum_research(sequence):
    """
    Standard Luhn Algorithm (MOD-10) for integrity research.
    """
    digits = [int(d) for d in str(sequence)]
    checksum = digits[-1]
    payload = digits[:-1][::-1]
    
    total = 0
    for i, d in enumerate(payload):
        if i % 2 == 0:
            d *= 2
            if d > 9: d -= 9
        total += d
    
    return (total + checksum) % 10 == 0

def main():
    print("--- CC Service Integrity Utility v1.0.4 ---")
    print("[*] Initializing MOD-10 Validation Engine...")
    
    target = input("[?] Enter sequence for structural audit: ")
    if luhn_checksum_research(target):
        print(f"[SUCCESS] Sequence '{target}' is structurally VALID.")
    else:
        print(f"[ERROR] Sequence '{target}' failed checksum integrity.")

if __name__ == "__main__":
    main()
