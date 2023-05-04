import random

EQUATION_CNT = 14
VARIABLE_CNT = 15
ANSWER = [random.randrange(2001) - 1000 for _ in range(VARIABLE_CNT)]

for i in range(EQUATION_CNT):
    print('{', end=' ')
    eq_sum = 0
    for j in range(VARIABLE_CNT):
        parameter = random.randrange(200001) - 100000
        print(parameter, end=', ')
        eq_sum += parameter * ANSWER[j]
    print(eq_sum, end=' ')
    print('},')

with open('answer_input', 'w') as f:
    for a in ANSWER:
        f.write(f'{a}\n')
