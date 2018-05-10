import pygame
import sys

pygame.init()
display_width = 800
display_height = 600
black = (0, 0, 0)
white = (255, 255, 255)
#red = (255, 0, 0)
boardDisplay = pygame.display.set_mode((display_width, display_height))
pygame.display.set_caption('LKABA ARENA')
player1_Img = pygame.image.load('bonus/box_green.png')
player2_Img = pygame.image.load('bonus/box_green.png')
#player1Img = pygame.color.load(white)
#player2Img = pygame.color.load(black)
def player1(p1_width, p1_height):
    boardDisplay.blit(player1_Img, (p1_width, p1_height))
#def player2(x, y):
    #boardDisplay.blit(player2_Img, (x, y))

p1_width = (display_width * 0.45)
p1_height = (display_height * 0.8)


clock = pygame.time.Clock()
crashed = False
while not crashed:   
    for event in pygame.event.get() :
        if event.type == pygame.QUIT :
            crashed = True
        #sys.stderr.write((event)
    boardDisplay.fill(white)
    player1(p1_width, p1_height)
    
   # for line in sys.stdin:
        #sys.stdout.write(line)
    for i in range (0, 6):
        sys.stderr.write(sys.stdin.readline())
    player_num = int(sys.stdin.readline()[10])
    print ('player = ', player_num)
    sys.stderr.write(sys.stdin.readline())
    sys.stderr.write(sys.stdin.readline())
    sys.stderr.write(sys.stdin.readline())
    sys.stderr.write(sys.stdin.readline())
    masterlist = []
    for i in range(0, 100):
        s = list(sys.stdin.readline().split()[1])
        masterlist.append(s)
    print(masterlist)
    sys.stderr.write(sys.stdin.readline())
    
    # for i in masterlist:
    #     for char in i:
    #         if char == 'x'
    #             draw red square
    #         elif 
    sys.exit()
    
    pygame.display.update()
    clock.tick(60)
pygame.quit()
quit()