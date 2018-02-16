import sys

#ensures proper usage
if len(sys.argv) != 2:
    print("Usage: python caesar.py k")
    exit(1)

#prompts user for input        
plaintext = input("plaintext : ")

#generates and prints ciphertext        
print("ciphertext : ", end = "")
for c in plaintext:
    if c.isalpha():    
        if c.islower():
            print(chr((((ord(c) % 97) + int(sys.argv[1])) % 26) + 97), end = "")
        else:
            print(chr((((ord(c) % 65) + int(sys.argv[1])) % 26) + 65), end = "")
    else:
        print(c, end = "")
print()

#success        
exit(0)