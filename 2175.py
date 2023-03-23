#function that returns the area of a triangle with input of 3 dots
def t_Area(dot1, dot2, dot3):
    x,y = 0,1
    return abs(((dot2[x] - dot1[x])*(dot3[y]-dot1[y]) - (dot3[x]-dot1[x]) * (dot2[y] - dot1[y]))/2)
#function that returns the middle point of 2 dots
def middlePoint(dot1, dot2):
    return [(dot1[0]+dot2[0])/2 , (dot1[1]+dot2[1])/2]

arr = list(map(float, input().split()))
for i in range(4):
    arr.append([arr[i*2],arr[i*2+1]])
arr = arr[-4:]

arr_with_middle_point = [arr[0], middlePoint(arr[0],arr[1]), arr[1], middlePoint(arr[1],arr[2]), arr[2], middlePoint(arr[2], arr[3]), arr[3], middlePoint(arr[3], arr[0])]

left_half, right_half = 0,1e9

for i in range(8):
    #case where dividing from edge
    if i%2 == 0:
        target_dots = []
        for j in range(2,7):
            target_dots.append((i+j)%8)
        triangles = []
        for k in range(4):
            triangles.append(t_Area(arr_with_middle_point[i], arr_with_middle_point[target_dots[k]], arr_with_middle_point[target_dots[k+1]]))
        for l in range(3):
            x = sum(triangles[:l+1])
            y = sum(triangles[l+1:])
            if abs(x-y)<abs(left_half-right_half):
                left_half, right_half = x,y

    #case where dividing from a middle point
    else:
        target_dots = []
        for j in range(1,8):
            target_dots.append((i+j)%8)
        triangles = []
        for k in range(6):
            triangles.append(t_Area(arr_with_middle_point[i], arr_with_middle_point[target_dots[k]], arr_with_middle_point[target_dots[k+1]]))
        for l in range(5):
            x = sum(triangles[:l+1])
            y = sum(triangles[l+1:])
            if abs(x-y)<abs(left_half-right_half):
                left_half, right_half = x,y
left_half = round(left_half,3)
right_half = round(right_half,3)

if left_half<right_half:
    print(left_half, right_half)
else:
    print(right_half, left_half)