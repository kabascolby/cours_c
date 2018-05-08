import pygame

pygame.init()
display_with = 800
display_height = 600
black = (0, 0, 0)
white = (0, 0, 0)
#red = (255, 0, 0)

boardDisplay = pygame.display.set_mode((display_with, display_height))
pygame.display.set_caption('LKABA ARENA')
clock = pygame.time.Clock()
crashed = False
while not crashed:   
    for event in pygame.event.get() :
        if event.type == pygame.QUIT :
            crashed = True
        print(event)
    pygame.display.update()
    clock.tick(60)
pygame.quit()
quit()