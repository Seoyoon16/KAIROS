# turtle module ko import karwana

from turtle import*

# title me naam kya dena chahte ho

title("Python Turtle Art")

# background color kya dena chahte ho

bgcolor("black")

# draw karne ki speed 

speed(0)

# pen ka size kitna rakhna chahte ho

pensize(3)

for i in range(9):

    # pen ka color kya dena chahte ho

    color("yellow") 

    # turtle ko 60degree pr move karna

    left(60)

    circle(-18, 200)

    color("yellow", "red")

    # radius 100 rakhna

    r = 100

    for j in range(12):

        begin_fill()

        circle(r-11*j, 90)

        end_fill()

    # turtle ko 180degree pr move karna    

    left(180) 

    # pen ka likhna band krta hai   

    penup()

    #turtle ko x or y position pr move krna

    goto(0,0)

    # pen ka likhna chalu krta hai

    pendown()

    # turtle ko gayab karta hai

    hideturtle()

done()
