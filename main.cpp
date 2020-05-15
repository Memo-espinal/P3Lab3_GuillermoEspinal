#include <windows.h>
#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

//conway(mat, x, y, turnos);

/*1.Cualquier célula viva con menos de dos vecinos vivos muere (por subpoblación).
2.Cualquier célula viva con dos o tres vecinos vivos vive hasta la próxima generación.
3.Cualquier célula vivacon más de tres vecinos vivos muere (por sobrepoblación).
4.Cualquier célula muerta con exactamente tres vecinos vivos se convierte en una célula viva (por reproducción).*/
void printCharMatrix(int ** matriz, int x,int y){
	if(matriz!=NULL){
		for(int i = 0; i<y;i++){
			for(int j=0;j<x;j++){
				if (matriz[i][j]!=0){
					cout<<matriz[i][j]<<" "; 
				}else{
					cout<<"x"<<" ";
				}
			}
			cout<<endl;
		}//forj
	}//endif	
}

void freeCharMatrix(int**& matriz, int x,int y){
	//liberar la memoria de la matriz
	if(matriz!=NULL){
		
		//liberar los arreglos de chars
		for(int i =0; i<y;i++){
			delete[] matriz[i];
		} 
		
		//liberamos el arreglo de apuntadores a char (char*)
		delete[] matriz;
		
		matriz=NULL;
	}
}


void Conway(int**& matriz, int x,int y, int turnos){
	int round =1;
	while (round <=turnos ){
		for(int i=0;i < y; i++){
			for (int j =0 ; j < x; j++){
				int vecinos_vivos=0;
				
				//evaluacion de la primera celula
				if (i==0 &&j==0){
					//validaciones si i ==0 y j ==0
					if (matriz[i+1][j]==1){
						vecinos_vivos++;
					}
					if (matriz[i+1][j+1]==1){
						vecinos_vivos++;
					}
					if (matriz[i][j+1]==1){
						vecinos_vivos++;
					}
					
					//Aqui veremos si hay que ponerle el cambio aqui o despues jeje
					
				}else if(i==0	&&	j>0	&&	j<x-1){//validaciones de la primera fila
					if (matriz[i][j-1]==1){
						vecinos_vivos++;
					}
					if (matriz[i][j+1]==1){
						vecinos_vivos++;
					}
					if (matriz[i+1][j-1]==1){
						vecinos_vivos++;
					}
					if (matriz[i+1][j]==1){
						vecinos_vivos++;
					}
					if (matriz[i+1][j+1]){
						vecinos_vivos++;
					}
					//Aqui veremos si hay que ponerle el cambio aqui o despues jeje
				} else if (i==0 && j==x-1){ //evaluacion de la ultima celula de la primera fila
					if(matriz[i][j-1]==1){
						vecinos_vivos++;
					}
					if(matriz[i+1][j-1]){
						vecinos_vivos++;
					}
					if (matriz[i+1][j]){
						vecinos_vivos++;
					}
					
				//Aqui veremos si hay que ponerle el cambio aqui o despues jeje
				}else if (j==0 && i <y-1){ 	//validacion si la celula esta en la primera columna y no es la ultima de la columna
					if (matriz[i-1][j]==1){
						vecinos_vivos++;
					}
					if (matriz[i-1][j+1]==1){
						vecinos_vivos++;
					}
					if (matriz[i][j+1]==1){
						vecinos_vivos++;
					}
					if (matriz[i+1][j+1]==1){
						vecinos_vivos++;
					}
					if (matriz[i+1][j]==1){
						vecinos_vivos++;
					}
					//Aqui veremos si hay que ponerle el cambio aqui o despues jeje
					
				}else if ( j==x-1 && i!=y-1){	//validacion si es la ultima de la fila  //i==y-1 &&
					if (matriz[i-1][j-1]==1){
						vecinos_vivos++;
					}
					if (matriz[i-1][j]==1){
						vecinos_vivos++;
					}
					if (matriz[i][j-1]==1){
						vecinos_vivos++;
					}
					if (matriz[i+1][j-1]){
						vecinos_vivos++;
					}
					if (matriz[i+1][j]){
						vecinos_vivos++;
					}
					//Aqui veremos si hay que ponerle el cambio aqui o despues jeje
					
				}else if (i==y-1 && j==0){ //validacion si es la ultima de la columna y es la primera de la fila
					if (matriz[i-1][j]==1){
						vecinos_vivos++;
					}
					if (matriz[i-1][j+1]==1){
						vecinos_vivos++;
					}
					if (matriz[i][j+1]==1){
						vecinos_vivos++;
					}
				}else if (i==y-1 && j!=0 && j<x-2 ){ //validacion si esta en la ultima fila 
					if (matriz[i][j-1]==1){
						vecinos_vivos++;	
					}
					if (matriz[i-1][j-1]==1){
						vecinos_vivos++;	
					}
					if (matriz[i-1][j]==1){
						vecinos_vivos++;	
					}
					if (matriz[i-1][j+1]==1){
						vecinos_vivos++;	
					}
					if (matriz[i][j+1]==1){
						vecinos_vivos++;	
					}
					
					
				}else if( i==y-1 && j==x-1){//validacion si es la ultima de la fila y es la ultima de las columnas
					if (matriz[i-1][j-1]==1){
						vecinos_vivos++;	
					}
					if (matriz[i][j-1]==1){
						vecinos_vivos++;	
					}
					if (matriz[i-1][j]==1){
						vecinos_vivos++;	
					}
					
					
				}else{// este solo es para uno que este en cualquier lugar que no sea mencionado antes
					if(matriz[i-1][j-1]==1){
						vecinos_vivos++;
					}
					if(matriz[i][j-1]==1){
						vecinos_vivos++;
					}
					if(matriz[i+1][j-1]==1){
						vecinos_vivos++;
					}
					if(matriz[i-1][j]==1){
						vecinos_vivos++;
					}
					if(matriz[i+1][j]==1){
						vecinos_vivos++;
					}
					if(matriz[i-1][j+1]==1){
						vecinos_vivos++;
					}
					if(matriz[i][j+1]==1){
						vecinos_vivos++;
					}
					if(matriz[i+1][j+1]==1){
						vecinos_vivos++;
					}
					
					
				}
				// FINAL DE LAS VALIDACIONES 
				// medir los vecinos y decision si vive o muere
					/*1.Cualquier célula viva con menos de dos vecinos vivos muere (por subpoblación).
					2.Cualquier célula viva con dos o tres vecinos vivos vive hasta la próxima generación.
					3.Cualquier célula vivacon más de tres vecinos vivos muere (por sobrepoblación).
					4.Cualquier célula muerta con exactamente tres vecinos vivos se convierte en una célula viva (por reproducción).*/
				
				if (matriz[i][j]==1){
					if (vecinos_vivos<2){
						matriz[i][j]=0;
					}else if (vecinos_vivos==2 ||vecinos_vivos==3){
						matriz[i][j]=1;
					}else if (vecinos_vivos>3){
						matriz[i][j]=0;
					}
				}else if (matriz[i][j]==0){
					if (vecinos_vivos==3){
						matriz[i][j]=1;
						
					}
				}
				 
			}
		}
		printCharMatrix(matriz,x,y);
		cout<<endl;
		cout<<endl;
		
		round++;	
		getch();
	}
	
	
	freeCharMatrix(matriz,x,y);
}




int ** creatIntMatrix(int x, int y ){
	int** matriz = NULL;
	matriz = new int*[y];
		for(int i = 0; i<y;i++){
			matriz[i] = new int[x]; 
		}
			
	return matriz ;
}


int main (){
	srand(time(NULL));
	
	int respuesta;
	cout <<"Bienvenido al juego de la vida de Conway"<<endl ;
	cout <<"1.- Jugar con una matriz random."<<endl;
	cout <<"2.- Jugar con una matriz predeterminada."<<endl;
	cout <<"3.- Salir."<<endl;

	cin >>respuesta;
	switch (respuesta){
		case 1:
			int columnas,filas;
		
			int turnos;
			cout << "Ingrese la cantidad de columnas en la matriz : "<<endl ;
			cin>> columnas;
			cout << "Ingrese la cantidad de filas en la matriz : "<<endl;
			cin>> filas;
			cout << "Ingrese cuantos turnos quiere jugar : "<< endl ;
			cin >> turnos;
			
			int**matriz=NULL;
			
			//creamos la matriz 
			matriz= creatIntMatrix(columnas,filas);
		
			//rellenamos la matriz de 1 y cero
			for (int i = 0; i<filas;i++ ){
				for(int j = 0; j<columnas;j++){
				matriz[i][j]= 0 + rand()%(2-0);	
				}
				
			}
			//imprimimos la matriz 
			printCharMatrix(matriz,columnas,filas);
			cout<<endl;
			cout<<endl;
			
			Conway(matriz,columnas,filas,turnos);
			
			// liberamos la matriz
			freeCharMatrix(matriz,columnas,filas);
			
			break;
		//case 2 : 
			//break;
		//case 3 : 
			//break;
		
	}
	
	
}

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
