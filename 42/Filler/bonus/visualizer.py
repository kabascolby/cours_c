import pygame
import sys
from pygame.locals import *

lamine = pygame.image.load('bonus/ProfilePhoto.jpg')
pygame.display.set_icon(lamine)
pygame.init()


white = (255, 255, 255)
pygame.display.set_caption('LKABA ARENA')

def player1(x, y):
	boardDisplay.blit(player1_Img, (x, y))
def player2(x, y):
	boardDisplay.blit(player2_Img, (x, y))

masterlist = []

def board_loop(map_height):
	masterlist[:] = []
	for i in range(0, map_height):
		s = sys.stdin.readline().split()
		s = list(s[1])
		masterlist.append(s)
	# print(masterlist)

def skip_lines(cnt):
	for i in range(0, cnt):
	   sys.stderr.write(sys.stdin.readline())
	sys.stderr.write("\n")
clock = pygame.time.Clock()
crashed = False

for i in range (0, 6):
	sys.stderr.write(sys.stdin.readline())
s = sys.stdin.readline()
sys.stderr.write(s)
player_num = 1 if s[17:22] == "lkaba" else 0
sys.stderr.write(sys.stdin.readline())
s = sys.stdin.readline()
sys.stderr.write(s)
player_num = 2 if s[17:22] == "lkaba" else player_num
s = sys.stdin.readline()

map_height = int(s.split(' ')[1])
map_widht = int(s.split(' ')[2].split(':')[0])

display_width = 800 
display_height = 700

if map_height == 100:
	display_width = 1188
	display_height = 1200
if map_height == 24:
	display_width = 1400
	display_height = 840

boardDisplay = pygame.display.set_mode((display_width, display_height))
boardDisplay.fill(white)

p1_width = (display_width / map_widht)
p1_height = (display_height / map_height)

def image_swap(img1, img2):
	img3 = img1
	img1 = img2
	img2 = img3

player1_Img = pygame.image.load('bonus/' + ('purple_block_shrek.png' if player_num == 1 else 'green_block.png'))
player2_Img = pygame.image.load('bonus/' + ('purple_block_shrek.png' if player_num == 2 else 'red_block.png'))
player1_Img = pygame.transform.scale(player1_Img, (p1_height, p1_width))
player2_Img = pygame.transform.scale(player2_Img, (p1_height, p1_width))

sys.stdin.readline()
board_loop(map_height)
s = sys.stdin.readline()
cnt = int(s.split(' ')[1])
skip_lines(cnt)
pygame.display.update()
clock.tick(50)

countt = 0

while not crashed:
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			quit()
		if event.type == KEYDOWN:
			if event.key == K_ESCAPE:
				quit()

	s = sys.stdin.readline()
	s = sys.stdin.readline()
	if s[0] == 'P' and s[1] == 'i':
		cnt = int(s.split(' ')[1])
		skip_lines(cnt + 3)
	elif s[0] == '=':
		print(s)
		print(sys.stdin.readline())
		crashed = True
		continue
	elif s[0] == 'P' and s[1] == 'l':
		skip_lines(1)

	board_loop(map_height)
	s = sys.stdin.readline()
	cnt = int(s.split(' ')[1])
	skip_lines(cnt)

	for h, l in enumerate(masterlist):
		for w, item in enumerate(l):
			if item == 'x':
				player2(p1_width * w, p1_height * h,)
			elif item == 'o':
				player1(p1_width * w, p1_height * h,)

	pygame.display.update()
	clock.tick(120)

crashed = False
while not crashed:
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			crashed = True
		if event.type == KEYDOWN:
			if event.key == K_ESCAPE:
				crashed = True
pygame.quit()
quit()
