# Objects file:

```
[Header];[Objects];[Lights];
```

## Header

```
TopLeftCornerX,TopLeftCornerY,TopLeftCornerZ,
ImageHeight,ImageWidth,
PlaneA,PlaneB,PlaneC;
NbObjects;NbLights
```

## Objects

```
ObjectAName,CenterX,CenterY,CenterZ,ObjArgumentA,ObjArgumentB,...;
ObjectBName,CenterX,CenterY,CenterZ,ObjArgumentA,ObjArgumentB,...
```

## Lights

```
light,PosX,PosY,PosZ;
light,PosX,PosY,PosZ;
light,PosX,PosY,PosZ
```

## Exemple

```
1,2,3,400,500,5,4,8;1;1;ellipsoid,12,15,23,15,20,5;light,30,40,44
```