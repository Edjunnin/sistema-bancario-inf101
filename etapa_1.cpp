#include <iostream>
#include <string>
using namespace std;

int main()
{
    int tipoConta = 0, numeroConta = 0, opcao = 0;
    string nomeCliente, cpf;
    double saldo = 0.0;
    bool contaAtiva = false, contaCadastrada = false;
    
    //Nessa parte das declarações das variáveis eu coloquei uma do lado da outra separando por tipos.
    //Também criei uma nova variável chamada "contaCadastrada", faz sentido já que outras ações do sistema vão depender primeiramente de ter uma conta cadastrada.
    //Defini os valores das variáveis pra zero e false para evitar lixo de memória e garantir que tudo esteja zerado antes de qualquer coisa.
    //Eu pessoalmente acho que assim fica mais fácil de ver, e também consome menos linhas de código.
    
    do{
        cout<< "********************************** BANCO GUARDINO **********************************" <<endl;
    
    //O nome do banco vem de um sobrenome meu, que é um tanto exótico quanto o meu primeiro nome kkkkk.
        
        cout<< "1 - Cadastrar conta" <<endl;
        cout<< "2 - Consultar conta" <<endl;
        cout<< "3 - Verificar saldo" <<endl;
        cout<< "4 - Alterar tipo da conta" <<endl;
        cout<< "5 - Ativar/Desativar conta" <<endl;
        cout<< "6 - Sair \n"  <<endl;
    
        cout<< "ESCOLHA UMA OPÇÃO: ";
        cin >> opcao;
    
        switch(opcao){
            case 1:
                cout<< "Você entrou no cadastro de conta.\n" <<endl;
                cout<< "------------CADASTRO DE CONTA------------\n" <<endl;
                
                cout<< "Digite o número que você quer que corresponda a essa conta: ";
                cin>> numeroConta;
                while (numeroConta <=0) {
                    cout<< "Número Inválido! O número da conta tem que ser maior que zero: ";
                    cin >> numeroConta;
                }
                //Esse while é para garantir que o número da seja maior que zero.
                
                cin.ignore();
                //O cin ignore pra limpar o buffer pra não dar aquele bug da quebra de liinha do enter.
                
                cout<< "Digite o nome do titular da conta: ";
                getline(cin, nomeCliente);
                
                cout<< "Digite o CPF do titular da conta: ";
                getline(cin, cpf);
                while (cpf.length() != 11){
                    cout<< "CPF inválido! Um cpf deve conter exatamente 11 dígitos: ";
                    getline(cin, cpf);
                }
                //Essa validação foi algo que eu mesmo adicionei, já que não faria muito sentido um cpf não ter 11 números.
                
                cout<< "Escolha o tipo de conta.\n [1] Conta corrente \n [2] Conta poupança \n Digite o tipo da conta: ";
                cin>> tipoConta;
                while (tipoConta != 1 && tipoConta != 2) {
                    cout<< "Opção Inválida! Digite 1 para Conta corrente e 2 para conta poupança: ";
                    cin>> tipoConta;
                }
                // Esse while é para que o usuário possa escolher somente as duas opções possíveis.
                
                cout<< "Digite o saldo inicial da conta: ";
                cin>> saldo;
                while (saldo < 0.0) {
                    cout<< "Saldo Inválido! O saldo não pode ser negativo: ";
                    cin>> saldo;
                }
                //O while aqui é para garantir que o saldo não seja negativo.
                
                contaAtiva = true;
                contaCadastrada = true;
                //aqui é pra confirmar pro sistema que existe conta cadastrada e ativa.
                
                cout<< "Conta cadastrada com sucesso!"<< endl;
                
                break;
            case 2:
                cout<< "Você entrou na consulta de contas.\n" <<endl;
                cout<< "------------CONSULTA DE CONTAS------------\n" <<endl;
                if (!contaCadastrada) { // aqui, !contaCadastrada é a mesma coisa de contaCadastrada == false. Já que no case 1 essa váriavel foi mudada pra true.
                    cout<< "Nenhuma conta foi criada ainda.\n" <<endl;
                }// esse if é para caso o usuário tentar consultar uma conta sem ter nenhuma cadastrada.
                else {
                    if (contaCadastrada == true) {
                        cout<< "Numero da conta:  " << numeroConta << endl;
                        cout<< "Nome do titular:  " << nomeCliente << endl;
                        cout<< "CPF:  " << cpf << endl;
                    
                        if (tipoConta == 1) {
                            cout<< "Tipo da conta: Corrente" << endl;
                        }
                        else {
                            cout<< "Tipo da conta: Poupança" << endl;
                        }// if e else pra verificar o tipo de conta.
                        cout<< "Saldo: R$" << saldo << endl;
                    
                        if (contaAtiva == true) {
                            cout<< "Conta Ativa." << endl;
                        }
                        else {
                            cout<< "Conta Inativa." << endl;
                        } // if e else aqui utilizado para verificar se é uma conta ativa ou inativa.
                    }
                }
                break;
            case 3:
                cout<< "Você escolheu verificar saldo.\n" <<endl;
                cout<< "------------VERIFICAÇÃO DE SALDO------------\n" <<endl;
                
                if (!contaCadastrada) {
                    cout<< "Não existe conta cadastrada para verificar saldo.\n" << endl;
                }
                else if (!contaAtiva) { //aqui é a mesma coisa do !contaCadastrada, seria como um contaAtiva == false.
                    cout<< "Conta inativa. Não será possível verificar saldo.\n" << endl;
                }
                else {
                    cout<< "Saldo: R$" << saldo << endl;
                }
                break;
            case 4:
                cout<< "Você escolheu alterar tipo da conta.\n" <<endl;
                cout<< "------------ALTERAÇÃO DE TIPO DE CONTA------------\n" <<endl;
                
                if (!contaCadastrada) {
                    cout<< "Não existe conta cadastrada para alterar o tipo de conta.\n" << endl;
                }
                else if (!contaAtiva) {
                    cout<< "Conta inativa. Não será possível alterar o tipo de conta.\n" << endl;
                }
                else {
                     if (tipoConta == 1) {
                            cout<< "Tipo atual da conta: Corrente" << endl;
                        }
                        else {
                            cout<< "Tipo atual da conta: Poupança" << endl;
                        }
                    cout<< "Escolha seu novo tipo de conta.\n [1] Conta corrente \n [2] Conta poupança \n Digite o tipo da conta: ";
                    cin>> tipoConta;
                    while (tipoConta != 1 && tipoConta != 2) {
                    cout<< "Opção Inválida! Digite 1 para Conta corrente e 2 para conta poupança: ";
                    cin>> tipoConta; 
                    }
                    
                    cout<< "Tipo de conta alterado com sucesso!\n" << endl;
                    
                } // nesse case 4 eu copiei e colei a parte da escolha do tipo de conta do case 1.
                break;
            case 5:
                cout<< "Você escolheu ativar ou desativar uma conta.\n" <<endl;
                cout<< "------------ALTERAÇÃO DE STATUS DA CONTA------------\n" <<endl;
                
                if (!contaCadastrada) {
                    cout<< "Não existe conta cadastrada para alterar o status dela.\n" << endl;
                }
                else {
                    if (contaAtiva == true) { // aqui decidi usar o == true invés de de somente "contaAtiva". É pra variar um pouco o uso mesmo.
                        contaAtiva = false; // pra alterar a conta pra false
                        cout<< "Sua conta foi desativada com sucesso!\n" << endl;
                    }
                    else {
                        contaAtiva = true; // pra alterar pra true
                        cout<< "Sua conta foi ativada com sucesso!\n" << endl;
                    }
                }
                break;
            case 6:
                cout<< "Você escolheu sair.\n" <<endl;
                break;
            default:
                cout<< "Opção Inválida!\n" <<endl;
        }
    }while(opcao !=6); // esse é o do-while para o programa sempre voltar pro menu até que o usuário digite 6 para sair do sistema.
    

    return 0;
}