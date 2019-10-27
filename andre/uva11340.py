"""
Author: André Martins
UVa Online Judge Problem: 11340 Newspaper

This code calculates the total value of an inputed article
according with the value of each charactere and show

"""

def main():

    # Get the total of case tests
    numberTest = int(input())

    for i in range(numberTest):

        # Get the number of chars that should be inputed
        numberPaidChar = int(input())

        # Fill the dictionary according with {'char': 'paid value'}
        paidChars = {}
        for j in range(numberPaidChar):
            inputCharVal = input().split(' ')
            paidChars[inputCharVal[0]] = int(inputCharVal[1])
        # end-for

        # Get the number of lines of the article, read and concatenate
        article = ""
        numberLinesArticle = int(input())
        for j in range(numberLinesArticle):
            article = article + input()
        # end-for

        # Iterate on the chars of the article and get its total occurrence
        # taking care to dont reapeat the calculation
        calculatedChar = {}
        for char in article:
            if(char not in calculatedChar.keys()):
                totalChar = article.count(char)
                calculatedChar[char] = totalChar
            # end-if
        # end

        # iterate on the amount of chars and multiply by the paid value for each
        totalValue = 0
        for char in paidChars.keys():
            if(char in calculatedChar.keys()):
                totalValue = totalValue + (calculatedChar[char] * paidChars[char])
            #end-if
        #end-for

        # print the result
        finalValue = totalValue / 100.0
        print('%.2f$' % (finalValue))
    # end-for

# end-main()

if __name__ == "__main__":
    main()
# end-if
