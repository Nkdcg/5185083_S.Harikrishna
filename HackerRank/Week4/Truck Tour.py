def truckTour(petrolpumps):
    total_petrol = 0
    total_distance = 0
    start_index = 0
    balance = 0

    for i, (petrol, distance) in enumerate(petrolpumps):
        total_petrol += petrol
        total_distance += distance
        balance += petrol - distance

        # If balance becomes negative, reset start point
        if balance < 0:
            start_index = i + 1
            balance = 0

    # If total petrol < total distance, journey not possible
    if total_petrol < total_distance:
        return -1
    return start_index


if __name__ == '__main__':
    n = int(input().strip())
    petrolpumps = []
    for _ in range(n):
        petrolpumps.append(list(map(int, input().split())))

    result = truckTour(petrolpumps)
    print(result)
