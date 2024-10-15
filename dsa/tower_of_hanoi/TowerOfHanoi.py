def TowerOfHanoi(n, source, dest, helper):
    if n == 0:
        return
    TowerOfHanoi(n-1, source, helper, dest)
    print("Move disk", n, "from rod", source, "to rod", dest)
    TowerOfHanoi(n-1, helper, dest, source)

N = int(input("Enter the number of disks: "))

# A: Source rod, B: Helper rod, C: Destination Rod
TowerOfHanoi(N, 'A', 'C', 'B')