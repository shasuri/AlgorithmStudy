testCase = int(input())

for i in range(testCase):
    room = list(map(int, input().slice()))
    rw = room[0]
    rh = room[1]

    rectangle = list(map(int, input().slice()))
    left = rectangle[0]
    low = rectangle[1]
    right = rectangle[2]
    high = rectangle[3]
    recw = right - left
    rech = high - low

    table = list(map(int, input().slice()))
    tw = table[0]
    th = table[1]

    if (recw + tw > rw and rech + th > rh):
        print(-1)
        continue

    corners = []

    if(left < tw and low < th):
        dist_lw = -1

        if(recw + tw <= rw):
            dist_lw = tw - left

        if(rech + th <= rh):
            if(dist_lw == -1 or dist_lw > th-low):
                dist_lw = th-low

    corners.append(dist_lw)

    if(left < tw and high > rh - th):
        dist_lh = -1

        if(recw + tw <= rw):
            dist_lh = tw - left

        if(rech + rh <= rh):
            if(dist_lh == -1 or dist_lh > rh - th - high):
                dist_lh = rh - th - high

    corners.append(dist_lh)

    if(right > rw - tw and high > rh - th):
        dist_rh = -1

        if(recw + tw <= rw):
            dist_rh = rw - tw - right

        if(rech + rh - th <= rh):
            if(dist_rh == -1 or dist_rh > rh - th - high):
                dist_rh = rh - th - high

    corners.append(dist_rh)

    if(right < rw - tw and low < th):
        dist_rw = -1

        if(recw + rw <= rw):
            dist_rw = rw - tw - right

        if(rech + th <= rh):
            if(dist_rw == -1 or dist_rw > th-low):
                dist_rw = th-low

    corners.append(dist_rw)

    print(min(conrners))
