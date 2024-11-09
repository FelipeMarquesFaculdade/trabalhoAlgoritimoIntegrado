#include <iostream>
#include <string>

using namespace std;

const int FMS_quantidadeMaximaDeProdutos = 3;

int FMS_seletorMenu; // opção selecionada no menu
int FMS_controleQuantidadeCadastrados = 0; //variavel para controlar quantos produtos foram cadastrados

string FMS_nomeProduto[FMS_quantidadeMaximaDeProdutos]; // vetor de nomes de produtos
float FMS_precoProduto[FMS_quantidadeMaximaDeProdutos]; // vetor de preço de produtos
float FMS_quantidadeProdutoEstoque[FMS_quantidadeMaximaDeProdutos]; // vetor de quantidade de produtos em estoque
string FMS_unidadeMedidaProduto[FMS_quantidadeMaximaDeProdutos]; //tipos Unidade e Mililitros

int finalizar; //declaração da variavel para finalizar venda.

void FMS_menu(); // declaração da função que apresenta o MENU
void FMS_cadastrarProdutos(); // declaração da função que cadastro os produtos
void FMS_listarProdutos(); // declaração da função que lista os produtos
void FMS_compraDeProdutos(); // declaração da função que compra os produtos
void FMS_vendaDeProdutos(); // declaração da função que vende os produtos
void FMS_editarProdutos(); // declaração da função que edita os produtos
void FMS_excluiProdutos(); // declaração da função que excluir os produtos

//---------------------------------------------------------------------------------------------------

string FMS_voltaMenu; //variável auxiliar para esperar o usuário pressionar enter para voltar ao menu
void FMS_operacaoSucesso(){ //função para informar que a operação foi realizada comsucesso
 cout<<"Operação Realizada com Sucesso\n\n";
}
void FMS_limparTela(){ //função para limpar o console
 system("clear");
}
void FMS_limpaTelaTeclando(){ //função para limpar o console assim que o usuario teclar ENTER
 cout << "pressione enter para voltar ao MENU...";
 
 getline(cin,FMS_voltaMenu); // getline permite ler mais de uma palavra na mesmavariável
 getline(cin,FMS_voltaMenu); // 2x getline para contornar o problema de passar pela variável sem digital nada
 
 FMS_limparTela(); //chamando a função de limpar o console
}

//---------------------------------------------------------------------------------------------------

void FMS_compraDeProdutos(){
    
 int FMS_codigoProdutoComprado;
 float FMS_quantidadeProdutoComprado;
 cout<<"############## Compra de Produto #################\n";
 
 cout<<"Informe o codigo do Produto: ";
 cin>>FMS_codigoProdutoComprado;
 
 while(FMS_codigoProdutoComprado < 0 || FMS_codigoProdutoComprado > FMS_controleQuantidadeCadastrados){
 cout<<"Codigo inexistente, informe um codigo valido";
 cout<<"Informe o codigo do Produto: ";
 cin>>FMS_codigoProdutoComprado;
 }
 
 cout<<"Qual a quantidade que quer comprar do Produto "<<FMS_nomeProduto[FMS_codigoProdutoComprado]<<": ";
 cin>>FMS_quantidadeProdutoComprado;
 FMS_quantidadeProdutoEstoque[FMS_codigoProdutoComprado] = FMS_quantidadeProdutoEstoque[FMS_codigoProdutoComprado] + FMS_quantidadeProdutoComprado;
 
 cout<<"O produto "<<FMS_nomeProduto[FMS_codigoProdutoComprado]<<" agora tem "<<FMS_quantidadeProdutoEstoque[FMS_codigoProdutoComprado]<<FMS_unidadeMedidaProduto[FMS_codigoProdutoComprado]<<" em estoque\n\n";
 
 FMS_limpaTelaTeclando();
 
}

//---------------------------------------------------------------------------------------------------

void FMS_vendaDeProdutos(){
    
 cout<<"############## Venda de Produto #################\n";   
 finalizar =0;   
 int FMS_codigoProdutoVendido;
 float FMS_quantidadeProdutoVendido;
 
 bool continuarVenda = true;
 while(continuarVenda == true){

 cout<<"Informe o codigo do Produto que deseja vender: ";
 cin>>FMS_codigoProdutoVendido;
 
 while(FMS_codigoProdutoVendido < 0 || FMS_codigoProdutoVendido > FMS_controleQuantidadeCadastrados){
 cout<<"Codigo inexistente, informe um codigo valido";
 cout<<"Informe o codigo do Produto: ";
 cin>>FMS_codigoProdutoVendido;
 }
 
 int x = FMS_quantidadeProdutoEstoque[FMS_codigoProdutoVendido];
 
 while(x == 0 ){
 x = FMS_quantidadeProdutoEstoque[FMS_codigoProdutoVendido];
 cout<<"\nVocê não tem este produto em seu estoque, portanto não é possivel realizar está venda.\n";
 string simOuNao = "s";
 
 do{
 cout<<"\nDeseja realizar a venda de outro produto?\n";
 cout<<"s = SIM ou n = Não\n";
 cin>>simOuNao;
 if(simOuNao != "s" && simOuNao != "n" && simOuNao != "S" && simOuNao !="N"){
 cout<<"Responda somente com s ou n\n";
 }else if(simOuNao == "n" || simOuNao == "N"){//Forço a saida do loop.
 continuarVenda = false;
 finalizar =1;
 x = 1;
 }else{
 FMS_limparTela(); 
 cout<<"############## Venda de Produto #################\n";
 cout<<"Informe o codigo do Produto que deseja vender: ";
 cin>>FMS_codigoProdutoVendido;
 }
 }while(simOuNao != "s" && simOuNao != "n" && simOuNao != "S" && simOuNao !="N");
 }
 continuarVenda = false;
 }
 
 if(finalizar==0){
 cout<<"Qual a quantidade que quer vender deste Produto "<<FMS_nomeProduto[FMS_codigoProdutoVendido]<<": ";
 cin>>FMS_quantidadeProdutoVendido;
 
 while((FMS_quantidadeProdutoEstoque[FMS_codigoProdutoVendido]-FMS_quantidadeProdutoVendido) < 0 || FMS_quantidadeProdutoVendido > FMS_quantidadeProdutoEstoque[FMS_codigoProdutoVendido]){
 cout<<"\nQuantidade igua a 0 ou maior que o total em estoque, informe uma quantidade valida.\n";
 cout<<"Qual a quantidade que quer vender deste Produto "<<FMS_nomeProduto[FMS_codigoProdutoVendido]<<": ";
 cin>>FMS_quantidadeProdutoVendido;
 }
 
 cout<<"\nA venda de "<<FMS_quantidadeProdutoVendido<<" do produto "<<FMS_nomeProduto[FMS_codigoProdutoVendido]<<" foi realizada.\n";
 
 FMS_quantidadeProdutoEstoque[FMS_codigoProdutoVendido] = FMS_quantidadeProdutoEstoque[FMS_codigoProdutoVendido] - FMS_quantidadeProdutoVendido;
 
 cout<<"O produto "<<FMS_nomeProduto[FMS_codigoProdutoVendido]<<" agora tem "<<FMS_quantidadeProdutoEstoque[FMS_codigoProdutoVendido]<<FMS_unidadeMedidaProduto[FMS_codigoProdutoVendido]<<" em estoque\n\n";
 }
 
 FMS_limpaTelaTeclando();
}

//---------------------------------------------------------------------------------------------------

void FMS_editarProdutos(){
 
 int codigodoProduto;
    
 bool continuarCadastrando = true;
 cout<<"############## Editor de Produto #################\n";
 cout << "Código do produto a ser editado: ";
 cin>>codigodoProduto;
 
 while(codigodoProduto < 0 || codigodoProduto > FMS_controleQuantidadeCadastrados){
 cout<<"Codigo inexistente, informe um codigo valido";
 cout<<"Informe o codigo do Produto: ";
 cin>>codigodoProduto;
 }
 
 cout << "Nome do produto: ";
 getline(cin,FMS_nomeProduto[codigodoProduto]);
 getline(cin,FMS_nomeProduto[codigodoProduto]);
 
 cout << "Preço do produto "<<FMS_nomeProduto[codigodoProduto]<<": ";
 cin >> FMS_precoProduto[codigodoProduto];
 int FMS_auxiliarEscolhaUnidadeMedida=0;
 do{
 cout<<"Qual a unidade de Medida do Produto?\n";
 cout<<"1 - ML ou 2 - Unidade\n";
 cin>> FMS_auxiliarEscolhaUnidadeMedida;
 if(FMS_auxiliarEscolhaUnidadeMedida == 1) FMS_unidadeMedidaProduto[codigodoProduto] = " Mililitros";
 else if(FMS_auxiliarEscolhaUnidadeMedida == 2) FMS_unidadeMedidaProduto[codigodoProduto] = " Unidades";
 else cout<<"Somente deve ser inserido valores 1 e 2, sendo 1 - ML ou 2 - Unidade\n";
 }while(FMS_auxiliarEscolhaUnidadeMedida < 1 || FMS_auxiliarEscolhaUnidadeMedida > 2);

 FMS_operacaoSucesso();
 
 string simOuNao = "s";
 
 do{
 cout<<"Deseja Continuar editando?\n";
 cout<<"s = SIM ou n = Não\n";
 cin>>simOuNao;
 
 if(simOuNao != "s" && simOuNao != "n" && simOuNao != "S" && simOuNao !="N"){
 cout<<"Responda somente com s ou n\n";
 }else if(simOuNao == "n" || simOuNao == "N") continuarCadastrando = false;
 else{
 FMS_limparTela(); 
 }
 }while(simOuNao != "s" && simOuNao != "n" && simOuNao != "S" && simOuNao !="N");
 
 FMS_limpaTelaTeclando();
}

//---------------------------------------------------------------------------------------------------

void FMS_excluiProdutos(){
    
 int codigodoProduto;
 string produtoExcluido;
 
 bool continuarCadastrando = true;
 while(continuarCadastrando == true){
 cout<<"############## Exclusão de Produto #################\n";
 cout << "Código do produto a ser Excluido: ";
 cin>>codigodoProduto;
 
 if(FMS_controleQuantidadeCadastrados!=0){
 
 while(codigodoProduto < 0 || codigodoProduto > FMS_controleQuantidadeCadastrados){
 cout<<"Codigo inexistente, informe um codigo valido";
 cout<<"Informe o codigo do Produto: ";
 cin>>codigodoProduto;
 }
 
 produtoExcluido = FMS_nomeProduto[codigodoProduto];
 if(codigodoProduto<FMS_controleQuantidadeCadastrados){
 if (FMS_quantidadeProdutoEstoque[codigodoProduto] > 0){
    cout<<"O produto "<<FMS_nomeProduto[codigodoProduto]<<" tem "<<FMS_quantidadeProdutoEstoque[codigodoProduto]<<" em estoque, não podemos excluir ele.\n\n";
 }else{
 for(codigodoProduto;codigodoProduto<FMS_quantidadeMaximaDeProdutos;codigodoProduto++){
 if(codigodoProduto!=FMS_quantidadeMaximaDeProdutos-1){
 FMS_nomeProduto[codigodoProduto]=FMS_nomeProduto[codigodoProduto+1];
 FMS_precoProduto[codigodoProduto]=FMS_precoProduto[codigodoProduto+1];
 FMS_unidadeMedidaProduto[codigodoProduto]=FMS_unidadeMedidaProduto[codigodoProduto+1];
 FMS_controleQuantidadeCadastrados=FMS_controleQuantidadeCadastrados-1;
 }else{
 FMS_nomeProduto[codigodoProduto]="";
 FMS_precoProduto[codigodoProduto]=0;
 FMS_unidadeMedidaProduto[codigodoProduto]="";
 FMS_controleQuantidadeCadastrados=FMS_controleQuantidadeCadastrados-1;
 }}
 cout<<"Produto "<<produtoExcluido<<" excluido com sucesso!\n\n";
 }}else{
    cout<<"Produto inexistente.\n\n";
 }}else{
    cout<<"Nenhum Produto Cadastrado.\n\n";
 }
 
 string simOuNao = "s";
 
 do{
 cout<<"Deseja excluir outro produto?\n";
 cout<<"s = SIM ou n = Não\n";
 cin>>simOuNao;
 
 if(simOuNao != "s" && simOuNao != "n" && simOuNao != "S" && simOuNao !="N"){
 cout<<"Responda somente com s ou n\n";
 }else if(simOuNao == "n" || simOuNao == "N") continuarCadastrando = false;
 else{
 FMS_limparTela(); 
 }
 }while(simOuNao != "s" && simOuNao != "n" && simOuNao != "S" && simOuNao !="N");
 }   

 FMS_limpaTelaTeclando();
}

//---------------------------------------------------------------------------------------------------

void FMS_cadastrarProdutos(){
 bool continuarCadastrando = true;
 while(continuarCadastrando == true){
 cout<<"############## Cadastro de Produto #################\n";
 
 if (FMS_controleQuantidadeCadastrados < FMS_quantidadeMaximaDeProdutos){ //verifica se não chegou no nivel maximo de cadastros
 cout << "Nome do produto: ";
 getline(cin,FMS_nomeProduto[FMS_controleQuantidadeCadastrados]);
 getline(cin,FMS_nomeProduto[FMS_controleQuantidadeCadastrados]);
 FMS_quantidadeProdutoEstoque[FMS_controleQuantidadeCadastrados] = 0;
 cout << "Preço do produto "<<FMS_nomeProduto[FMS_controleQuantidadeCadastrados]<<": ";
 cin >> FMS_precoProduto[FMS_controleQuantidadeCadastrados];
 int FMS_auxiliarEscolhaUnidadeMedida=0;
 do{
 cout<<"Qual a unidade de Medida do Produto?\n";
 cout<<"1 - ML ou 2 - Unidade\n";
 cin>> FMS_auxiliarEscolhaUnidadeMedida;
 if(FMS_auxiliarEscolhaUnidadeMedida == 1) FMS_unidadeMedidaProduto[FMS_controleQuantidadeCadastrados] = " Mililitros";
 else if(FMS_auxiliarEscolhaUnidadeMedida == 2) FMS_unidadeMedidaProduto[FMS_controleQuantidadeCadastrados] = " Unidades";
 else cout<<"Somente deve ser inserido valores 1 e 2, sendo 1 - ML ou 2 - Unidade\n";
 }while(FMS_auxiliarEscolhaUnidadeMedida < 1 || FMS_auxiliarEscolhaUnidadeMedida > 2);

 FMS_controleQuantidadeCadastrados++;
 FMS_operacaoSucesso();
 }else{
 cout << "Quantidade máxima de produtos atingida";
 }
 
 string simOuNao = "s";
 
 do{
 cout<<"Deseja Continuar Cadastrando?\n";
 cout<<"s = SIM ou n = Não\n";
 cin>>simOuNao;
 
 if(simOuNao != "s" && simOuNao != "n" && simOuNao != "S" && simOuNao !="N"){
 cout<<"Responda somente com s ou n\n";
 }else if(simOuNao == "n" || simOuNao == "N") continuarCadastrando = false;
 else{
 FMS_limparTela(); 
 }
 }while(simOuNao != "s" && simOuNao != "n" && simOuNao != "S" && simOuNao !="N");
 }
 
 FMS_limpaTelaTeclando();
 
}
//---------------------------------------------------------------------------------------------------

void FMS_listarProdutos(){
 cout << "################ Lista de Produtos ################"<< endl;
 for (int i=0; i < FMS_controleQuantidadeCadastrados; i++) {
 cout<< FMS_quantidadeProdutoEstoque[i] << FMS_unidadeMedidaProduto[i] << " do Produto " <<FMS_nomeProduto[i] << "\nCom o Valor de " << FMS_precoProduto[i] << "RS em estoque, ";
 cout<<"Codigo: "<<i<<endl;
 cout<<"-------------------------------------------------------------------------\n\n";
 }
 
 FMS_limpaTelaTeclando();
}
//---------------------------------------------------------------------------------------------------

void FMS_menu(){
 bool fechar = false;
 
 while(fechar == false){
 
 cout << "*************************************************"<< endl;
 cout << "**************** Defensivos NSLO ****************"<< endl;
 cout << "*************************************************"<< endl;
 cout << "1 - Realizar Cadastro de Produtos"                << endl;
 cout << "2 - Realizar a Alteraração de um Produto"         << endl;
 cout << "3 - Realizar a Deleção de um Produto"             << endl;
 cout << "4 - Realizar a Compra de um Produto"              << endl;
 cout << "5 - Realizar a Venda de um Produto"               << endl;
 cout << "6 - Lista Todos os Produtos"                      << endl;
 cout << "0 - Sair do Sistema"                              << endl;
 cout << "Opção do Menu: ";
 cin >> FMS_seletorMenu;
 
 if (FMS_seletorMenu == 1){
 FMS_limparTela();
 FMS_cadastrarProdutos();
 }else if (FMS_seletorMenu == 2){
 FMS_limparTela();
 FMS_editarProdutos();
 }else if (FMS_seletorMenu == 3){
 FMS_limparTela();
 FMS_excluiProdutos();
 }else if (FMS_seletorMenu == 4){
 FMS_limparTela();
 FMS_compraDeProdutos();
 }else if (FMS_seletorMenu == 5){
 FMS_limparTela();
 FMS_vendaDeProdutos();
 }else if (FMS_seletorMenu == 6){
 FMS_limparTela();
 FMS_listarProdutos();
 }else if(FMS_seletorMenu == 0){
 fechar = true;
 }else{
 system("clear");
 cout << "Opção inválida " << endl;
 }
 }
}

int main()
{
 FMS_menu();
 return 0;
}