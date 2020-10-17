from turtle import *
import svgwrite
from svg_turtle import SvgTurtle

# Prepare SVG
drawing = svgwrite.Drawing("primes.svg", size=("10000px", "15000px"))
drawing.add(drawing.rect(fill='white', size=("100%", "100%")))
t = SvgTurtle(drawing)
Turtle._screen = t.screen
Turtle._pen = t

# Open the file with sorted prime numbers on each line
file = open("primes.txt", "r")
primes = file.readlines()

# Draw
right(90)
prev = int(primes[0])
for i in range(1, len(primes)):
# for i in range(1, 5000):
    new = int(primes[i])
    forward(new - prev)
    right(90)
    prev = new


# Save
drawing.save()
