# uva10920
from itertools import cycle
from math import ceil
from enum import Enum

class Side(Enum):
    Up = 1
    Left = 2
    Down = 3
    Right = 4
#end-class

def main():
    inputData = input().split(' ')

    boardSize = int(inputData[0])
    position = int(inputData[1])
    
    while(boardSize != 0 and position != 0):
        side = cycle([Side.Up, Side.Left, Side.Down, Side.Right])
        middle = ceil(boardSize/2.0)
        middleLine = middleColumn = middle

        stepSize = 1
        stepsDone = 1
        incrementStep = False
        actualSide = Side.Up #Just to declare Var
        while(stepsDone < position):
            actualSide = next(side)

            if(actualSide == Side.Up):
                middleLine = middleLine + stepSize
            #end-if
            elif(actualSide == Side.Left):
                middleColumn = middleColumn - stepSize
                incrementStep = True
            #end-elif
            elif(actualSide == Side.Down):
                middleLine = middleLine - stepSize
            #end-elif
            else:
                middleColumn = middleColumn + stepSize
                incrementStep = True
            #end-if

            stepsDone = stepsDone + stepSize

            if(incrementStep):
                stepSize = stepSize + 1
                incrementStep = False
            #end-if
        #end-while

        if(stepsDone > position):
            stepBack = stepsDone - position

            if(actualSide == Side.Up):
                middleLine = middleLine - stepBack
            #end-if
            elif(actualSide == Side.Left):
                middleColumn = middleColumn + stepBack
            #end-elif
            elif(actualSide == Side.Down):
                middleLine = middleLine + stepBack
            #end-elif
            else:
                middleColumn = middleColumn - stepBack
            #end-if
        #end-if

        print('Line = %d, column = %d.' % (middleLine, middleColumn))

        inputData = input().split(' ')
        boardSize = int(inputData[0])
        position = int(inputData[1])
    #end-while
# end-main()


if __name__ == "__main__":
    main()
# end-if
