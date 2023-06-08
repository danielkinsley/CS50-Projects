from cs50 import get_float

while True:
    cash = get_float("Change owed: ")
    if cash > 0:
        break
if cash > 0:

    coin = round(cash*100)
    coins = 0
    q = 0
    d = 0
    n = 0
    p = 0

    q = int(coin/25)
    d = int((coin % 25) / 10)
    n = int(((coin % 25) % 10) / 5)
    p = int(((coin % 25) % 10) % 5)

    coins += q + d + n + p

    print(coins)


