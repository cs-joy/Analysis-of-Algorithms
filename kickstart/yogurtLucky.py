class Case:
    def __init__(self, bought, limit_per_day, yogurt_expiration):
        self.bought = bought
        self.limit_per_day = limit_per_day
        self.yogurt_expiration = sorted(yogurt_expiration) # check sorted function later
        self.consumed = 0
    
    def consume(self):
        day = 0
        consumed_today = 0

        for i in range(self.bought):
            # Lucky has consumed her limit for the day -
            # "go forward" one day
            if consumed_today == self.limit_per_day:
                day += 1
                consumed_today = 0
                #  Lucky can only consume yogurt expire
                # after today ("day")
            if self.yogurt_expiration[i] > day:
                consumed_today += 1
                self.consumed += 1
        return self.consumed

t = int(input())
for i in range(1, t + 1):
    bought, limit_per_day = [int(j) for j in input().split()] # check later split function
    yogurt_expiration = [int(k) for k in input().split()]
    case = Case(bought, limit_per_day, yogurt_expiration)
    print("Case #{}: {}" .format(i, case.consume())) # check out later format function