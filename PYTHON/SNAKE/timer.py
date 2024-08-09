from turtle import Turtle
import time


class Timer(Turtle):

    def __init__(self):
        super().__init__()
        self.hideturtle()
        self.color("white")
        self.penup()
        self.goto(-255, 265)
        self.start_time = time.time()
        self.elapsed_time = 0
        self.update_timer()

    def update_timer(self):
        self.elapsed_time = int(time.time() - self.start_time)
        self.clear()
        self.write(f"Time: {self.elapsed_time} s", align="center", font=("Arial", 16, "normal"))
        self.getscreen().ontimer(self.update_timer, 1000)

    def get_elapsed_time(self):
        return self.elapsed_time

    def save_time_to_file(self):
        with open("login.txt", "a") as file:
            file.write(f"Czas gry: {self.elapsed_time} sekund \n")
