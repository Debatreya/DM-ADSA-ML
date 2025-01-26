def timeOfBuffering(arrivalRate, packets):
    buffer = []
    current_time = 1
    for i in range(len(packets)):
        buffer.append(packets[i])
        buffer.sort()
        if buffer and buffer[0] == current_time:
            buffer.pop(0) 
        else:
            return current_time
        current_time += 1
    return -1