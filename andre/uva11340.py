# uva11340


def main():
    numberTest = int(input())

    for i in range(numberTest):
        numberPaidChar = int(input())

        paidChars = {}
        for j in range(numberPaidChar):
            inputCharVal = input().split(' ')
            paidChars[inputCharVal[0]] = int(inputCharVal[1])
        # end-for

        article = ""
        numberLinesArticle = int(input())
        for j in range(numberLinesArticle):
            article = article + input()
        # end-for

        calculatedChar = {}
        for char in article:
            if(char not in calculatedChar.keys()):
                totalChar = article.count(char)
                calculatedChar[char] = totalChar
            # end-if
        # end

        totalValue = 0
        for char in paidChars.keys():
            if(char in calculatedChar.keys()):
                totalValue = totalValue + (calculatedChar[char] * paidChars[char])
            #end-if
        #end-for

        finalValue = totalValue / 100.0
        print('%.2f$' % (finalValue))
    # end-for

# end-main()


if __name__ == "__main__":
    main()
# end-if
