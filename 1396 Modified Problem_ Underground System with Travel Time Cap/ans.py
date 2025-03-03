class UndergroundSystem:
    def __init__(self, T: int):
        self.cap = T
        self.checkIns = {}
        self.travelData = {}
    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.checkIns[id] = (stationName, t)
    def checkOut(self, id: int, stationName: str, t: int) -> None:
        startStation, t0 = self.checkIns.pop(id)
        travelTime = t - t0
        if travelTime <= self.cap:
            key = startStation + "->" + stationName
            if key not in self.travelData:
                self.travelData[key] = [0, 0]
            self.travelData[key][0] += travelTime
            self.travelData[key][1] += 1
    def getAverageTime(self, startStation: str, endStation: str) -> float:
        key = startStation + "->" + endStation
        if key not in self.travelData or self.travelData[key][1] == 0:
            return -1.0
        total, count = self.travelData[key]
        return total / count

if __name__ == '__main__':
    import sys
    input_data = sys.stdin.read().split()
    idx = 0
    t = int(input_data[idx]); idx += 1
    outputs = []
    for _ in range(t):
        T = int(input_data[idx]); idx += 1
        system = UndergroundSystem(T)
        n = int(input_data[idx]); idx += 1
        for i in range(n):
            op = input_data[idx]; idx += 1
            if op == "checkIn":
                id = int(input_data[idx]); idx += 1
                station = input_data[idx]; idx += 1
                time = int(input_data[idx]); idx += 1
                system.checkIn(id, station, time)
            elif op == "checkOut":
                id = int(input_data[idx]); idx += 1
                station = input_data[idx]; idx += 1
                time = int(input_data[idx]); idx += 1
                system.checkOut(id, station, time)
            elif op == "getAverageTime":
                start = input_data[idx]; idx += 1
                end = input_data[idx]; idx += 1
                avg = system.getAverageTime(start, end)
                outputs.append(f"{avg:.5f}")
    sys.stdout.write("\n".join(outputs))