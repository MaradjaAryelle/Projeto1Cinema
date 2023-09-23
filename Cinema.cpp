#include <iostream>

using namespace std;

const int linha = 10;
const int coluna = 10;
int sala[linha][coluna];
float valorEntrada = 12.50;
int vendidas = 0;

void mostrarSala(){
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            if(sala[i][j] == -1){
                cout << "X" << "\t";
            } else{
                cout << sala[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

bool comprarIngresso(){
    int numeroPoltrona = -1;
    
    cout << "Digite o numero da poltrona: ";
    cin >> numeroPoltrona;            
    
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            if(sala[i][j] == numeroPoltrona){
                sala[i][j] = -1;
                vendidas += 1;
                cout << "Ingresso comprado com sucesso!\n";
                return true;
            }
        }
    }
    cout << "Poltrona indisponivel!\n";
    return false;
}

void exibirRelatorio(){
    cout << "Foram vendidas " << vendidas << " e a receita foi de R$ " << valorEntrada * vendidas << endl;
}

int main(int argc, char** argv) {
    int opcao = -1;
    
    int auxiliar = 1;
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            sala[i][j] = auxiliar++;
        }
    }
    
    while (opcao != 0) {
        cout << " -> Digite: 1- Exibir Sala; 2-Comprar Ingresso; 3-Exibir Relatorio de Vendas; 0- para sair: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                mostrarSala();
                break;
                
            case 2:
                comprarIngresso();
                break;
        
            case 3:
                exibirRelatorio();
                break;
                
            case 0:
                cout << "TCHAU" << endl;
                break;
                
            default:
                cout << "Opcao inexistente!" << endl;
                break;
        }
    }
    return 0;
}
