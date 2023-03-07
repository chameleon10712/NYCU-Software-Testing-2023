import math


class Calculator:

    @staticmethod
    def divide(x, y):
        return x / y

    @staticmethod
    def add(x, y):
        return x + y

    @staticmethod
    def sqrt(x):
        return math.sqrt(x)

    @staticmethod
    def exp(x):
        return math.exp(x)


if __name__ == '__main__':
    # Calculator.add(1, '2')
    Calculator.divide(1, 0)
