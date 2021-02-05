import cs50


def main():
    while True:
        height = cs50.get_int("Height: ")
        width = height
        if height > 0 and height <= 8:
            break
    for i in range(1, height + 1):
        n_hash = i
        n_space = width - i
        print(" " * n_space, end="")
        print("#" * i, end="")
        print("  ",  end="")
        print("#" * i)


if __name__ == '__main__':
    main()
