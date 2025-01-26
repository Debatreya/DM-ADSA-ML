def numPaths(wh):
    rows = len(wh)
    cols = len(wh[0])
    
    paths = [[0] * cols for _ in range(rows)]
    if wh[0][0] == 1:
        paths[0][0] = 1

    for i in range(1, rows):
        if wh[i][0] == 1:
            paths[i][0] = paths[i - 1][0]

    for j in range(1, cols):
        if wh[0][j] == 1:
            paths[0][j] = paths[0][j - 1]

    for i in range(1, rows):
        for j in range(1, cols):
            if wh[i][j] == 1:
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1]

    return paths[rows - 1][cols - 1] % (10**9 + 7)