# TODO
from cs50 import get_int

def main():
    user_input = input("Number: ")

    total = check(user_input)
    remainder = total % 10

    post_input = int(user_input)

    if remainder == 0:
        first_two = post_input / 10**14
        first_one = post_input / 10**15
        if first_two >= 51 and first_two <=55:
            print("MASTERCARD")
        elif first_one == 4:
            print("VISA")
        else:
            print("INVALID")

    elif post_input > 10**14 and post_input < 10**15:
        fifteen_two = post_input / 10**13
        if fifteen_two == 34 or fifteen_two == 37:
            print("AMEX")
        else:
            print("INVALID")

    else:
        print("INVALID")


def check(number):
    digits = digits_of(number)
    odd_digits = digits[-1::-2]
    even_digits = digits[-2::-2]
    checksum = 0
    for d in even_digits:
        checksum += sum(digits_of(d*2))
    checksum += sum(odd_digits)
    return checksum


def digits_of(n):
    return [int(d) for d in str(n)]

main()