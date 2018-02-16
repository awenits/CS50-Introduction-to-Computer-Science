import cs50

def main():
    height = get_height()
    
    for i in range(height):
        #prints spaces
        print(" " * (height - (i + 1)), end = "")
        #prints hashes
        print("#" * (i + 2))

#to get the correct height    
def get_height():
    while True:
        print("Height: ", end = "")
        n = cs50.get_int()
        if (0 <= n <= 23):
            break
    return n
    
if __name__ == "__main__":
    main()