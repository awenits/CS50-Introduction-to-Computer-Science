import cs50

def main():
    
    noofcoins = 0;
    change = get_valid_change()
    change = change * 100
    change = round(change)
    
    while change != 0 :
        cent = largest_cent(change)
        noofcoins = noofcoins + (change // cent)
        change = change % cent
    
    print(noofcoins)

#returns valid change value
def get_valid_change():
    print("O hai! ", end = "")
    while True:
        print("How much change is owed?") 
        n = cs50.get_float()
        if n > 0:
            break
    return n

#returns largest cent value 
def largest_cent(change) :
    if change >= 25 :
        return 25;
    elif change < 25 and change >= 10 :
        return 10;
    elif change < 10 and change >= 5 :
        return 5;
    else:
        return 1;

if __name__ == "__main__":
    main()