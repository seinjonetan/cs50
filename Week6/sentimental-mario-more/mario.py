# TODO
from cs50 import get_int

def main():
    height = get_height()
    blanks = height - 1
    hash = 1
    for i in range(height):
        for k in range(blanks):
            print(" ", end="")
        for l in range(hash):
            print("#", end="")
        print("  ", end="")
        for m in range(hash):
            print("#", end="")
        print()
        blanks -= 1
        hash += 1



def get_height():
    while True:
        height = get_int("Height: ")
        if height > 0 and height < 9:
            return height

main()