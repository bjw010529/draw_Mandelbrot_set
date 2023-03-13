set terminal epslatex color size 14cm,12cm
set output '毕嘉文_homgwork6-gnuplottex-fig1.tex'
set key top left
set xlabel 'x [1]'
set ylabel 'y [1]'
plot x**2 ,x**2+10 , x**2-10
