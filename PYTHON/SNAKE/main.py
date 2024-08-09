from turtle import Screen
from snake import Snake
from food import Food
from scoreboard import Scoreboard
from timer import Timer
import time
import os
import shutil
from datetime import datetime


def move_login_file():
    # Generowanie unikalnej nazwy pliku
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    unique_filename = f"{timestamp}.txt"
    # Przenoszenie pliku login.txt do folderu "game_logs" z unikalną nazwą
    folder_name = "game_logs"
    if not os.path.exists(folder_name):
        os.makedirs(folder_name)
    shutil.move("login.txt", os.path.join(folder_name, unique_filename))


def start_game():
    global speed
    from interface import difficulty_level  # Importujemy wybrany poziom trudności

    screen = Screen()
    screen.setup(width=600, height=600)
    screen.bgcolor("black")
    screen.title("Snake")
    screen.tracer(0)

    snake = Snake()
    food = Food()
    scoreboard = Scoreboard()
    timer = Timer()

    screen.listen()
    screen.onkey(snake.up, "Up")
    screen.onkey(snake.down, "Down")
    screen.onkey(snake.left, "Left")
    screen.onkey(snake.right, "Right")

    game_is_on = True

    # Ustawiamy prędkość w zależności od poziomu trudności
    if difficulty_level == "Easy":
        speed = 0.15
    elif difficulty_level == "Normal":
        speed = 0.1
    elif difficulty_level == "Hard":
        speed = 0.05

    while game_is_on:
        screen.update()
        time.sleep(speed)
        snake.move()

        # FOOD
        if snake.head.distance(food) < 20:
            food.refresh()
            snake.extend()
            scoreboard.increase_score()

        # WALLS
        if snake.head.xcor() > 280 or snake.head.xcor() < -280 or snake.head.ycor() > 280 or snake.head.ycor() < -280:
            game_is_on = False
            scoreboard.game_over()

        # TAIL
        for segment in snake.segments[1:]:
            if snake.head.distance(segment) < 10:
                game_is_on = False
                scoreboard.game_over()

    timer.save_time_to_file()
    move_login_file()  # Przeniesienie pliku po zakończeniu gry
    screen.exitonclick()


if __name__ == "__main__":
    from interface import main as login_main

    login_main()
    start_game()
