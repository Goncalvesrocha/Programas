CREATE DATABASE SistemaGestaoComercial;

USE SistemaGestaoComercial;

CREATE TABLE regiao(

      reg_id int auto_increment,
      reg_nome varchar(20),

	  PRIMARY KEY(reg_id)

);


CREATE TABLE tipo(

	tip_id int auto_increment,
	tip_nome varchar(20),

	PRIMARY KEY (tip_id)

);


CREATE TABLE categoria(

	cat_id int auto_increment,
	cat_nome varchar(50),
	cat_comissao DECIMAL(4, 1),

	PRIMARY KEY (cat_id)

);


CREATE table prazo(
	
	pra_id int auto_increment,
	pra_tempoDias int,
	pra_periodo int,
	pra_limite int,

	PRIMARY KEY(pra_id)
);


CREATE TABLE formapagmto(
	
	for_id int auto_increment,
	for_nome varchar(40),

	PRIMARY KEY (for_id)

);


CREATE TABLE cliente(
     
     cli_cnpj varchar(20),
     cli_nome varchar(40),
     cli_inscricaoEstadual int,

     cli_estado varchar(20),
     cli_cidade varchar(20),
     cli_bairro varchar(20),
     cli_cep varchar(10),
     cli_rua varchar(20), 
     cli_numero int,
     
  
     cli_telefone varchar(12),
     cli_email varchar(40),
	 reg_id int,
	 tip_id int, 
     ven_cpf varchar(12),
	 PRIMARY KEY (cli_cnpj),

     FOREIGN KEY (reg_id) REFERENCES regiao(reg_id),
     FOREIGN KEY (tip_id) REFERENCES tipo(tip_id),
     FOREIGN KEY (ven_cpf) REFERENCES vendedor(ven_cpf)

);


CREATE TABLE vendedor(
     
     ven_cpf varchar(12),
     ven_nome varchar(40),
	 reg_id int,	
	 PRIMARY KEY (ven_cpf),

     FOREIGN KEY (reg_id)   REFERENCES regiao(reg_id)
     
);



CREATE TABLE fabricante(
	
	fab_cnpj varchar(20),
	fab_nome varchar(40),
	reg_id varchar(12),
    PRIMARY KEY (fab_cnpj),

	FOREIGN KEY (reg_id) REFERENCES regiao(reg_id)
);



CREATE TABLE produto(
 	
	pro_id int auto_increment,
    pro_nome varchar(40),
	pro_codBarras int,
    pro_preco199 decimal(8, 2),
    pro_precoMercado decimal (8, 2),
	pro_estoque int,
	pro_descricao varchar(200),
	cat_id int, 
    fab_cnpj varchar(20),
	PRIMARY KEY (pro_id),

	FOREIGN KEY (cat_id) REFERENCES categoria(cat_id),
  	FOREIGN KEY (fab_cnpj) REFERENCES fabricante(fab_cnpj)      
);


CREATE TABLE pedido(
	
	ped_id int auto_increment,
	ped_data DATE,
	ped_valorTotal DECIMAL(8,2),


	PRIMARY KEY (ped_id),

	FOREIGN KEY (cli_cnpj) REFERENCES cliente(cli_cnpj),
	FOREIGN KEY (ven_cpf)  REFERENCES vendedor(ven_cpf), 
	FOREIGN KEY (for_id)   REFERENCES formapagmto(for_id),
	FOREIGN KEY (pra_id)   REFERENCES prazo(pra_id)

);

CREATE TABLE itempedido(
 	
	itp_id int auto_increment,
	itp_quantidade int,
	itp_valorUnitario decimal(8, 2),
	ped_id int,
    pro_id int,
    
	PRIMARY KEY (itp_id),
	
    FOREIGN KEY (ped_id) REFERENCES pedido(ped_id),  
	FOREIGN KEY (pro_id) REFERENCES produto(pro_id)  
);


