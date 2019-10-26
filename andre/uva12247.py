def inputCards():
    cards: list = []
    validCards: list = [True for x in range(53)]

    hasZeroInput: bool = False
    cards = input().split(' ')
    
    for i in range(len(cards)):
        toInt = int(cards[i])
        cards[i] = toInt

        if(toInt == 0):
            hasZeroInput = True
        else:
            validCards[toInt] = False
        #else
    #end-for

    return cards, validCards, hasZeroInput
#end-InputCards()

def main():
    cards, validCards, hasZeroInput = inputCards()

    princessCards:list = []
    princeCards:list = []
    
    while(not hasZeroInput):
        princessCards = cards[0:3]
        princeCards = cards[3:5]

        princessCards.sort()
        princeCards.sort()
        
        newCard = -1

        if(princeCards[0] > princessCards[2]):
            for i in range(1, 52):
                if(validCards[i]):
                    newCard = i
                    break
                #end-if
            #end-for
        #end-if
        else:
            if(princeCards[1] > princessCards[2]):
                for i in range(princessCards[2] + 1, 52):
                    if(validCards[i]):
                        newCard = i
                        break
                    #end-if
                #end-for
            #end-if
            
            if(princeCards[0] > princessCards[1]):
                for i in range(princessCards[1], 52):
                    if(validCards[i]):
                        newCard = i
                        break
                    #end-if
                #end-for
            #end-elif
        #end-else
        
        print(newCard)
        cards, validCards, hasZeroInput = inputCards()
    #end-while 
#end-main()

if __name__ == "__main__":
    main()
#end-if