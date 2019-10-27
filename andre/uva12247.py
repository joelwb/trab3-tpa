"""
Author: André Martins
UVa Online Judge Problem: 12247 Jollo

This code verify which is the last card that the prince needs 
to receive from the servant and win on Jollo from his sister.

"""

"""
This method get the input cards, verifying if receveid any 0 on input, to stop the code.
Also, it cleans and update the array of valid cards on the deck.
"""
def inputCards():
    #Create array of input cards and Array of Valid cards
    cards: list = []
    validCards: list = [True for x in range(53)]

    # Set the 0 Inputs to false and read the keyboard input
    hasZeroInput: bool = False
    cards = input().split(' ')
    
    # Iterate on the input cards, converting to integer 
    # and verying zeros. Also update the array of valid cards
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
        # Separate de Cards
        princessCards = cards[0:3]
        princeCards = cards[3:5]

        # Sort the cards from minor to maior
        princessCards.sort()
        princeCards.sort()
        
        # Set the Default value when the prince lose.
        newCard = -1

        # Verify if the first prince's card is bigger than the last princess card
        # This means that the prince already has 2 bigger cards
        if(princeCards[0] > princessCards[2]):
            for i in range(1, 52):
                if(validCards[i]):
                    newCard = i
                    break
                #end-if
            #end-for
        #end-if
        else:
            # Verify if the second prince's card is bigger than the last Princess Card
            # This means that the prince still have a chance if theres any card bigger than princess[2]
            if(princeCards[1] > princessCards[2]):
                for i in range(princessCards[2] + 1, 52):
                    if(validCards[i]):
                        newCard = i
                        break
                    #end-if
                #end-for
            #end-if
            
            # Verify if the first prince's card is bigger than the second Princess Card
            # This means that the prince still have a chance if theres any card bigger than princess[1]
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