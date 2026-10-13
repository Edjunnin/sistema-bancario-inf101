#include <iostream>
#include <string>
using namespace std;

int main()
{
    int tipoConta[5] = {0}, numeroConta[5] = {0}, opcao = 0, totalContas = 0, numBusca = 0, indiceEncontrado = -1;
    string nomeCliente[5], cpf[5];
    double saldo[5] = {0.0};
    bool contaAtiva[5] = {false}, numeroRepetido = false;
    
    //Nessa parte das declarações das variáveis eu coloquei uma do lado da outra separando por tipos.
    //Para conseguir cadastrar até 5 contas, eu transformei as variáveis da conta em vetores de 5 posições.
    //Tirei o "contaCadastrada" e criei o "totalContas", faz sentido já que agora eu preciso saber quantas contas já existem no sistema (de 0 até 5).
    //Defini os valores dos vetores e variáveis pra zero e false para evitar lixo de memória e garantir que tudo esteja zerado antes de qualquer coisa.
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
                
                if (totalContas >= 5) {
                    cout<< "Limite máximo de 5 contas atingido! Não é possível cadastrar mais contas.\n" <<endl;
                }
                //Esse if é para travar o cadastro caso o usuário já tenha cadastrado as 5 contas possíveis.
                else {
                    cout<< "Digite o número que você quer que corresponda a essa conta: ";
                    cin>> numeroConta[totalContas];
                    
                    do {
                        numeroRepetido = false;
                        while (numeroConta[totalContas] <= 0) {
                            cout<< "Número Inválido! O número da conta tem que ser maior que zero: ";
                            cin >> numeroConta[totalContas];
                        }
                        //Esse while é para garantir que o número da conta seja maior que zero.
                        
                        for (int i = 0; i < totalContas; i++) {
                            if (numeroConta[i] == numeroConta[totalContas]) {
                                numeroRepetido = true;
                            }
                        }
                        //Esse for passa pelas contas que já existem pra ver se alguém já pegou esse número.
                        
                        if (numeroRepetido == true) {
                            cout<< "Esse número de conta já existe! Digite outro número: ";
                            cin >> numeroConta[totalContas];
                        }
                    } while (numeroRepetido == true);
                    
                    cin.ignore();
                    //O cin ignore pra limpar o buffer pra não dar aquele bug da quebra de linha do enter.
                    
                    cout<< "Digite o nome do titular da conta: ";
                    getline(cin, nomeCliente[totalContas]);
                    
                    cout<< "Digite o CPF do titular da conta: ";
                    getline(cin, cpf[totalContas]);
                    while (cpf[totalContas].length() != 11){
                        cout<< "CPF inválido! Um cpf deve conter exatamente 11 dígitos: ";
                        getline(cin, cpf[totalContas]);
                    }
                    //Essa validação foi algo que eu mesmo adicionei, já que não faria muito sentido um cpf não ter 11 números.
                    
                    cout<< "Escolha o tipo de conta.\n [1] Conta corrente \n [2] Conta poupança \n Digite o tipo da conta: ";
                    cin>> tipoConta[totalContas];
                    while (tipoConta[totalContas] != 1 && tipoConta[totalContas] != 2) {
                        cout<< "Opção Inválida! Digite 1 para Conta corrente e 2 para conta poupança: ";
                        cin>> tipoConta[totalContas];
                    }
                    // Esse while é para que o usuário possa escolher somente as duas opções possíveis.
                    
                    cout<< "Digite o saldo inicial da conta: ";
                    cin>> saldo[totalContas];
                    while (saldo[totalContas] < 0.0) {
                        cout<< "Saldo Inválido! O saldo não pode ser negativo: ";
                        cin>> saldo[totalContas];
                    }
                    //O while aqui é para garantir que o saldo não seja negativo.
                    
                    contaAtiva[totalContas] = true;
                    totalContas++;
                    //Aqui deixa a conta atual ativa e soma 1 no totalContas para a próxima conta cair na próxima posição do vetor.
                    
                    cout<< "Conta cadastrada com sucesso!\n"<< endl;
                }
                break;
                
            case 2:
                cout<< "Você entrou na consulta de contas.\n" <<endl;
                cout<< "------------CONSULTA DE CONTAS------------\n" <<endl;
                if (totalContas == 0) { // se totalContas for 0, quer dizer que nenhuma conta foi cadastrada no case 1 ainda.
                    cout<< "Nenhuma conta foi criada ainda.\n" <<endl;
                }// esse if é para caso o usuário tentar consultar uma conta sem ter nenhuma cadastrada.
                else {
                    cout<< "Digite o número da conta que deseja consultar: ";
                    cin>> numBusca;
                    indiceEncontrado = -1;
                    //Coloquei -1 porque as posições do vetor vão de 0 a 4. Se continuar -1 depois do for, é porque não achou a conta.
                    
                    for (int i = 0; i < totalContas; i++) {
                        if (numeroConta[i] == numBusca) {
                            indiceEncontrado = i;
                        }
                    }
                    //Esse for procura em qual posição do vetor está o número da conta que o usuário digitou.
                    
                    if (indiceEncontrado == -1) {
                        cout<< "Conta não encontrada!\n" << endl;
                    }
                    else {
                        cout<< "Numero da conta:  " << numeroConta[indiceEncontrado] << endl;
                        cout<< "Nome do titular:  " << nomeCliente[indiceEncontrado] << endl;
                        cout<< "CPF:  " << cpf[indiceEncontrado] << endl;
                    
                        if (tipoConta[indiceEncontrado] == 1) {
                            cout<< "Tipo da conta: Corrente" << endl;
                        }
                        else {
                            cout<< "Tipo da conta: Poupança" << endl;
                        }// if e else pra verificar o tipo de conta.
                        cout<< "Saldo: R$" << saldo[indiceEncontrado] << endl;
                    
                        if (contaAtiva[indiceEncontrado] == true) {
                            cout<< "Conta Ativa.\n" << endl;
                        }
                        else {
                            cout<< "Conta Inativa.\n" << endl;
                        } // if e else aqui utilizado para verificar se é uma conta ativa ou inativa.
                    }
                }
                break;
                
            case 3:
                cout<< "Você escolheu verificar saldo.\n" <<endl;
                cout<< "------------VERIFICAÇÃO DE SALDO------------\n" <<endl;
                
                if (totalContas == 0) {
                    cout<< "Não existe conta cadastrada para verificar saldo.\n" << endl;
                }
                else {
                    cout<< "Digite o número da conta para verificar o saldo: ";
                    cin>> numBusca;
                    indiceEncontrado = -1;
                    
                    for (int i = 0; i < totalContas; i++) {
                        if (numeroConta[i] == numBusca) {
                            indiceEncontrado = i;
                        }
                    }
                    
                    if (indiceEncontrado == -1) {
                        cout<< "Conta não encontrada!\n" << endl;
                    }
                    else if (!contaAtiva[indiceEncontrado]) { //aqui o !contaAtiva seria como um contaAtiva == false.
                        cout<< "Conta inativa. Não será possível verificar saldo.\n" << endl;
                    }
                    else {
                        cout<< "Saldo: R$" << saldo[indiceEncontrado] << "\n" << endl;
                    }
                }
                break;
                
            case 4:
                cout<< "Você escolheu alterar tipo da conta.\n" <<endl;
                cout<< "------------ALTERAÇÃO DE TIPO DE CONTA------------\n" <<endl;
                
                if (totalContas == 0) {
                    cout<< "Não existe conta cadastrada para alterar o tipo de conta.\n" << endl;
                }
                else {
                    cout<< "Digite o número da conta para alterar o tipo: ";
                    cin>> numBusca;
                    indiceEncontrado = -1;
                    
                    for (int i = 0; i < totalContas; i++) {
                        if (numeroConta[i] == numBusca) {
                            indiceEncontrado = i;
                        }
                    }
                    
                    if (indiceEncontrado == -1) {
                        cout<< "Conta não encontrada!\n" << endl;
                    }
                    else if (!contaAtiva[indiceEncontrado]) {
                        cout<< "Conta inativa. Não será possível alterar o tipo de conta.\n" << endl;
                    }
                    else {
                        if (tipoConta[indiceEncontrado] == 1) {
                            cout<< "Tipo atual da conta: Corrente" << endl;
                        }
                        else {
                            cout<< "Tipo atual da conta: Poupança" << endl;
                        }
                        cout<< "Escolha seu novo tipo de conta.\n [1] Conta corrente \n [2] Conta poupança \n Digite o tipo da conta: ";
                        cin>> tipoConta[indiceEncontrado];
                        while (tipoConta[indiceEncontrado] != 1 && tipoConta[indiceEncontrado] != 2) {
                            cout<< "Opção Inválida! Digite 1 para Conta corrente e 2 para conta poupança: ";
                            cin>> tipoConta[indiceEncontrado]; 
                        }
                        
                        cout<< "Tipo de conta alterado com sucesso!\n" << endl;
                    }
                } // nesse case 4 eu copiei e colei a parte da escolha do tipo de conta do case 1 e a busca do case 2.
                break;
                
            case 5:
                cout<< "Você escolheu ativar ou desativar uma conta.\n" <<endl;
                cout<< "------------ALTERAÇÃO DE STATUS DA CONTA------------\n" <<endl;
                
                if (totalContas == 0) {
                    cout<< "Não existe conta cadastrada para alterar o status dela.\n" << endl;
                }
                else {
                    cout<< "Digite o número da conta para ativar ou desativar: ";
                    cin>> numBusca;
                    indiceEncontrado = -1;
                    
                    for (int i = 0; i < totalContas; i++) {
                        if (numeroConta[i] == numBusca) {
                            indiceEncontrado = i;
                        }
                    }
                    
                    if (indiceEncontrado == -1) {
                        cout<< "Conta não encontrada!\n" << endl;
                    }
                    else {
                        if (contaAtiva[indiceEncontrado] == true) { // aqui decidi usar o == true invés de somente "contaAtiva". É pra variar um pouco o uso mesmo.
                            contaAtiva[indiceEncontrado] = false; // pra alterar a conta pra false
                            cout<< "Sua conta foi desativada com sucesso!\n" << endl;
                        }
                        else {
                            contaAtiva[indiceEncontrado] = true; // pra alterar pra true
                            cout<< "Sua conta foi ativada com sucesso!\n" << endl;
                        }
                    }
                }
                break;
                
            case 6:
                cout<< "Você escolheu sair.\n" <<endl;
                break;
                
            default:
                cout<< "Opção Inválida!\n" <<endl;
        }
    }while(opcao != 6); // esse é o do-while para o programa sempre voltar pro menu até que o usuário digite 6 para sair do sistema.

    return 0;
}
