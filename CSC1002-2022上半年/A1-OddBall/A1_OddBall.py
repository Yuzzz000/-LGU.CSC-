import random
import sys

def intro():                        # Display an introduction about the game. 
    print('Welcome to odd-ball game!')
    print('How to play the game?')
    print('First, input an even number, minimum 2. It is the number of the ball.\n'
    'We will label all the balls and randomly choose one to be heavier.')
    print('Then, You are expected to find the heavier ball. There is a weighing scale for you to use.')
    print('Game begins. Have fun!')

def enterBallNumber():              # Ask player to enter the right ball number.
    global g_n
    g_n = input('Enter the number of ball (reminder: it should be even):')
    try:
        g_n = int(g_n)
    except:
        print('Invalid input!')     # If g_n is not an integer, then ask user to input again.
        enterBallNumber()
    if g_n % 2 == 1 or g_n < 2:
        print('Invalid input!')     # If g_n is not even or is less than 2, ask user to input again.
        enterBallNumber()
    
def chooseOddBall():                # Choose the odd ball randomly.
    global g_oddball
    g_oddball = int(g_n*random.random()+1) 
    g_oddball = str(g_oddball) 

def setPans():                      # put balls onto pans
    print('You are prompted to enter the balls to be placed on the pans of the scale, \
        seperated each ball identifierwith one minimum space, e.g. 1 2 3')
    left = input('The ball to be put on left:')
    right = input('The ball to be put on right:')
    left = left.split()
    right = right.split()
    t = 0                              # to show it is valid or not
    if len(left) != len(right):     # make sure the number of balls in two pans are the same.
        t = 1  
    for i in left:               # make sure the input is number
        try:
            a = int(i)
        except:
            t = 1
            break
        if a < 1 or a > g_n:        #make sure the input number is in the valid interval
            t = 1
        for j in right:     # make sure no ball is in both pans
            if i == j:
                t = 1
                break
        if t == 1: break
    
    for i in right:
        try:
            a = int(i)
        except:
            t = 1
            break
        if a < 1 or a > g_n:        
            t = 1
            break

    if t == 1:
        print('Please ensure correct ball identifiers are entered on each pan, no duplicate\
            balls on either or both pans. Both pans should have the same number of balls and must\
                have at least one ball')
        setPans()
    else:
        global g_left
        global g_right
        g_left = left
        g_right = right
        
def scaleResult():          
    if g_oddball in g_left:
        print('The scale shows: left is heavier')   
    elif g_oddball in g_right:
        print('The scale shows: right is heavier')
    else:
        print('The scale is balanced.')

def guess():
    global g_tf         # to show the answer is right o not
    uGuess = input('Enter the odd ball number:')
    try:
        a = int(uGuess)       # make sure the user input the valid number
    except:
        print('Invalid input!')
        guess()
    if a < 1 or a > g_n:
        print('Invalid input!')
        guess()
    if uGuess == g_oddball:
        g_tf = 1
    else:
        g_tf = 0


def gameCircle():
    n=1             # the scale usage count
    while True:
        setPans()
        scaleResult()
        guess()
        if g_tf == 0:
            n += 1
            print('Regretfully, the answer is wrong. Try again!')
            continue
        else:
            print('Congratulations! You get the right answer!')
            print('Scale usage count:',n)
            break


def oddBallGame():          # the whole game for once
    intro()
    enterBallNumber()
    chooseOddBall()
    gameCircle()

def main():
    oddBallGame()
    while True:
        yn = input('Do you want to do the game? \n Please answer yes if you want.\
            Otherwise you will quit.')
        if yn == 'yes':
            oddBallGame()
        else:
            sys.exit()

main()







    

