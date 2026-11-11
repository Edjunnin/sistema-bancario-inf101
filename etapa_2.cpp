#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int MAX_CONTAS =100;
    
    int numeroConta[MAX_CONTAS];
    string nomeCliente[MAX_CONTAS];
    string cpf[MAX_CONTAS];
    int tipoConta[MAX_CONTAS];
    double saldo[MAX_CONTAS];
    bool contaAtiva[MAX_CONTAS];
    
    int quantidadeContas = 0;
    
    const int MAX_MOVIMENTACOES = 500;
    
    int contaMovimentacao[MAX_MOVIMENTACOES];
    char tipoMovimentacao[MAX_MOVIMENTACOES];
    double valorMovimentacao[MAX_MOVIMENTACOES];
    
    int quantidadeMovimentacao = 0;
    
    int opcao = 0;
    
    do{
        cout << "\n==========================================" << endl;
        cout << "           BANCO GUARDINO                 " << endl;
        cout << "==========================================" << endl;
        cout << " 1 - Cadastrar conta" << endl;
        cout << " 2 - Listar as contas cadastradas" << endl;
        cout << " 3 - Consultar uma conta pelo número" << endl;    
        cout << " 4 - Realizar depósitos" << endl;   
        cout << " 5 - Realizar saques" << endl;
        cout << " 6 - Realizar transferências entre contas" << endl;
        cout << " 7 - Exibir o extrato de uma conta" << endl;
        cout << " 8 - Desativar/ativar uma conta" << endl;
        cout << " 9 - Sair" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
       
        while (opcao < 1 || opcao > 9 ){
            cout << "Opção inválida! Digite uma opção válida (1 a 9): ";
            cin >> opcao;
        }

        cout << endl;
        
        switch(opcao){
            
            case 1:
                cout << ">>> CADASTRO DE CONTA <<<" << endl;
                if(quantidadeContas >= MAX_CONTAS){
                    cout << "Número máximo de contas cadastradas atingido!" << endl;
                    break;
                }
                
                cout << "Digite o número da conta que você quer cadastrar: ";
                cin >> numeroConta[quantidadeContas];
                while (numeroConta[quantidadeContas] <= 0) {
                    cout << "Número inválido! O número da conta deve ser maior que zero: ";
                    cin >> numeroConta[quantidadeContas];
                }

                cin.ignore();
                
                cout << "Qual é o nome do cliente: ";
                getline(cin, nomeCliente[quantidadeContas]);
                
                cout << "Digite o CPF do cliente (apenas 11 dígitos): ";
                getline(cin, cpf[quantidadeContas]);
                while (cpf[quantidadeContas].length() != 11){
                    cout << "CPF inválido! O CPF deve conter exatamente 11 dígitos: ";
                    getline(cin, cpf[quantidadeContas]);
                }

                cout << "Digite o tipo da conta (1- Corrente, 2- Poupança): ";
                cin >> tipoConta[quantidadeContas];
                while (tipoConta[quantidadeContas] != 1 && tipoConta[quantidadeContas] != 2) {
                    cout << "Opção inválida! Digite 1 para Corrente ou 2 para Poupança: ";
                    cin >> tipoConta[quantidadeContas];
                }

                cout << "Digite o saldo inicial da conta: R$";
                cin >> saldo[quantidadeContas];
                while (saldo[quantidadeContas] < 0.0) {
                    cout << "Saldo inválido! O saldo inicial não pode ser negativo: R$";
                    cin >> saldo[quantidadeContas];
                }
                
                contaAtiva[quantidadeContas] = true;
                quantidadeContas++;

                cout << "\n--> Conta cadastrada com sucesso!" << endl;
                break;
            
            case 2:
                cout << ">>> CONTAS CADASTRADAS <<<" << endl;
                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada no momento." << endl;
                } else {
                    for (int i = 0; i < quantidadeContas; i++) {
                        cout << "------------------------------------------" << endl;
                        cout << "Número da conta: " << numeroConta[i] << endl;
                        cout << "Nome do cliente: " << nomeCliente[i] << endl;
                        cout << "CPF do cliente : " << cpf[i] << endl;
                        cout << "Tipo da conta  : " << (tipoConta[i] == 1 ? "Corrente" : "Poupança") << endl;
                        cout << "Saldo          : R$" << saldo[i] << endl;
                        cout << "Status         : " << (contaAtiva[i] ? "Ativa" : "Inativa") << endl;
                    }
                    cout << "------------------------------------------" << endl;
                }
                break;
            
            case 3:
                cout << ">>> CONSULTA DE CONTA <<<" << endl;
                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada!" << endl;
                } else {
                    int numeroConsulta;
                    cout << "Digite o número da conta que deseja consultar: ";
                    cin >> numeroConsulta;
                    
                    bool contaEncontrada = false;
                    for (int i = 0; i < quantidadeContas; i++) {
                        if (numeroConta[i] == numeroConsulta) {
                            cout << "\n------------------------------------------" << endl;
                            cout << "Número da conta: " << numeroConta[i] << endl;
                            cout << "Nome do cliente: " << nomeCliente[i] << endl;
                            cout << "CPF do cliente : " << cpf[i] << endl;
                            cout << "Tipo da conta  : " << (tipoConta[i] == 1 ? "Corrente" : "Poupança") << endl;
                            cout << "Saldo          : R$" << saldo[i] << endl;
                            cout << "Status         : " << (contaAtiva[i] ? "Ativa" : "Inativa") << endl;
                            cout << "------------------------------------------" << endl;
                            contaEncontrada = true;
                            break;
                        }
                    }
                    
                    if (!contaEncontrada) {
                        cout << "\n--> Conta não encontrada!" << endl;
                    }
                }
                break;
            
            case 4:
                cout << ">>> REALIZAR DEPÓSITO <<<" << endl;
                if(quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada!" << endl;
                } else {
                    int numeroDeposito;
                    cout << "Digite o número da conta para depósito: ";
                    cin >> numeroDeposito;
                    
                    bool contaEncontrada = false;
                    for (int i = 0; i < quantidadeContas; i++) {
                        if (numeroConta[i] == numeroDeposito) {
                            if (!contaAtiva[i]) {
                                cout << "\n--> Operação cancelada: Conta inativa!" << endl;
                                contaEncontrada = true;
                                break;
                            }
                            
                            double valorDeposito;
                            cout << "Digite o valor do depósito: R$";
                            cin >> valorDeposito;
                            while (valorDeposito <= 0.0) {
                                cout << "Valor inválido! O depósito deve ser maior que zero: R$";
                                cin >> valorDeposito;
                            }

                            saldo[i] = saldo[i] + valorDeposito;

                            if (quantidadeMovimentacao < MAX_MOVIMENTACOES) {
                                contaMovimentacao[quantidadeMovimentacao] = numeroConta[i];
                                tipoMovimentacao[quantidadeMovimentacao] = 'D';
                                valorMovimentacao[quantidadeMovimentacao] = valorDeposito;
                                quantidadeMovimentacao++;
                            } else {
                                cout << "Aviso: Limite de registros de movimentações atingido!" << endl;
                            }

                            cout << "\n--> Depósito realizado com sucesso!" << endl;
                            cout << "Novo saldo: R$" << saldo[i] << endl;
                            
                            contaEncontrada = true;
                            break;
                        }
                    }
                    
                    if (!contaEncontrada) {
                        cout << "\n--> Conta não encontrada!" << endl;
                    }
                }
                break;

            case 5:
                cout << ">>> REALIZAR SAQUE <<<" << endl;
                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada!" << endl;
                } else {
                    int numeroSaque;
                    cout << "Digite o número da conta para saque: ";
                    cin >> numeroSaque;
                    
                    bool contaEncontrada = false;
                    for (int i = 0; i < quantidadeContas; i++) {
                        if (numeroConta[i] == numeroSaque) {
                            if (!contaAtiva[i]) {
                                cout << "\n--> Operação cancelada: Conta inativa!" << endl;
                                contaEncontrada = true;
                                break;
                            }
                            
                            if (saldo[i] <= 0.0) {
                                cout << "\n--> Operação cancelada: Conta com saldo zerado!" << endl;
                                contaEncontrada = true;
                                break;
                            }

                            double valorSaque;
                            cout << "Digite o valor do saque: R$";
                            cin >> valorSaque;
                            while (valorSaque <= 0.0 || valorSaque > saldo[i]) {
                                if (valorSaque <= 0.0) {
                                    cout << "Valor inválido! O saque deve ser maior que zero: R$";
                                } else {
                                    cout << "Saldo insuficiente! Digite um valor de até R$" << saldo[i] << ": R$";
                                }
                                cin >> valorSaque;
                            }

                            saldo[i] = saldo[i] - valorSaque;

                            if (quantidadeMovimentacao < MAX_MOVIMENTACOES) {
                                contaMovimentacao[quantidadeMovimentacao] = numeroConta[i];
                                tipoMovimentacao[quantidadeMovimentacao] = 'S';
                                valorMovimentacao[quantidadeMovimentacao] = valorSaque;
                                quantidadeMovimentacao++;
                            } else {
                                cout << "Aviso: Limite de registros de movimentações atingido!" << endl;
                            }

                            cout << "\n--> Saque realizado com sucesso!" << endl;
                            cout << "Novo saldo: R$" << saldo[i] << endl;
                            
                            contaEncontrada = true;
                            break;
                        }
                    }
                    
                    if (!contaEncontrada) {
                        cout << "\n--> Conta não encontrada!" << endl;
                    }
                }
                break;
            
            case 6:
                cout << ">>> TRANSFERÊNCIA ENTRE CONTAS <<<" << endl;
                if (quantidadeContas < 2) {
                    cout << "Não há contas suficientes cadastradas para realizar uma transferência!" << endl;
                } else {
                    int numeroOrigem, numeroDestino;
                    cout << "Digite o número da conta de ORIGEM: ";
                    cin >> numeroOrigem;
                    cout << "Digite o número da conta de DESTINO: ";
                    cin >> numeroDestino;
                    
                    if (numeroOrigem == numeroDestino) {
                        cout << "\n--> Erro: As contas de origem e destino não podem ser as mesmas!" << endl;
                        break;
                    }
                    
                    int indiceOrigem = -1, indiceDestino = -1;
                    for (int i = 0; i < quantidadeContas; i++) {
                        if (numeroConta[i] == numeroOrigem) {
                            indiceOrigem = i;
                        }
                        if (numeroConta[i] == numeroDestino) {
                            indiceDestino = i;
                        }
                    }
                    
                    if (indiceOrigem == -1 || indiceDestino == -1) {
                        cout << "\n--> Erro: Uma ou ambas as contas não foram encontradas!" << endl;
                        break;
                    }
                    
                    if (!contaAtiva[indiceOrigem] || !contaAtiva[indiceDestino]) {
                        cout << "\n--> Erro: Uma ou ambas as contas estão inativas!" << endl;
                        break;
                    }
                    
                    double valorTransferencia;
                    cout << "Digite o valor da transferência: R$";
                    cin >> valorTransferencia;
                    while (valorTransferencia <= 0.0 || valorTransferencia > saldo[indiceOrigem]) {
                        if (valorTransferencia <= 0.0) {
                            cout << "Valor inválido! A transferência deve ser maior que zero: R$";
                        } else {
                            cout << "Saldo insuficiente na origem! Digite até R$" << saldo[indiceOrigem] << ": R$";
                        }
                        cin >> valorTransferencia;
                    }

                    saldo[indiceOrigem] -= valorTransferencia;
                    saldo[indiceDestino] += valorTransferencia;

                    if (quantidadeMovimentacao + 2 <= MAX_MOVIMENTACOES) {
                        contaMovimentacao[quantidadeMovimentacao] = numeroConta[indiceOrigem];
                        tipoMovimentacao[quantidadeMovimentacao] = 'S';
                        valorMovimentacao[quantidadeMovimentacao] = valorTransferencia;
                        quantidadeMovimentacao++;

                        contaMovimentacao[quantidadeMovimentacao] = numeroConta[indiceDestino];
                        tipoMovimentacao[quantidadeMovimentacao] = 'D';
                        valorMovimentacao[quantidadeMovimentacao] = valorTransferencia;
                        quantidadeMovimentacao++;
                    } else {
                        cout << "Aviso: Limite de registros atingido, movimentações não gravadas no extrato!" << endl;
                    }

                    cout << "\n--> Transferência realizada com sucesso!" << endl;
                    cout << "Novo saldo da conta de origem (" << numeroConta[indiceOrigem] << "): R$" << saldo[indiceOrigem] << endl;
                }
                break;
            
            case 7:
                cout << ">>> EXTRATO DE CONTA <<<" << endl;
                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada!" << endl;
                } else {
                    int numeroExtrato;
                    cout << "Digite o número da conta para exibir o extrato: ";
                    cin >> numeroExtrato;
                    
                    bool contaEncontrada = false;
                    for (int i = 0; i < quantidadeContas; i++) {
                        if (numeroConta[i] == numeroExtrato) {
                            cout << "\n================ EXTRATO BANCÁRIO ================" << endl;
                            cout << "Conta: " << numeroConta[i] << " | Titular: " << nomeCliente[i] << endl;
                            cout << "Status da conta: " << (contaAtiva[i] ? "Ativa" : "Inativa") << endl;
                            cout << "--------------------------------------------------" << endl;
                            cout << "MOVIMENTAÇÕES:" << endl;

                            bool movimentacaoEncontrada = false;
                            for (int j = 0; j < quantidadeMovimentacao; j++) {
                                if (contaMovimentacao[j] == numeroConta[i]) {
                                    if (tipoMovimentacao[j] == 'D') {
                                        cout << " (+) Depósito    : R$" << valorMovimentacao[j] << endl;
                                    } else {
                                        cout << " (-) Saque/Saída : R$" << valorMovimentacao[j] << endl;
                                    }
                                    movimentacaoEncontrada = true;
                                }
                            }

                            if (!movimentacaoEncontrada) {
                                cout << " (Nenhuma movimentação registrada para esta conta)" << endl;
                            }

                            cout << "--------------------------------------------------" << endl;
                            cout << "SALDO ATUAL: R$" << saldo[i] << endl;
                            cout << "==================================================" << endl;

                            contaEncontrada = true;
                            break;
                        }
                    }
                    
                    if (!contaEncontrada) {
                        cout << "\n--> Conta não encontrada!" << endl;
                    }
                }
                break;
            
            case 8:
                cout << ">>> ALTERAR STATUS DA CONTA <<<" << endl;
                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada!" << endl;
                } else {
                    int numeroStatus;
                    cout << "Digite o número da conta para alterar o status: ";
                    cin >> numeroStatus;
                    
                    bool contaEncontrada = false;
                    for (int i = 0; i < quantidadeContas; i++) {
                        if (numeroConta[i] == numeroStatus) {
                            contaAtiva[i] = !contaAtiva[i];
                            cout << "\n--> Conta " << numeroConta[i] << " agora está " << (contaAtiva[i] ? "ATIVA" : "INATIVA") << "." << endl;
                            contaEncontrada = true;
                            break;
                        }
                    }
                    
                    if (!contaEncontrada) {
                        cout << "\n--> Conta não encontrada!" << endl;
                    }
                }
                break;
            
            case 9:
                cout << "Encerrando o sistema... Obrigado por utilizar o Banco Guardino!" << endl;
                break;
            
            default:
                cout << "Opção inválida!" << endl;
        }
    }while (opcao != 9);
    
    return 0;
}