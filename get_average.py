filenames = ['1m', '5m', '10m', '15m', '20m', '25m', '30m']

for f in filenames:
    file = open(f, 'r')
    packetCounter = 1
    packets = []

    for i in range(1, 41):
        packets.append(str(i))
    missedPackets = []
    receivedPackets = []
    rssiReading = 0
    total = 0

    for line in file:
        fields = line.split(" ")
        receivedPackets.append(fields[1][:-1])
        rssiReading += int(fields[3])
        total += 1

    for packet in packets:
        if packet not in receivedPackets:
            missedPackets.append(packet)

    print("Finished reading file " + f + ".")
    print("Packet loss:")
    print(missedPackets)
    print("Average RSSI: ")
    print(rssiReading/total)