f = open("1m", "r")
count = 0
total = 0

for line in f:
  fields = line.split(" ")
  val = int(fields[3])
  count += 1
  total += val

average = total/count
print(average)