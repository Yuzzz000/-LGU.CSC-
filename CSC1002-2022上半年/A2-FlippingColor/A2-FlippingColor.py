

# 写在前面：这一套下来我觉得写得非常简洁。不过乱点会报错，按要求点就没事。

import turtle as t                  
import random

screen = t.Screen()
intro=t.Turtle()
tileList = [0] * 25        # Set a list to store all the tiles, which are turtles
colorBarList=[0] * 5           # Set a list to store all the turtles in color bar
colorList = ['lightcoral', 'tan', 'skyblue', 'darkseagreen', 'plum']      # A list containing 5 colors


def setScreen():                # set the screen
    screen.screensize(500, 500)
    screen.title("Color Flipping Game 121090741")

def introduction():         # the introduction page before the game.
    intro.hideturtle()
    intro.up()
    intro.write("It's a color flipping game.\n \
The goal is to turn all tiles to the same color.\n \
Choose one tile on the board and then click the desired color in the color bar below to change the color of the chosen tile.\n \
The newly selected color will spread to all its neighbering tiles which match the original color of the chosen tile\n \
Click anywhere to start the game. Enjoy your time!", align="center", font = ('Arial', 12, 'normal'))


def setTile(i):                     # Set one tile
    tileList[i] = t.Turtle('square')
    tileList[i].shapesize(4)
    tileList[i].color(random.choice(colorList))

def setTiles():                     # Set all the tiles in board
    posList = [-125, -40, 45, 130, 215]
    i=0
    for x in posList:
        for y in posList:
            setTile(i)
            tileList[i].up()
            tileList[i].setpos(x, y)
            i += 1

def setColorBar():                 # Set the color bar
    i=0
    for x in [-200, -120, -40, 40, 120]:
        colorBarList[i] = t.Turtle('square')
        colorBarList[i].shapesize(4)
        colorBarList[i].color(colorList[i])
        colorBarList[i].up()
        colorBarList[i].setpos(x, -280)
        i += 1
    
def setInterface():             # Set the whole interface
    screen.tracer(0)
    setTiles()
    setColorBar()
    screen.update()
    


def findNeighbor(i):
    neighbor=[]
    if (i+1)%5 != 0:                # find the file above, if exist
        neighbor.append(i+1)
    if (i+1)%5 != 1:                # find the file below, if exist
        neighbor.append(i-1)
    if i<20:
        neighbor.append(i+5)        # find the file right, if exist
    if i>4:
        neighbor.append(i-5)        # find the file left, if exist
    return neighbor
    
def flip(i, j, k):                 # i is the ith tile; j is the jth color, which is the original color; k is the kth color, which is the target color. This function is to flip the color of eligible tiles.
    tileList[i].color(colorList[k])
    neighbor=findNeighbor(i)
    for m in neighbor:
        if tileList[m].color()[1] == colorList[j]:
            flip(m, j, k)


def theChosenTile(i):               # use this function to put i into the function 'setBorder'
    def setBorder(x, y):            # make the border black when the tile is clicked
        for k in range(25):         # cancel the last black border by making all the border the same color as the interior.
            tileList[k].pencolor(tileList[k].color()[1])
        tileList[i].pencolor('black')
        screen.update()
    return setBorder

def theChosenColor(i):              # Similarly, use this function to put i into fucnction 'doFlip'
    def doFlip(x, y):               # Flip as request
        chosenColor = i
        for m in range(25):         # Check all the tiles to find the chosen one.
            if tileList[m].color()[0] == 'black':
                chosenTile = m
                originalColor = colorList.index(tileList[m].color()[1])
                break
        flip(chosenTile, originalColor, i)
        screen.update()
    return doFlip

def chooseTile():
    for i in range(25):
        tileList[i].onclick(theChosenTile(i))
    
def chooseColor():              # choose color and flip
    for i in range(5):
        colorBarList[i].onclick(theChosenColor(i))


def game(x, y):                 # the game body part
    intro.clear()
    setInterface()
    screen.onscreenclick(None)
    chooseTile()
    chooseColor()

if __name__ == "__main__":
    setScreen()
    introduction()
    screen.onscreenclick(game)
    screen.listen()
    screen.mainloop()     