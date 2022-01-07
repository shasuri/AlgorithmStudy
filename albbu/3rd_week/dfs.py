def perm(arr, depth, n):
    # depth가 0부터 시작하여 k라면 k개를 모두 뽑은 것이므로 print하고 return
    if (depth == n):
        print(arr)
        return
    for idx in range(depth, n):
        # 각 depth에 대해 남아 있는 것들 중에 모두 뽑아보고,
        # 해당 경우에 대해 재귀적으로 perm 함수를 돌리고,
        # 원상복구 하여 다시 경우의 수를 찾는다
        arr[idx], arr[depth] = arr[depth], arr[idx]
        perm(arr, depth+1, n)
        arr[idx], arr[depth] = arr[depth], arr[idx]

perm([0,1,2,3,4,5,6,7],0,8)