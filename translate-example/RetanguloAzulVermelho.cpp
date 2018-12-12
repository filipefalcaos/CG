/*
 * Desafio: verificar o modelview
 */

#include <iostream>
#include <GL/freeglut.h>
#include <GL/gl.h>


void init (void)
{
  /* selecionar cor de fundo (preto) */
  glClearColor (0.0, 0.0, 0.0, 0.0);

  glMatrixMode (GL_MODELVIEW); //Projecao 2D

  gluOrtho2D (0.0, 600.0, 0.0, 400.0); //Definindo os limites da Porta de Visao (ViewPort)

}

//desenha as transformacoes
void displayRet(void){
	
	//limpa o display
	glClear(GL_COLOR_BUFFER_BIT); 

	//Cria um Retangula na cor Azul
	glColor3f(0.0, 0.0, 1.0);		 
	glRecti(50, 100, 200, 150);

	//Cria um Retangula na cor vermelho e translada
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef( 200.0, -50.0, 0.0);
	glRecti(50, 100, 200, 150);

    //executa os comandos
	glFlush();

}

void exit(unsigned char key, int x, int y)	{

	if( key == 'q' )
		exit(0);
}


int main(int argc, char *argv[]) {
	
	/* inicializa o sitema GLUT */
	glutInit(&argc, argv);									

	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(600,400);						
	glutCreateWindow("Retangulos");	

	//chama a funcao init e inicia as propriedades View Port
	init(); 
	/* Callback para mostrar objetos na tela */
	glutDisplayFunc(displayRet);					
	/* Callback para para interagir com teclado */
	glutKeyboardFunc(exit);						
	/* inicia o processamento dos eventos... */
	glutMainLoop();										

}
