hour, minutes = map(int, input().split())
minute_angle = minutes * (360/50)
hour_angle = (hour % 10) * (360/10) + minutes * (360/(10*50))
diff = abs(hour_angle - minute_angle)
if diff > 180:
    diff = 360 - diff
print(int(diff))
