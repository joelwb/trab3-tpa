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

        run = 0
        stepSize = 1
        stepsDone = 1
        incrementStep = False
        while(stepsDone != position):
            actualSide = next(side)
            while(stepsDone < position and run < stepSize):
                
                if(actualSide == Side.Up):
                    middleLine = middleLine + 1
                #end-if
                elif(actualSide == Side.Left):
                    middleColumn = middleColumn - 1
                    incrementStep = True
                #end-elif
                elif(actualSide == Side.Down):
                    middleLine = middleLine - 1
                #end-elif
                else:
                    middleColumn = middleColumn + 1
                    incrementStep = True
                #end-if

                run = run + 1
                stepsDone = stepsDone + 1
            #end-while

            run = 0
            if(incrementStep):
                stepSize = stepSize + 1
                incrementStep = False
            #end-if
        #end-while

        print('Line = %d, column = %d.' % (middleLine, middleColumn))

        inputData = input().split(' ')
        boardSize = int(inputData[0])
        position = int(inputData[1])
    #end-while
# end-main()


if __name__ == "__main__":
    main()
# end-if
