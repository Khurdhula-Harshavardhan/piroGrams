
  




market=list()


def getLowestcap():
    lowest=market[0][1]
    coin=""
    for item in market:
        if lowest>=item[1]:
            coin=item[0]

    index=0
    for coinsss in market:
        if coinsss[0] == coin:
            market.pop(index)
            break
        else:
            index+=1



    return coin

        





x=int(input("enter the number of currencies : "))

for _ in range(x):
    name = input("Enter coin name : ")
    cap= float(input("enter market cap : "))
    market.append((name,cap))
    print(market)



rank=1

for _ in range(x):
    getCoin=getLowestcap()
    print(" #%d %s "%(rank,getCoin.upper()))
    rank+=1