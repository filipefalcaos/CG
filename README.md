# computer-graphics
Code for COMP269 - Computer Graphics (UFAL)

## Compilation

### ice-hockey-rink
Ice Hockey Rink is the version of project-1 that presents a Qt GUI. To compile you must have: (i) *Qt*, *qmake* and *make* installed in your system; and (ii) the *OpenGL/GLUT* libs installed in your system. Then, just run the following commands:
```
cd ice-hockey-rink
qmake ice-hockey-rink.pro
make
./ice-hockey-rink
```

### project-1
To compile you must have: (i) *CMake* and *make* installed in your system; and (ii) the *OpenGL/GLUT* libs installed in your system. Then, just run the following commands:
```
cmake project-1/CMakeLists.txt
make
./project-1
```

### flor-de-abril and translate-example
Just run the bash script inside the script's folder (linux only):
```
bash flor-de-abril/run.sh
./Flor

bash translate-example/run.sh
./RetanguloAzulVermelho
```
