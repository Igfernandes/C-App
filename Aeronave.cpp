#include <iostream>
#include <locale.h>
#include <string.h>

using namespace std;

//FUNCTIONS
string dates(string data, string references);
string codCompanhia(string check, string references);
string nomeCompanhia(string check,  string references);

//STRUCTS
struct Passageiro{
	string 	nome;
	int 	CPF;
	int 	cod_voo;
	float	preco_passagem;
	int		cod_cidade_origem;
	string 	data_partida;
	int		Cod_cidade_dest;
	string 	data_chegada;
	string	cod_companhia;
	string	nome_companhia;
	int		cod_aeronave;
};


struct Companhia{
	float	ganho_total;
	string 	cod_companhia;
	string	nome_companhia;
	string	mes_ano;
};



// MAIN
int main(){
	
	setlocale(LC_ALL, "portuguese");
	
	bool exit = false; int z = 0; char resp;
	Companhia caixa; caixa.ganho_total = 0;	string result_dates;
	Passageiro registro[1000];	
	

	cout<<"| REGISTRO DO PASSAGEIRO | \n\n";
	
	while(exit == false){
		
		
		cout<<"\n(*) - Passageiro "<<z + 1<<"°: \n";
		cout<<"(*) - Nome: ";cin>>registro[z].nome;
		cout<<"(*) - CPF: ";cin>>registro[z].CPF;
		cout<<"(*) - Código de Vôo: ";cin>>registro[z].cod_voo;
		cout<<"(*) - Preço da passagem: ";cin>>registro[z].preco_passagem;
		cout<<"(*) - Código da Cidade Origem: ";cin>>registro[z].cod_cidade_origem;
		cout<<"(*) - Data e Horário de Partida( 00/00/00 00:00): ";cin>>registro[z].data_partida;
		cout<<"(*) - Código da Cidade Destino: ";cin>>registro[z].Cod_cidade_dest;
		cout<<"(*) - Data e Horário de Chegada( 00/00/00 00:00): ";cin>>registro[z].data_chegada;
		cout<<"(*) - Código da companhia(00000): ";cin>>registro[z].cod_companhia;
		cout<<"(*) - Nome da Companhia: ";cin>>registro[z].nome_companhia;
		cout<<"(*) - Código da Aeronave: ";cin>>registro[z].cod_aeronave;
		
		Estrutura MAIN
		caixa.ganho_total += registro[z].preco_passagem;
		cout<<"\n\n\n($) - Ganho Total: "<<caixa.ganho_total;
		caixa.cod_companhia += codCompanhia(registro[z].cod_companhia, caixa.cod_companhia);
		cout<<"\n($) - Código da Companhia: "<<caixa.cod_companhia;
		caixa.nome_companhia += nomeCompanhia(registro[z].nome_companhia, caixa.nome_companhia);
		cout<<"\n($) - Nome das Companhias: "<<caixa.nome_companhia;
		
		caixa.mes_ano += dates(registro[z].data_partida, caixa.mes_ano);
		cout<<"\n($) - Mês/Ano de Vôos: "<<caixa.mes_ano;

		
				
		cout<<"\n\n (@) - DESEJA ADICIONAR OUTRO PASSAGEIRO? S/N \n -("; cin>>resp;
		if(resp == 's'){
			resp = 'S';
		}
		switch(resp){
			case 'S':
				z++;
				break;
			default:
				exit = true;
				break;
		}
	}
	
}


string dates(string data, string references){
	int nu = 7; string mes_ano, check_date; 
	
	for(int x = 3; x < 8; x++){
		mes_ano += data[x]; 
	}

	mes_ano = " - "+mes_ano;
	for(int y = 0; y <= references.length(); y++){
						
		check_date += references[y];
		if(y == nu){
			cout<<check_date;
			if(mes_ano == check_date){
				mes_ano = "";
				cout<<mes_ano;
			}
			nu *= nu;
			check_date= "";
		}
	}
	

	return mes_ano;
}


string nomeCompanhia(string check,  string references){
	string 	check_cod;
	
	for(int y = 0; y <= references.length(); y++){
						
		check_cod += references[y];
		
		if(references[y] != '-'){
			if(check == references){
				check = "";
			}
			check_cod = "";
		}else{
			if(references[y] == '-'){
				
				if(check == check_cod){
					check = "";
				}else{
					
				}
				check_cod = "";
			}
		}
		
	}
	if(references == ""){
		check = check;
	}else if(references != "" && check != ""){
		check = "-"+check;
	}
	
	return check;
	
}

string codCompanhia(string check, string references){
	string 	check_cod; int nu = 6;
	
	check = " - "+check;
	
	for(int y = 0; y <= references.length(); y++){
						
		check_cod += references[y];
	
		if(y == nu){
			
			if(check == check_cod){
				check = "";
			}
			nu *= nu;
			check_cod = "";
		}
	}
	
	return check;
}








