# TODO
from cs50 import get_string
import math

def main():
    text = get_string("Text: ")

    l = avg_letters(text)
    s = avg_sentences(text)
    score = 0.0588 * l - 0.296 * s - 15.8

    if score > 16:
        print("Grade 16+")
    elif score < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {round(score)}")


def count_words(text):
    word_count = 0
    for i in range(len(text)):
        if text[i].isalpha() and text[i + 1] == " ":
            word_count += 1
        elif text[i] == "." or text[i] == "?" or text[i] == "!" or text[i] == ",":
            if text[i -1].isalpha:
                word_count += 1
    return word_count


def avg_letters(text):
    char_count = 0
    for i in range(len(text)):
        if text[i].isalpha():
            char_count += 1
    avg = (char_count / count_words(text)) * 100
    return avg


def avg_sentences(text):
    sentence_count = 0
    for i in range(len(text)):
        if text[i] == "." or text[i] == "?" or text[i] == "!":
            sentence_count += 1
    avg = (sentence_count / count_words(text)) * 100
    return avg


main()