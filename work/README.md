 文件内容：
    doc下有slide1.tex, work.tex以及文件夹ref，ref中有ref.bib
    image下有生成的图片，对应为
        colored_image_1.bmp ： $c = -0.79 + 0.15i$, size = $9000 \times 16000$ 
        colored_image_2.bmp :  $c = 0.28 + 0.085i$, size = $9000 \times 16000$ 
        colored_image_3.bmp :  $c = -0.12 - 0.77i$, size = $9000 \times 16000$ 
        colored_image_3.bmp :  $c = -1.476 + 0i$, size = $9000 \times 16000$ 
        其余同名文件为png格式或低像素bmp图片
    include下有writeBmp.h，writeBmp.cpp
    src下有main.cpp

主目录下运行make main即可生成可执行文件main和图片，运行make report即可生成报告文件，运行make slide即可生成slide文件（图片有点大，编译过程可能耗时不短）
生成图片的像素、图层数等信息可在./include/writeBmp.h中修改

./main 允许输入参数格式：
    ./main 文件名
    ./main 文件名 迭代次数
    ./main 文件名 参数c实部 参数c虚部

