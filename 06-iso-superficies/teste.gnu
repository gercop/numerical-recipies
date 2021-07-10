# set terminal png truecolor nocrop enhanced size 450,320 font "arial,8" 
# set output 'hidden2.2.png'
unset border
set dummy u, v
set format cb "%.1f" 
unset key
set parametric
set view 60, 30, 1.5, 0.9
set isosamples 50, 20
set size ratio 0 0.55,0.9
set origin 0.4,0
unset xtics
unset ytics
unset ztics
set title "PM3D surface\ndepth sorting" 
set urange [ -3.14159 : 3.14159 ] noreverse nowriteback
set vrange [ -3.14159 : 3.14159 ] noreverse nowriteback
set pm3d depthorder
set colorbox user
set colorbox vertical origin screen 0.9, 0.15, 0 size screen 0.02, 0.5, 0 front bdefault
f(x,y) = sin(-sqrt((x+5)**2+(y-7)**2)*0.5)
GPFUN_f = "f(x,y) = sin(-sqrt((x+5)**2+(y-7)**2)*0.5)"
splot cos(u)+.5*cos(u)*cos(v),sin(u)+.5*sin(u)*cos(v),.5*sin(v) with pm3d,1+cos(u)+.5*cos(u)*cos(v),.5*sin(v),sin(u)+.5*sin(u)*cos(v) with pm3d
