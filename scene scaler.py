#x,y,z

def move_point(point,x,y,z):
    point[0]=point[0]+x
    point[1]=point[1]+y
    point[2]=point[2]+z
    return point
    
def point_to_cube(point,scale):
    cube=[]
    cube.append([point[0]*scale,               point[1]*scale,         point[2]*scale               ])
    cube.append([(point[0]+point[3][0])*scale, point[1]*scale,         point[2]*scale               ])
    cube.append([(point[0]+point[3][0])*scale, point[1]*scale,         (point[2]+point[3][1])*scale ])
    cube.append([point[0]*scale,               point[1]*scale,         (point[2]+point[3][1])*scale ])
    cube.append([point[0]*scale,               (point[1]+scale)*scale, point[2]*scale               ])
    cube.append([(point[0]+point[3][0])*scale, (point[1]+scale)*scale, point[2]*scale               ])
    cube.append([(point[0]+point[3][0])*scale, (point[1]+scale)*scale, (point[2]+point[3][1])*scale ])
    cube.append([point[0]*scale,               (point[1]+scale)*scale, (point[2]+point[3][1])*scale ])
    cube.append(point[4])#add block's element
    return cube

def gen_cubes(part,center,scale):
    cubes=[]
    for i in range(0,len(part)):
        cubes.append( point_to_cube ( move_point ( part[i], center[0], center[1], center[2]),scale ) )
    return cubes

def dispaly_cubes(cubes):
    for i in range(0,len(cubes)):
        for j in range(0,8):
            print(cubes[i][j])
            print("---")
        print("matiere : ")
        print(cubes[i][8])
        print("\n")
        print("\n")

c0  =[3,0,2,[1,1],"stone"]
c1  =[3,1,2,[1,2],"stone"]
c2  =[2,2,2,[2,2],"stone"]
c3  =[2,3,2,[2,2],"stone"]
c4  =[1,4,1,[4,5],"stone"]
c5  =[1,5,1,[5,5],"stone"]
c6  =[0,6,0,[6,6],"stone"]
c7  =[0,7,0,[7,7],"dirt"]
c8a =[0,8,1,[7,6],"grass"]
c8b =[1,8,0,[2,1],"grass"]
c8c =[4,8,0,[2,1],"grass"]
c9b =[3,9,4,[4,3],"grass"]
c9c =[4,9,2,[3,1],"grass"]
c9a =[3,9,3,[1,1],"wood"]
c10 =[3,10,3,[1,1],"wood"]
c11 =[3,11,3,[1,1],"wood"]
c12 =[2,12,2,[3,3],"leaves"]
c13a=[2,13,3,[1,1],"leaves"]
c13b=[3,13,2,[1,3],"leaves"]
c13c=[4,13,3,[1,1],"leaves"]
c14 =[3,14,3,[1,1],"leaves"]
c15 =[8,15,2,[3,4],"cloud"]
c16 =[9,16,3,[2,3],"cloud"]
c17 =[1,17,9,[3,3],"cloud"]
c18 =[2,18,9,[2,2],"cloud"]

center = [0,0,0]

scale = 1

part = [
    c0,
    c1,
    c2,
    c3,
    c4,
    c5,
    c6,
    c7,
    c8a,c8b,c8c,
    c9a,c9b,c9c,
    c10,
    c11,
    c12,
    c13a,c13b,c13c,
    c14,
    c15,
    c16,
    c17,
    c18
]

dispaly_cubes(gen_cubes(part,center,1))
